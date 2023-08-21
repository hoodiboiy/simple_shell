#include "shell.h"

/**
 * forkcheck_f - checks if the call to fork failed.
 * @child: process id returned by fork.
 * @input: pointer to a buffer where user input is.
 *
 * Return: void.
 */
void forkcheck_f(pid_t child, char *input)
{
	if (child == -1)
	{
		free(input);
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
}
