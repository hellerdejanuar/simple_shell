#include <stdio.h>

int main(int ac, char **av)
{
	int n;
	for (n = 1; av[n] != NULL; n++)
	{
		printf("%s\n", av[n]);
	}
	return (0);
}
