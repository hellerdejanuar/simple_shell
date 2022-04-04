#include "main.h"

char ** _token_to_av (char *str, char* separator)
{
	char **index = NULL;
	char *token = NULL;
	int i;
	/* counts the amount of tokens to be indexed*/
	tok_cn = _tokcntr(str, separator);

	/* allocates some space for the index */
	index = malloc((tok_cn + 1) * sizeof(char *));

	/* init strtok */
	token = strtok(str, separator);

	for (i = 0; token != NULL; i++)
	{
		index[i] = token;
		token = strtok(NULL, separator);
	}

	index[i] = NULL;

	return (index);
}
