#include <stdio.h>
#include <unistd.h>

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
	printf("%s", buf);
	}
	return (1);
}
