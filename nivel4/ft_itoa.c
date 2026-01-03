#include <stdlib.h>

static int count_nbr(int n)
{
	int len = 0;
	if(n <= 0)
		len++;
	while (n != 0)
	{
		len = n /10;
		len++;
	}
	return (len);
}

char *ft_itoa(int nbr)
{
	int i;
	char *str;

	i = count_nbr(nbr);
	str = malloc ((i + 1) * size_of(char));
	if (!str)
		return(NULL);
	str[i--] = '\0';
	if (nbr == 0 )
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
		str[0] = '-';
	
}
