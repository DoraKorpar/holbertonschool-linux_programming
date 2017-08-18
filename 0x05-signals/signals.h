#ifndef _SIGNALS_H_
#define _SIGNALS_H_

#define EXIT_SUCCESS 0

int handle_signal(void);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);

#endif
