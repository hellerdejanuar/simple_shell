#include "main.h"

/**
 * main - runs getline_tok to read a line and tokenize the string into a list
 * Return: 0 success
 */
int main(void)
{
	char **index = NULL;
	char *argv[] ={"ls", "-l", "./", NULL}; 
	char *env[] = {"/bin/ls", NULL}; /* PATH ? */

	while (1)
	{
		/* getline function. returns index to */
		index = _getline_tok();

		if (index == NULL)
			break;

		execve("/bin/ls", argv, env);
		/* for (i = 0; index[i] != NULL; i++)
			printf("%s\n", index[i]); */

		free(index);
	}

	return (0);
}
