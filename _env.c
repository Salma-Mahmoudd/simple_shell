#include "shell.h"
void _env(void)
{
	char **env = environ;
	int i = 0;

	while (env[i])
	{
		write(1, env[i], strlen(*env));
		write(1, "\n", 1);
		i++;
	}
}
