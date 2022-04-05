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

		printf("BEFORE fork()getpid %i\n", getpid());
		printf("BEFORE fork()getppid %i\n", getppid());
		pids[i] = fork();
		printf("AFTER fork()getpid %i\n", getpid());
		printf("AFTER fork()getppid %i\n", getppid());
		if (pids[i] == -1)
    		printf("Error with creating process\n");

		if (pids[i] != 0)
		{
			printf("IM A CHILD!! pid: %i\n", pids[i]);
			execve("/bin/ls", argv, env);
			return (0);
		}
	}
	 
	for (i = 0; i < PROCESS_QTY; i++)
	{
		wait(NULL);
	}

	return (0);
}
