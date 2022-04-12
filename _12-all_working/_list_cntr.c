#include "main.h"

/**
 * _list_cntr - counts elements of a list or index
 * @list: list or index
 * Return: list elements count. NULL if no list is passed
 */
unsigned int _list_cntr(char **list)
{
	unsigned int cn = 0;

	if (!list)
		return (-1);
	while(list[cn])
		cn++;

	return (cn);
}
