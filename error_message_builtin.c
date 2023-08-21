#include "shell.h"

/**
 * cd_error - prints error message and cleans up if a command doesn't exist.
 * @i: pointer to the current shell iteration.
 * @arv0: the name of the shell program.
 * @argv: parsed user input.
 * @input: user input to shell.
 * @status: execution status.
 * Return: void.
 */
void cd_error(int *i, char *arv0, char *input, char **argv, int *status)
{
	char error_msg[200];

	_memset(error_msg, 0, sizeof(error_msg));
	sprintf(error_msg, "%s: %d: %s: can't cd to %s", arv0, *i, argv[0], argv[1]);
	write(STDERR_FILENO, error_msg, _strlen(error_msg));
	write(STDERR_FILENO, "\n", _strlen("\n"));
	free(argv);
	free(input);
	*status = 2;
	if (isatty(0) == 0)
		exit(*status);
}

/**
 * env_error - prints error message and cleans up if a command doesn't exist.
 * @argv: parsed user input.
 * @input: user input to shell.
 * @status: execution status.
 * Return: void.
 */
void env_error(char *input, char **argv, int *status)
{
	char error_msg[200];

	_memset(error_msg, 0, sizeof(error_msg));
	sprintf(error_msg, "%s: '%s': No such file or directory", argv[0], argv[1]);
	write(STDERR_FILENO, error_msg, _strlen(error_msg));
	write(STDERR_FILENO, "\n", _strlen("\n"));
	free(argv);
	free(input);
	*status = 127;
	if (isatty(0) == 0)
		exit(*status);
}

/**
 * exit_error - prints error message and cleans up if a command doesn't exist.
 * @i: pointer to the current shell iteration.
 * @arv0: the name of the shell program.
 * @argv: parsed user input.
 * @input: user input to shell.
 * @status: execution status.
 * Return: void.
 */
void exit_error(int *i, char *arv0, char *input, char **argv, int *status)
{
	char error_msg[200];

	_memset(error_msg, 0, sizeof(error_msg));
	sprintf(error_msg, "%s: %d: %s: Illegal number: %s", arv0, *i, argv[0],
		argv[1]);
	write(STDERR_FILENO, error_msg, _strlen(error_msg));
	write(STDERR_FILENO, "\n", _strlen("\n"));
	free(argv);
	free(input);
	*status = 2;
	if (!isatty(0))
		exit(*status);
}

/**
 * setenv_error - prints error message, cleans up if a command doesn't exist.
 * @i: pointer to the current shell iteration.
 * @arv0: the name of the shell program.
 * @argv: parsed user input.
 * @input: user input to shell.
 * @status: execution status.
 * Return: void.
 */
void setenv_error(int *i, char *arv0, char *input, char **argv, int *status)
{
	(void)i;
	(void)arv0;
	(void)input;
	(void)argv;
	(void)status;
}

/**
 * unsetenv_error - prints error message, cleans up if a command doesn't exist.
 * @i: pointer to the current shell iteration.
 * @arv0: the name of the shell program.
 * @argv: parsed user input.
 * @input: user input to shell.
 * @status: execution status.
 * Return: void.
 */
void unsetenv_error(int *i, char *arv0, char *input, char **argv, int *status)
{
	(void)i;
	(void)arv0;
	(void)input;
	(void)argv;
	(void)status;
}
