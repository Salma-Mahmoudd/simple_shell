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
void _free(char **mal)
{
	int i, size = 0;

	while(mal[size])
		size++;
	for (i = 0; i < size; i++)
		free(mal[i] = NULL);
	free(mal);
}
int main(__attribute__((unused))int argc, char **argv, char **env)
{
	pid_t PID;
	int stat, lineFlag;
	char *line, **command;
	size_t len = 0;

	do
	{
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);
		lineFlag = getline(&line, &len, stdin);
		if (lineFlag == -1)
			exit(1);
		command = _commandLine(line);
		if (access(command[0], F_OK) == 0 && command)
		{
			PID = fork();
			if (PID < 0)
				return (0);
			if (PID != 0)
			{
				waitpid(PID, &stat, 0);
				if (!WIFEXITED(stat))
					return (0);
			}
			else
			{
				if (execve(command[0], command, env) == -1)
					perror(argv[0]);
			}
		}
		else
			perror(argv[0]);
		free(line = NULL), _free(command);
	} while (isatty(STDIN_FILENO));
	return (1);
}
