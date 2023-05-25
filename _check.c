#include "shell.h"
/**
 * _check - check exit
 * @command: pointer
 * @line: pointer
 * @stat: integer
 */
void _check(char **command, char *line, int stat)
{
	int s;

	if (!strcmp(command[0], "exit"))
	{
		free(line);
		if (!command[1])
		{
			_free(command);
			exit(WEXITSTATUS(stat));
		}
		s = atoi(command[1]);
		_free(command);
		exit(s);
	}
	else
		_PATH(command);
}
