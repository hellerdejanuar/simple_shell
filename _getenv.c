#include "main.h"

/**
 * _getenv - searches for a variable in the local environment variables
 * @var: the name of the env variable to be searched for
 * Return: the requested env variable value. NULL if not found
 */
char *_getenv(const char *var)
{
	extern char **environ;
	unsigned int var_len = 0, i = 0, j = 0;
	char *value = NULL;

	if (var == NULL || environ == NULL)
		return (NULL);

	/* iterate trough elements of list*/
	for (i = 0; environ[i] != NULL; i++)
	{
		/* counts env var length */
		for (var_len = 0; environ[i][var_len] != '='; var_len++);

		/* compares var to first 'var_len' chars of environ */
		if (strncmp(environ[i], var, var_len) != 0)
			continue;

		/* if environ variable ends right after the var_len allocate the rest
		 * in value and return */
		if (environ[i][var_len] == '=')
		{

			for (j = var_len + 1; environ[i][j] != '\0'; j++);

			value = malloc(sizeof(char) * (j - var_len));
				if (value == NULL)
				{
					return (NULL);
				}

			for (j = var_len + 1; environ[i][j] != '\0'; j++)
			{
				value[j - var_len - 1] = environ[i][j];
			}

			value[j - var_len - 1] = '\0';

			return(value);
		}
	}

	return (NULL);
}
