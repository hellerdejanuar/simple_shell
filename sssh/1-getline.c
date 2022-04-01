#include <stdio.h>
#include <unistd.h>

int main (void)
{
	size_t num = 1024;
	char *buf = NULL;
	FILE *str;

	str = fopen("asdf", "r");

	getline(&buf, &num, str);
	printf("%s\n", buf);
	return (1);
}
