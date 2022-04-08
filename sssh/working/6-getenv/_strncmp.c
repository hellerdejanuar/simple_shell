#include "main.h"

/**
 * _strncmp - compares two strings character by character, from beggining a times.
 * @str1: string 1
 * @str2: string 2
 * @n:Qntity of char since [0] to compare.
 * Return: 0 if strings are equal. -1 if they are not.
 */
int _strcomp(const char *str1, const char *str2, int n)
{
	int i = 0;

	if(n <= 0 || !str1 || !str2)
		return (-1);

	for (i = 0; i < n ; i++)
	{	
		/*Checkes wheather same char position are same character in both strings*/
		/*Checkes if n is greater than quantity of chars in both strings.*/
		if (str1[i] != str2[i] || str[i] == '\0' || str[i] == '\0')
			return (-1);
	}
	return (0);
}
