#include <stdlib.h>
#include <signal.h>

#include "signals.h"

/**
 * current_handler_sigaction - gets current handler of SIGINT signal
 *
 * Return: address of current SIGINT handler or NULL
 */

void (*current_handler_sigaction(void))(int)
{
	struct sigaction old_action;

	if (sigaction(SIGINT, NULL, &old_action) < 0)
		return (NULL);
	return (old_action.sa_handler);
}
