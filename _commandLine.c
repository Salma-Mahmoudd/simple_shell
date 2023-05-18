#include "shell.h"
char **_commandLine(char *line)
{
	int j = 0, i = 1;
	char *tok, *tmp, **command;

	tok = strtok(line, "\n");
	tmp = strtok(NULL, " ");
	while (tmp)
		i++, tmp = strtok(NULL, " ");
	command = (char **)malloc(sizeof(char *) * (i + 1));
	if (!command)
		return (NULL);
	tok = strtok(tok, " ");
	while (tok)
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
