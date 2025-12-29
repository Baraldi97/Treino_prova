/*Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);*/

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return(i);
}

#include <stdio.h>

int main (void)
{
	char *name = "Rodrigo";
	int len = 0;
	len = ft_strlen(name);
	printf("O tamanho do meu nome %s é: %d\n", name, len);
	return (0);
}