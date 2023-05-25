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
ssize_t _getline(char **line, size_t *len, FILE *stream);
void _check(char **command, char *line, int stat);
void _free(char **mal);
void _env(void);
char *_token(char *str, const char *start);
#endif
