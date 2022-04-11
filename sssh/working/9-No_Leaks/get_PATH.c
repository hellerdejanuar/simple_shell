#include "main.h"

int main(void)
{
	char **path = NULL;
	int j = 0;

	path = _token_to_av(_getenv("PATH"), ":");
	for (j = 0; path[j] != NULL; j++)
		printf("%s\n", path[j]);

	return 0;
}
