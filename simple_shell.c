#include "main.h"
/**
 * main - runs getline_tok to read a line and tokenize the string into a list
 * Return: 0 success
 */
int main(void)
{
	char **index = NULL;
	extern char **environ;
	char *pathname = NULL, *aux_pathname = NULL, *aux_path = NULL;
	int j = 0, i = 0;
	struct stat st;
	int processid;
	char **path = NULL;
	int lit_path_flg = 0;
	int er_flag = 0, exit_flag = 0;
	
	aux_path = _getenv("PATH");
	path = _token_to_av(aux_path, ":");

	if (path == NULL)
		printf("PATH not found\n");

	while (1)
	{
		if (exit_flag == 1)
			break;

		/* getline function. returns index of arguments*/
		index = _getline_tok();
		/*if _getline_tok return NULL if fails or EOF*/
		if (index == NULL)
		{
			break;
		}

		if (index[0][0] == '\n')
		{
			free(index[0]);
			free(index);
			continue;
		}

		er_flag = 0;
		lit_path_flg = 0;

		for (j = 0; path[j] != NULL && lit_path_flg == 0; j++)
		{
			if ((_strcomp(index[0], "env", 3) == 0) && (index[0][3] == '\0'))
			{
				for(i = 0; environ[i] != NULL; i++)
				{
					write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
					write(STDOUT_FILENO, "\n", 1);
				}
				lit_path_flg = 1;
				er_flag = 1;
				break;
			}
			if ((_strcomp(index[0], "exit", 4) == 0) && (index[0][4] == '\0'))
			{
				exit_flag = 1;
				er_flag = 1;
				break;
			}

			if (index[0][0] != '/') /* to search through PATH */ 
			{
				aux_pathname = _strconcat(path[j], "/");
				pathname = _strconcat(aux_pathname, index[0]);
				free(aux_pathname);
			}
			else /* literal path */
			{
				pathname = index[0];
				lit_path_flg = 1;
				if (index[0][1] == '\0') /* only / */
					break;
			}

			/* checks if command not found */
			if (stat(pathname, &st) == -1)
			{
				er_flag = 0;
				if (lit_path_flg != 1)
					free(pathname);
			}
			else
			{
				processid = fork();
				/*Children process strats*/
				if( processid == 0)
				{
					execve(pathname, index, NULL);
					perror("Error");
					/*Kill children when execve fails*/
					exit(0);
				}
				wait(NULL);
				er_flag = 1;
				break;
			}
		}
		/*Outside for-loop, if command not found on any PATH*/
		if (er_flag == 0)	
		{
			write(STDOUT_FILENO, index[0], _strlen(index[0]));
			write(STDOUT_FILENO, ": Command not found.\n", 21);
		}
		else if (lit_path_flg != 1)	
			free(pathname);

		free(index[0]);
		free(index);
	}
	free(aux_path);
	free(path);
	if (isatty(0))
		write(STDOUT_FILENO, "exit\n", 5);
	return (0);
}
