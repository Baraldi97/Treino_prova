#include <stdlib.h>
#include <unistd.h>

int ft_count_word(char *str)
{
	int i = 0;
	int count = 0; 	
	while(str[i] != '\0')
	{
		while(str[i] == ' ' || str[i] == '\t' || str[i] ==  '\n')
			i++;
		if (str[i] != '\0') 
			count++;
		while(str[i] != ' ' && str[i] != '\0' && str[i] != '\n' && str[i] != '\t')
			i++;
	}
	return (count);
}

void ft_copy_word(char *tab, char *str, int start, int end)
{
	int i = 0;
	while (start < end)
		tab[i++] = str[start++];
	tab[i] = '\0';
}

int ft_find_next_word(char *str, int *start, int *end)
{
	int i = *end;
	while(str[i] != '\0' && (str[i] == ' ' || str[i] ==  '\t' || str[i] == '\n'))
		i++;
	*start = i;
	while(str[i] != ' ' && str[i] != '\0' && str[i] != '\n' && str[i] != '\t')
		i++;
	*end = i;
	return (*start < *end);
}

int ft_fill_word (char **tab, char *str)
{
	int i = 0;
	int word = 0;
	int start = 0;
	int end = 0;

	while (ft_find_next_word(str, &start, &end))
	{
		tab[word] = malloc ((end - start + 1) * (sizeof(char)));
		if (tab[word] ==  NULL)
		{
			i = 0;
			while (i < word)
				free(tab[i++]);
			free(tab);
			return (0);
		}
		ft_copy_word(tab[word], str, start, end);
		word++;
	}
	tab[word] = NULL;
	return (1);
}

char **ft_split(char *str)
{
	int size;
	char **out;

	size = ft_count_word(str);
	out = malloc ((sizeof(char *) * (size + 1)));
	if (!out)
		return (NULL);
	if (!ft_fill_word(out, str))
	{
		free(out);
		return(NULL);
	}
	return (out);
}