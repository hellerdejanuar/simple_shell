#include "main.h"
/**
 *_tokcntr - Counts tokens in a string parsed by *token.
 *@str: Line to be tokenized.
 *@separator: Separator.
 *Return: Amount of counted separator plus one.
 */
int _tokcntr(char *str, char *separator)
{
	int i;
	int flag = 0;
	int a = 0;

	if(!str)
		return (-1);

	if (separator[1] != '\0')
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (flag != 1)
			a++;
		if (str[i] == separator[0])
			a++;
		flag = 1;
	}

	/* only works with a one character long separator */
	return (a);
}
