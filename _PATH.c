#include "shell.h"
void _PATH(char **command)
{
	char *tmp, *fullPath, *path, *pathTok;

	if (access(command[0], X_OK) == 0)
		return;
	if (!strcmp(command[0], "exit"))
	{
		if (!command[1])
			exit(0);
		exit(atoi(command[1]));
	}
	if (!strcmp(command[0], "env"))
	{
		_env();
		return;
	}
	tmp = command[0];
	path = getenv("PATH");
	path = strdup(path);
	pathTok = strtok(path, ":");
	while (pathTok)
	{
		fullPath = malloc(strlen(pathTok) + strlen(tmp) + 2);
		strcpy(fullPath, pathTok);
		strcat(fullPath, "/");
		strcat(fullPath, tmp);
		if (access(fullPath, X_OK) == 0)
		{
			free(command[0]);
			command[0] = fullPath;
			free(path);
			printf("comm %s\n", command[0]);
			printf("comm %s\n", command[1]);
			return;
		}
		else
			free(fullPath), pathTok = strtok(NULL, ":");
	}
	free(path);
}
