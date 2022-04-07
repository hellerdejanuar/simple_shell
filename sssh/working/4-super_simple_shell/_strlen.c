#include "main.h"
/**
 * _strlen - Function that returns the length of a string.
 * @s: Pointer to String.
 * Return: The lenght of the sring
 */
int _strlen(char *s)
{
	int a = 0;

	if (!s)
		return (-1);

	while (*s != '\0')
	{
		a++;
		s++;
	}
	return (a);
}
