#include <signal.h>
#include <stdio.h>

#include "signals.h"

sighandler_t handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
}

int handle_signal(void)
{
	signal(SIGINT, handler(SIGINT));
	return (EXIT_SUCCESS);
}
