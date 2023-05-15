#include "shell.h"
int main(__attribute__((unused))int argc, char **argv, char **env)
{
	pid_t PID;
	int stat, lineFlag;
	char *line, *command[] = {"/bin/ls", NULL};
	size_t len = 0;

	do
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
		if (isatty(STDIN_FILENO))
			write(1, "#cisfun$ ", 9);
		lineFlag = getline(&line, &len, stdin);
		if (lineFlag == -1)
			exit(1);
		command[0] = strtok(strtok(line, "\n"), " ");
		if (execve(command[0], command, env) == -1)
			printf("exe\n%s\n", command[0]), perror(argv[0]);
		free(line = NULL);
	} while (isatty(STDIN_FILENO));
	return (1);
}
