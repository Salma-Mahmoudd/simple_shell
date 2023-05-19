#include "shell.h"
ssize_t _getline(char **line, size_t *len, FILE *stream)
{
	static char *buff;
	ssize_t i = 0, size = 1, check;

	if (!line || !len)
		return (-1);

	buff = malloc(size + 1);
	if (!buff)
		return (-1);

	while ((check = read(fileno(stream), buff + i, 1)) > 0 && buff[i] != '\n')
	{
		if (check == -1)
			return (-1);
		i++;
		if (i > size)
		{
			buff = realloc(buff, i + 1);
			if (!buff)
				return (-1);
		}
	}
	buff[i] = '\0';
	if (!buff)
		return (-1);
	*line = buff;
	*len = (size_t)strlen(buff);
	return (i + 1);
}
