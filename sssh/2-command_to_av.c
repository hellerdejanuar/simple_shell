#include "main.h"

int main (void)
{
	char **index = NULL;
	int i;

	index = _getline_tok();

	for (i = 0; index[i] != NULL; i++)
		printf("%s\n", index[i]);

	return (0);
}
char ** _getline_tok (void)
{
	size_t num = 1024;
	char *buf = NULL;
	FILE *str;
	int gl_r;
	char **index = NULL;
	char *token = NULL;

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
}
