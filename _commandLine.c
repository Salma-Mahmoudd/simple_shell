#include "shell.h"
char **_commandLine(char *line)
{
	int j = 0, i = 1;
	char *tok, *tmp, **command;

	tok = _token(line, "\n");
			printf("line %s\n", tok);
	tmp = _token(NULL, " ");
	while (tmp)
		i++, tmp = _token(NULL, " ");
	command = (char **)malloc(sizeof(char *) * (i + 1));
	if (!command)
		return (NULL);
	tok = _token(tok, " ");
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
		tok = _token(NULL, " ");
		j++;
	}
	command[j] = NULL;
	return (command);
}
