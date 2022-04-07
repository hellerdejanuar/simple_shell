#include "main.h"

/**
 * _getenv - searches for a variable in the local environment variables
 * @var: the name of the env variable to be searched for
 * Return: the requested env variable value. NULL if not found
 */
char *_getenv(const char *var)
{
	extern char **environ;
	char *aux = NULL;
	unsigned int var_len = 0, old_var_len = 0, i, j;
	char *value = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		/* counts env var length */
		for (var_len = 0; environ[i][j] != '='; var_len++);

		/* if not enough space in aux to store the var name allocate it*/
		if (var_len > old_var_len)
		{
			free(aux);
			aux = malloc(sizeof(char) * (var_len)); /* seg fault ?? */
		}

		/* stores env var name in string to compare*/
		for (j = 0; environ[i][j] != '='; j++)
		{
			aux[i] = environ[i][j];
		}
		aux[i] = '\0';

		/* if var == aux store the corresponding value and return*/
		if (_strcomp(var, aux))
		{
			free(aux);

			for (j = var_len + 1; environ[i][j] != '\0'; j++);

			value = malloc(sizeof(char) * (j - var_len));

			for (j = var_len + 1; environ[i][j] != '\0'; j++)
			{
				value[j] = environ[i][j];
			}
			value[j] = '\0';

			return(value);
		}
	}

	free(aux);
	return (NULL);
}
