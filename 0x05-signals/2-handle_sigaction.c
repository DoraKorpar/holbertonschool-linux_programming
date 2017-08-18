#include <stdio.h>
#include <signal.h>

#include "signals.h"

/**
 * handler - function to be executed when signal handled
 * @signum: signal integer
 *
 * Return: void
 */
void handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
	fflush(stdout);
}

/**
 * handle_sigaction - sets a handler for SIGINT
 *
 * Return: 0 on success, -1 on error
 */
int handle_sigaction(void)
{
	struct sigaction new_action, old_action;

	new_action.sa_handler = handler;

	if (sigaction(SIGINT, NULL, &old_action) < 0)
		return (-1);
	if (old_action.sa_handler != SIG_IGN)
	{
		if (sigaction (SIGINT, &new_action, NULL) != 0)
			return (-1);
	}
	return (0);
}
