#include "main.h"
/**
 *_tokcntr - Counts tokens in a string parsed by *token.
 *@str: Line to be tokenized.
 *@token: Separator.
 *Return: Amount of counted separator plus one.
 */
int _tokcntr(char *str, char *token)
{
	int i;
	int a = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			a++;
	}
	return (a);
}
