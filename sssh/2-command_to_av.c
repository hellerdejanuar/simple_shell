#include "main.h"

int main(void)
{
	char **index = NULL;
	int i;

	index = _getline_tok();

	for (i = 0; index[i] != NULL; i++)
		printf("%s\n", index[i]);

	return (0);
}
