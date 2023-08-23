#include "shell.h"

/**
 * number_builtins - returns the number of builtin commands.
 * Return: no. of builtins as stated above.
 */
int number_builtins(void)
{
	char *builtin_array[] = {"cd", "env", "exit", "setenv", "unsetenv"};

	return (sizeof(builtin_array) / sizeof(char *));
}

/**
 * num_builtins_error - returns the number of builtin returns.
 * Return: no. of builtins_returns as stated above.
 */
int num_builtins_error(void)
{
	int builtin_error[] = {1, -1, 2, 3, 3};

	return (sizeof(builtin_error) / sizeof(int));
}

/**
 * builtin_cmds - handles builtin commands.
 * @i: pointer to the current shell counter.
 * @argv: parsed user input.
 * @input: user input to shell.
 * @arv0: the name of the shell program.
 * @status: execution status.
 * Return: 0 on success and 1 on failure.
 */
int builtin_cmds(int *i, char **argv, char *input, char *arv0, int *status)
{
	int (*builtin_functions[]) (char **, char *, int *status) = {
		_cd, _env, _exxit, _setenv, _unsetenv};
	char *builtin_array[] = {"cd", "env", "exit", "setenv", "unsetenv"};
	int ret_val, k;

	for (k = 0; k < number_builtins(); k++)
	{
		if (strcmp(argv[0], builtin_array[k]) == 0)
		{
			ret_val = (*builtin_functions[k])(argv, input, status);
			switch (ret_val)
			{
				case 0:
					return (0);
				case 1:
					env_error(input, argv, status);
					return (0);
				case -1:
					cd_error(i, arv0, input, argv, status);
					return (0);
				case 2:
					exit_error(i, arv0, input, argv, status);
			}
		}
	}
	return (1);
}
