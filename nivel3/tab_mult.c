/*Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>*/

#include <unistd.h>

int ft_atoi(char *s)
{
	int res = 0, i = 0;
	while(s[i] && (s[i] >= 48 && s[i]<= 57))
	{
		res *= 10;
		res += s[i] - 48;
		i++;
	}
	return (res);
}

void ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void ft_putstr(char *s)
{
	int i = 0;
	while(s[i])
		write (1, &s[i++], 1);
}
int main (int ac, char *av[])
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	
	int i = 1;
	int nb = ft_atoi(av[1]);
	while(i < 10)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putnbr(nb);
		ft_putstr(" = ");
		ft_putnbr(i * nb);
		write (1, "\n", 1);
		i++;
	}
}