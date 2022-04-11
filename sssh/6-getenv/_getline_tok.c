#include "main.h"

/**
 * _getline_tok - prints "$ " and waits for input. then tokenizes the line
 * into individual arguments, USES MALLOC.
 * Return: NULL if error or break
 */
char **_getline_tok(void)
{
	size_t num = 1024;
	char *buf = NULL;
	FILE *str;
	int gl_r = 0;
	char **index = NULL;

	str = stdin;
	for (;gl_r != -1;)
	{
		printf("$ ");
		gl_r = getline(&buf, &num, str);
		/* This exceptions could be handled better with the return EOF of getline */
		if (gl_r == -1 || _strcmp("end-of-file\n", buf) || _strcmp("EOF\n", buf))
		{
			free(buf);
			break;
		}
		index = _token_to_av(buf, " ");
			free(buf);	
			return (index);
	}

	return (NULL);
}
