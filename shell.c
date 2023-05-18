#include "shell.h"
int main(__attribute__((unused))int argc, char **argv, char **env)
{
	pid_t PID;
	int stat;
	char *line, **command;
	size_t len = 0;

	do {
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);
		if (getline(&line, &len, stdin) == -1)
			exit(1);
		command = _commandLine(line);
		if (!command[0])
			continue;
		else
			_PATH(command);
		if (access(command[0], X_OK) == 0)
		{
			PID = fork();
			if (PID == 0 && execve(command[0], command, env) == -1)
				perror(argv[0]);
			else if (PID < 0)
				perror("fork failed"), exit(1);
			else if (PID > 0)
			{
				if (waitpid(PID, &stat, 0) == -1 || !WIFEXITED(stat))
					perror("waitpid failed"), exit(1);
			}
		}
		else
			perror(argv[0]);
		free(line = NULL), _free(command);
	} while (isatty(STDIN_FILENO));
	return (1);
}
