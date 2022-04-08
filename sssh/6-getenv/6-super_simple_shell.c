#include "main.h"
#define _PATH "/bin/"
/**
 * main - runs getline_tok to read a line and tokenize the string into a list
 * Return: 0 success
 */
int main(void)
{
	char **index = NULL;
	char **env = NULL;
	char *pathname;
	int i = 0, j = 0;
	struct stat st;
	int processid;
	char **path = NULL;

	path = _token_to_av(_getenv("PATH"), ":");

	for (j = 0; path[j]; j++)
	{
		printf("%s", path[j]);
	}	
	if (path == NULL)
		printf("PATH not found\n");

	while (1)
	{
		/* getline function. returns index of arguments*/
		index = _getline_tok();
		/*if _getline_tok return NULL if fails or EOF*/
		if (index == NULL)
			break;

		for (j = 0; path[j] != NULL; j++)
		{
			free(pathname);
			printf("Actual PATH: %s\n", path[j]);

			pathname = malloc(sizeof(char) * ( _strlen(index[0] + _strlen(path[j]))));
			pathname = _strconcat(path[j], index[0]);

			printf("%s\n", pathname);

			/*If command not found, prints NOT FOUND*/
			if (stat(pathname, &st) == -1)
				printf("%s: NOT FOUND\n", index[i]);
			else
			{
				processid = fork();
				if( processid == 0)
				{
					execve(pathname, index, env);
					/* for (i = 0; index[i] != NULL; i++)
						printf("%s\n", index[i]); */
					exit(0);
				}
				wait(NULL);
				break;
			}
		}
		free(index);
		free(pathname);
	}
	return (0);
}
