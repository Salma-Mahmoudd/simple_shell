#include "shell.h"
void _free(char **mal)
{
	int i, size = 0;

	while(mal[size])
		size++;
	for (i = 0; i < size; i++)
		free(mal[i] = NULL);
	free(mal);
}
