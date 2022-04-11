#include "main.h"
#define _PATH "/bin/"
/**
 * main - runs getline_tok to read a line and tokenize the string into a list
 * Return: 0 success
 */
int main(void)
{
	char **index = NULL;
	char *pathname = NULL, *aux_pathname = NULL;
	int j = 0, k = 0;
	struct stat st;
	int processid;
	char **path = NULL;
	char *aux_path = NULL;
	int er_flag = 0;
	int exit_flag = 0;

	aux_path = _getenv("PATH");
	path = _token_to_av(aux_path, ":");

	if (path == NULL)
		printf("PATH not found\n");

	while (1)
	{
		er_flag = 0;
		
		/* getline function. returns index of arguments*/
		index = _getline_tok();
		/*if _getline_tok return NULL if fails or EOF*/
		if (index == NULL)
		{
			if (exit_flag == 0)
				free(pathname);
			break;
		}

		for (j = 0; path[j] != NULL; j++)
		{
			exit_flag = 1;
			/*pathname = malloc(sizeof(char) * (_strlen(index[0]) + _strlen(path[j]) + 1)); jeeejooooo */
			aux_pathname = _strconcat(path[j], "/");
			pathname = _strconcat(aux_pathname, index[0]);
			free(aux_pathname);

			/*If command not found, set flag to print error*/
			if (stat(pathname, &st) != -1)
			{
				processid = fork();
				/*Children process strats*/
				if( processid == 0)
				{
					execve(pathname, index, NULL);
					/*Kill children when execve fails*/
					exit(0);
				}
				wait(NULL);
				er_flag = 1;
				free(pathname);
				break;
			}
			else
			{
				free(pathname);
			}
		}
		/*Outside for-loop, if command not found on any PATH*/
		if (er_flag == 0)	
			printf("%s: Command not found.\n", index[0]);
		
/* -- Free Mallocs -- */
	/*	for (k = 0;path[k] != NULL; k++)
			free(path[k]);*/

	/*	free(path);*/
/*	*	free(pathname);*/
		free(index);
	}
	free(path);
	free(aux_path);
	return (0);
}
