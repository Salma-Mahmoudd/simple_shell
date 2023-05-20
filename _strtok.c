#include "shell.h"
char *_token(char *str, char *start)
{
	static char *end;
	char *endtoken;
	char *ptr;

	while (*start != '\0' && (*start == ',' || *start == ' '))
		start++;
	if (str == NULL)
		return (NULL);
	end = str;
	if (end == NULL || *end == '\0')
		return (NULL);
	endtoken = end;
	while (*endtoken != '\0' && *endtoken != *start &&
		       *endtoken != ',' && *endtoken != ' ')
		endtoken++;
	if (*endtoken == *start)
		*endtoken++ = '\0';
	ptr = end;
	end = endtoken;
	return (ptr);
}
