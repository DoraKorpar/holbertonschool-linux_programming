#include <signal.h>
#include <stdio.h>

#include "signals.h"

/**
 * handler - function to be executed when signal handled
 *
 * Return: void
 */
void handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
}

/**
 * handle_signal - sets a handler for the signal SIGINT
 *
 * Return: EXIT_SUCCESS on success, -1 on failure
 */
int handle_signal(void)
{
	if (signal(SIGINT, handler) == SIG_ERR)
		return (-1);
	while(1)
		sleep(1);
	return (EXIT_SUCCESS);
}
