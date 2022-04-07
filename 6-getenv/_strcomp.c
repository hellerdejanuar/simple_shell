#include "main.h"

/**
 * _strcmp - compares two strings character by character
 * @str1: string 1
 * @str2: string 2
 * Return: 0 if strings are equal. -1 if they are not.
 */
int _strcomp(const char *str1, const char *str2)
{
	int i = 0;

	for (i = 0; str1[i] != '\0'; i++)
	{	
		if (str1[i] != str2[i])
			return (-1);
	}

	if (str1[i] != str2[i])
		return (-1);

	return (0);
}
