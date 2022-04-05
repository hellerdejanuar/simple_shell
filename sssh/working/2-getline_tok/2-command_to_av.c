#include "main.h"

/**
 * main - runs getline_tok to read a line and tokenize the string into a list
 * Return: 0 success
 */
int main(void)
{
	char **index = NULL;
	int i;

	while (1)
	{
		index = _getline_tok();

		if (index == NULL)
			break;

		for (i = 0; index[i] != NULL; i++)
			printf("%s\n", index[i]);

		free(index);
	}

	return (0);
}
