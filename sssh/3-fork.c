#include "main.h"
#include <unistd.h>
#include <sys/wait.h>
#define PROCESS_QTY 5

int main(void)
{
	int i = 0;
	int pids[PROCESS_QTY];
	char *argv[] ={"ls", "-l", "/tmp", NULL};
	char *env[] = {"/bin/ls",NULL};

	for (i = 0; i < PROCESS_QTY; i++)
	{
		pids[i] = fork();

		if (pids[i] == -1)
    		printf("Error with creating process\n");

		if (pids[i] == 0)
		{
			printf("IM A CHILD!! pid: %i\n", getpid());
			execve("/bin/ls", argv, env);
			return (0);
		}
		wait(NULL);
	}
	return (0);
}
