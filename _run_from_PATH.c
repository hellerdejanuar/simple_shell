#include "main.h"

/**
 * _run_from_PATH - tries to run program specified in Index[0] 
 * from every directory in env/PATH
 */
int _run_from_PATH(char **path, char** index)
{
	int j = 0;
	char *pathname = NULL;
	char *aux_pathname = NULL;
	struct stat st;
	int processid;
	int er_flag = 0;
	int exit_flag = 0;

	if (index == NULL)
	{
		if (exit_flag == 0)
			free(pathname);
		break;
	}

	for (j = 0; path[j] != NULL; j++)
	{
		exit_flag = 1;

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
}
