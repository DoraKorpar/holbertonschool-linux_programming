#include <stdlib.h>
#include <signal.h>

#include "signals.h"

void (*current_handler_sigaction(void))(int)
{
	struct sigaction old_action;

	if (sigaction(SIGINT, NULL, &old_action) < 0)
		return (NULL);
	return (&old_action);
}
