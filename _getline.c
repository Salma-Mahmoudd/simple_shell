#include "shell.h"
ssize_t _getline(char **line, size_t *len, FILE *stream)
{
	static char *buff;
	ssize_t i = 1, size = 128, check;

	buff = malloc(size + 1);
	if (!buff)
		return (-1);
	else if (!line || !len)
		return (-1);
	else if (read(fileno(stream), buff, 1) <= 0)
		return (-1);

	while (buff[i - 1] != '\n' && (check = read(fileno(stream), buff + i, 1)) > 0)
	{
		i++;
		if (i > size - 1)
		{
			buff = realloc(buff, i + 1);
			if (!buff)
				return (-1);
		}
	}
	if (!buff || check <= 0)
		return (-1);
	buff[i] = '\0';
	*line = buff;
	*len = (size_t)strlen(buff);
	return (i);
}
