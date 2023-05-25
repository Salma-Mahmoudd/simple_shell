#include "shell.h"
/**
 * _commandLine - to edit the command line
 * @line: token from user
 * Return: string of line
 */
char **_commandLine(char *line)
{
	int j = 0, i;
	char *tok, *tmp, **command;

	tok = strtok(line, "\n");
	tmp = strtok(NULL, " ");
	while (tmp)
		i++, tmp = strtok(NULL, " ");
	for (i = 1; line[i]; i++)
	{
		if (line[i] == ' ' && line[i - 1] != ' ')
			i++;
	}
	command = malloc((i + 1) * sizeof(char *));
	if (!command)
		return (NULL);
	tok = strtok(tok, " ");
	while (tok)
	{
		command[j] = malloc(strlen(tok) + 1);
		if (command[j] == NULL)
		{
			/**while (--j >= 0)*/
			for (i = 0; i < j; i++)
				free(command[j]);
			free(command[j]);
			free(command);
			return (NULL);
		}
		strcpy(command[j], tok);
		/**printf("%s %d\n", command[j], j);*/
		tok = strtok(NULL, " ");
		j++;
	}
	command[j] = NULL;
	return (command);
}
