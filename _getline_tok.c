#include "main.h"

/**
 * _getline_tok - prints "$ " and waits for input. then tokenizes the line
 * into individual arguments
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
		if (isatty(0))
		write(STDOUT_FILENO, "$ ", 2);

		gl_r = getline(&buf, &num, str);
		/* This exceptions could be handled better with the return EOF of getline */
		if (gl_r == -1 || _strcmp("end-of-file\n", buf) || _strcmp("EOF\n", buf))
			break;
		if (buf[0] == '\n')
		{
			index = malloc(sizeof(char *) * 2);	
			index[0] = buf;
			index[1] = NULL;
			return (index);
		}
		index = _token_to_av(buf, " ");

		return (index);
	}
	free(buf);
	return (NULL);
}
