#include "shell.h"
char **_commandLine(char *line)
{
	int j = 0, i = 0;
	char *tok, *tmp, **command;

	tok = strtok(line, "\n");
	tmp = tok;
	while (tmp)
		i++, tmp = strtok(NULL, " ");
	command = (char **)malloc(i + 2);
	if (!command)
		return (NULL);
	tok = strtok(tok, " ");
	while (j < i + 2 && tok)
	{
		command[j] = malloc(strlen(tok) + 1);
		if (command[j] == NULL)
		{
			while (--j >= 0)
				free(command[j]);
			free(command);
			return (NULL);
		}
		command[j] = tok;
		tok = strtok(NULL, " ");
		j++;
	}
	command[j] = NULL;
	return (command);
}
