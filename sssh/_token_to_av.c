#include "main.h"

/**
 * returns a list of all the arguments tokenized 
 * (with the last newline removed)
 */
char **_token_to_av(char *str, char* separator)
{
	char **index = NULL;
	char *token = NULL;
	int i, tok_cn, n;

	/* counts the amount of tokens to be indexed*/
	tok_cn = _tokcntr(str, separator);
	if (tok_cn == -1)
	{
		printf("lala");
		return (NULL);
	}
	
	/* allocates some space for the index */
	index = malloc((tok_cn + 1) * sizeof(char *));
	if (index == NULL)
		return(NULL);
	/* init strtok */
	token = strtok(str, separator);

	for (i = 0; token != NULL; i++)
	{
		index[i] = token;
		token = strtok(NULL, separator);
	}

	index[i] = NULL;

	for (n = 0; index[i - 1][n] != '\n'; n++)
	{
			if (index[i -1][n] == '\0')
				break;
	}

	index[i - 1][n] = '\0';

	return (index);
}
