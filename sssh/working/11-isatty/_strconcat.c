#include "main.h"
/**
 *_strconcat - Concatenates two strings, adds '\0' at end.
 *@s1: First string.
 *@s2: Second string.
 *Return: s3, being a string ending in '\0'. NULL if error.
 */

char *_strconcat(char *s1, char *s2)
{
	char *s3;
	unsigned int a = 0;
	unsigned int b = 0;
	unsigned int i;

	if (!s1 || !s2)
		return (NULL);

	/*Sets a to character quantity of s1*/
	for (i = 0 ; s1[i] != '\0'; i++)
	{
		a++;
	}

	/*Sets b to character quantity of s2*/
	for (i = 0; s2[i] != '\0'; i++)
	{
		b++;
	}

	/*Allocates final string before merging*/
	s3 = malloc(sizeof(char) * (a + b + 1));

	if(s3 == NULL)
		return (NULL);

	/*Iterates trough s3 to set every value of the final string*/
	for (i = 0; i < a; i++)
	{
		s3[i] = s1[i];
	}
	for (; i < (a + b); i++)
	{
		s3[i] = s2[i - a];
	}
	/*Adds last null char to string to make it valid*/
	s3[i] = '\0';

	return (s3);
}
