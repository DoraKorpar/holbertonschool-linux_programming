#include <unistd.h>
#include <stdlib.h>

#include "_getline.h"

/**
 * _getline - reads an entire line from file descriptor
 *
 * @fd - file descriptor to read from
 *
 * Return - string of line read or NULL
 */
char *_getline(const int fd)
{
	static char *buf;
	char *line;
	int i, j;
	size_t nread;

	buf = malloc(READ_SIZE);
	if (buf == NULL)
	{
		return (NULL);
	}

	while ((nread = read(fd, buf, READ_SIZE)) > 0)
	{
		line = malloc(READ_SIZE);
		if (line == NULL)
		{
			free(buf);
			return (NULL);
		}

		i = 0;
		j = 0;
		while (buf[i + 1]) /* i + 1 so last newline char is cut off from line */
		{
			line[j] = buf[i];
			i++;
			j++;
		}
		line[j] = '\0';
		free(buf);
		return (line);
	}
	free(buf);
	return (NULL);
}
