#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: 1 if s1 equal to s2, 0 if they're different,
 * 
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for(i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return(0);
	}

	if (s2[i] != '\0')
		return(0);

	return (1);
}
