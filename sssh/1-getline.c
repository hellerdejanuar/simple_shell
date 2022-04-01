#include <stdio.h>
#include <unistd.h>

int main (void)
{
	size_t *num = NULL;
	char *buf[1024];
	char *stream = "ThisIsATest";
	*null = 1024;
	getline(buf, num, stream);
	printf("%s\n", *buf);
	return (1);
}
