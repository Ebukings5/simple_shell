#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>

void shell_prompt();
int execute_command(const char *command);

#endif
