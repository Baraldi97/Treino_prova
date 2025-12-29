/*Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$*/

#include <unistd.h>
#include <stdio.h>

int main (int ac, char *av[])
{
	int i;
	if (ac == 2)
	{
		i = 0;
		int last_pos = 0;
		while(av[1][i])
			i++;
		last_pos = i -1;
		while (last_pos >= 0)
			write (1, &av[1][last_pos--], 1);
	}
	write (1, "\n", 1);
}