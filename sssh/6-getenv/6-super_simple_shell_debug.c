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
	char *pathname = NULL;
	int j = 0;
	struct stat st;
	int processid;
	char **path = NULL;

	path = _token_to_av(_getenv("PATH"), ":");

	for (j = 0; path[j]; j++)
	{
		printf("test: %s\n", path[j]);
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

			printf("Actual PATH: %s\n", path[j]);

			printf("INDEX 0 before: %s\n", index[0]);

			pathname = malloc(sizeof(char) * (_strlen(index[0]) + _strlen(path[j]) + 1));
			pathname = _strconcat(path[j], "/");
			pathname = _strconcat(pathname, index[0]);
			
			if (pathname == NULL)
				printf("PANIK! ");
			printf("PATHNAME: %s\n", pathname);

			/*If command not found, prints NOT FOUND*/
			if (stat(pathname, &st) == -1)
				{
					printf("%s: NOT FOUND\n", index[0]);
					printf("INDEX 0  after: %s\n", index[0]);
				}
			else
			{
				printf("%s: FOUND!!\n", index[0]);
				processid = fork();
				if( processid == 0)
				{
					execve(pathname, index, env);
					/* for (i = 0; index[i] != NULL; i++)
						printf("%s\n", index[i]); */
					exit(0);
				}
				wait(NULL);
				printf("INDEX 0  after: %s\n", index[0]);
				break;
			}
		}
		free(pathname);
	}
	return (0);
}
