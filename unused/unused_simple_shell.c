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
	int er_flag = 0;

	path = _token_to_av(_getenv("PATH"), ":");

	if (path == NULL)
		write(STDOUT_FILENO, "PATH not found\n", 1024);

	while (1)
	{
		/* getline function. returns index of arguments*/
		index = _getline_tok();
		/*if _getline_tok return NULL if fails or EOF*/
		if (index == NULL)
			break;
		
		er_flag = 0;

		for (j = 0; path[j] != NULL; j++)
		{
			pathname = malloc(sizeof(char) * (_strlen(index[0]) + _strlen(path[j]) + 1));
			pathname = _strconcat(path[j], "/");
			pathname = _strconcat(pathname, index[0]);
			
			/*If command not found, pr*/
			if (stat(pathname, &st) == -1)
			{
				er_flag = 0;
			}
			else
			{
				processid = fork();
				/*Children process strats*/
				if( processid == 0)
				{
					execve(pathname, index, env);
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
			write(STDOUT_FILENO, index[0], 1024);
			write(STDOUT_FILENO, ": Command not found\n", 1024);
		}
		free(pathname);
	}
	return (0);
}
