#include "shell.h"
char *_token(char *str, const char *start)
{
	static char *end;
	char *ptr = NULL;

	while ((*start != '\0') && (*start == ',' || *start == ' '))
		break;
	if (str != NULL)
		end = str;
	if (end == NULL || *end == '\0')
		return (NULL);
	ptr = end;
	while (*end != '\0')
	{
		if (*end == *start)
		{
			*end++ = '\0';
			break;
		}
		end++;
	}
	if (*ptr == '\0')
		return (_token(NULL, start));
	return (ptr);
}
