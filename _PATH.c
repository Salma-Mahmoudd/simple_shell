#include "shell.h"
/**
 * _PATH - to handle PATH environment variable
 * @command: line command to execute
 * Return: Nothing
 */
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
	tmp = command[0];
	path = getenv("PATH");
	path = strdup(path);
	printf("jjjjjjjjjjjjj %s\n", path);
	pathTok = strtok(path, ":");
	while (pathTok)
	{
		fullPath = malloc(strlen(pathTok) + strlen(tmp) + 2);
		strcpy(fullPath, pathTok);
		strcat(fullPath, "/");
		strcat(fullPath, tmp);
		if (access(fullPath, X_OK) == 0)
		{
			command[0] = (char *)realloc(command[0], sizeof(fullPath));
			if (!command[0])
				return;
			strcpy(command[0], fullPath);
			free(fullPath);
			free(path);
			printf("jjjjjjjjjjjjj %s\n", command[0]);
			return;
		}
		else
			free(fullPath), pathTok = strtok(NULL, ":");
	}
	free(path);
}
