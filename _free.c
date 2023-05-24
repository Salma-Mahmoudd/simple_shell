#include "shell.h"
/**
 * _free - to free 2d array of malloc
 * @mal: the string
 * Return: Nothing
 */
void _free(char **mal)
{
	int i;

	for (i = 0; mal[i]; i++)
		free(mal[i]);
	if (mal)
		free(mal);
}
