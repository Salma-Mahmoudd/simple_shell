#include "shell.h"
void _free(char **mal)
{
	int i;

	for (i = 0; mal[i]; i++)
		free(mal[i] = NULL);
	free(mal);
}
