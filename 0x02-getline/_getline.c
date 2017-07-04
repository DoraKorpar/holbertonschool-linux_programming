#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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
	char *buf;
	char *line;
	int i, j;
	size_t nread;

	if ((buf = malloc(READ_SIZE)) == NULL)
	{
		return (NULL);
	}
	if ((line = malloc(READ_SIZE * 2)) == NULL)
	{
		return (NULL);							\
	}

	while ((nread = read(fd, buf, READ_SIZE)) > 0)
	{
		i = 0;
		j = 0;
		while (buf[i + 1]) /* i + 1 so last newline char is cut off from line */
		{
			line[j] = buf[i];
			i++;
			j++;
		}
		return (line);
	}
	return (NULL);
}
