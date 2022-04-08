#include "main.h"
#define _PATH "/bin/"
/**
 * main - runs getline_tok to read a line and tokenize the string into a list
 * Return: 0 success
 */
int main(void)
{
	char **index = NULL;
	char *argv[] = {NULL};
	char *env[] = {NULL};
	char *pathname;
	unsigned int arg_cn = 0;
	int i = 0;
	struct stat st;

int processid;
	while (1)
	{
		/* getline function. returns index of arguments*/
		index = _getline_tok();
		/*if _getline_tok return NULL if fails or EOF*/
		if (index == NULL)
			break;

		pathname = malloc(sizeof(char) * ( _strlen(index[0] + _strlen(_PATH))));
		pathname = _strconcat(_PATH, index[0]);

		arg_cn = _list_cntr(index);
		/* Allocates argv */

		*argv = malloc(arg_cn * sizeof(char *));

		/*Loop through index[] to set argv[]*/
		for (i = 0; index[i] != NULL; i++)
		{
		argv[i] = index[i];
		}
		argv[i] = index[i];
		i = 0;

		/*If command not found, prints NOT FOUND*/
		if (stat(pathname, &st) == -1)
			printf("%s: NOT FOUND\n", argv[i]);

		processid = fork();
		if( processid == 0)
		{
			execve(pathname, argv, env);
			/* for (i = 0; index[i] != NULL; i++)
				printf("%s\n", index[i]); */
			exit(0);
		}
		wait(NULL);
		

		free(index);
		free(pathname);
	}
	return (0);
}
