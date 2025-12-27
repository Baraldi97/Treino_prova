/*Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);*/

#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int main (void)
{
	char *name = "Rodrigo";
	char receivedname[8];
	ft_strcpy(name, receivedname);
	printf("Minha variável 'nome recebido' vale: %s\n", receivedname);
	return (0);
}