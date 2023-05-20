#include "shell.h"
void _env(void)
{
	char **env = environ;
	int i = 0;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
