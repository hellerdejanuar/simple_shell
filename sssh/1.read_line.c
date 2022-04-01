#include <stdio.h>
int main()
{
	printf("$ ");
	getline(STDOUT_FILENO , , argv[1]);

}
