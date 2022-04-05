#include "main.h"

int main (void)
{
	size_t num = 1024;
	char *buf = NULL;
	FILE *str;
	int gl_r;

	str = stdin;
	for (;gl_r != -1;)
	{
	printf("$ ");
	gl_r = getline(&buf, &num, str);
	if (gl_r == -1 || _strcmp("end-of-file\n", buf) || _strcmp("EOF\n", buf))
		break;
	printf("%s", buf);
	}
	return (1);
}
