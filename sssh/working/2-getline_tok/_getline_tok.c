#include "main.h"

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
		if (gl_r == -1 || _strcmp("end-of-file\n", buf) || _strcmp("EOF\n", buf))
			break;

		index = _token_to_av(buf, " ");

		return (index);
	}

	return (NULL);
}
