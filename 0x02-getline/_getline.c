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
	char *buf;
	size_t nread;

	if ((buf = malloc(READ_SIZE)) == NULL)
	{
		return (NULL);
	}

	while ((nread = read(fd, buf, READ_SIZE)) > 0)
	{
		return (buf);
	}
	return (NULL);
}
