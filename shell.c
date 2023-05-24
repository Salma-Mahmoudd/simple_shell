#include "shell.h"
void _check(char **command, char *line)
{
	int stat;

	/*if (!command[0])
	{
		_free(command);
	}
	else if (!strcmp(command[0], "env"))
	{
		_env();
		continue;
	}*/
	if (!strcmp(command[0], "exit"))
	{
		free(line);
		if (!command[1])
		{
			_free(command);
		       	exit(0);
		}
		stat = atoi(command[1]);
		_free(command);
		exit(stat);
	}
	else
		_PATH(command);
}
/**
 * main - simple shell
 * @argc: no. arguments
 * @argv: pointer to args
 * @env: environ
 * Return: integer
 */
int main(__attribute__((unused))int argc, char **argv, char **env)
{
	pid_t PID;
	int stat;
	char *line = NULL;
	static char **command;
	size_t len = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);
		if (getline(&line, &len, stdin) == -1)
			free(line), exit(0);
		command = _commandLine(line);
		if (!command[0])
		{
			_free(command);
			continue;
		}
		else if (!strcmp(command[0], "env"))
		{
			_env();
			continue;
		}
		else
			_check(command, line);
		if (access(command[0], X_OK) == 0)
		{
			PID = fork();
			if (PID == 0 && execve(command[0], command, env) == -1)
				perror(argv[0]);
			else if (PID < 0)
				perror("fork failed"), exit(1);
			else if (PID > 0)
				waitpid(PID, &stat, 0);
		}
		else
			perror(argv[0]);
		_free(command);
	}
	return (0);
}
