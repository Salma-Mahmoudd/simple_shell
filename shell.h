#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;
char **_commandLine(char *line);
void _PATH(char **command);
/*char **_connect(char *path, char **command);*/
void _free(char **mal);
void _env(void);
#endif
