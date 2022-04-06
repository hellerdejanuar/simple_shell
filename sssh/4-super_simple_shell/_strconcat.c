#include "main.h"
/**
 *_strconcat - Concatenates two strings, adds '\0' at end.
 *@s1: First string.
 *@s2: Second string.
 *Return: s3, being a string ending in '\0'.
 */

char *_strconcat(char *s1, char *s2)
{
	char *s3;
	unsigned int a = 0;
	unsigned int b = 0;
	unsigned int i;

	for (i = 0 ; s1[i] != '\0'; i++)
	{
		a++;
	}

	for (i = 0; s2[i] != '\0'; i++)
	{
		b++;
	}

	s3 = malloc(sizeof(char) * (a + b + 1));

	for (i = 0; i < a; i++)
	{
		s3[i] = s1[i];
	}
	for (; i < (a + b); i++)
	{
		s3[i] = s2[i - a];
	}
	s3[i] = '\0';

	return (s3);
}
