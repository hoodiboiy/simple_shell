#include "shell.h"
#include <errno.h>

/**
 * _env - prints the environment variables.
 * @args: an array of pointers to the env variables.
 * @input: user input to shell.
 * @status: exit status of last process.
 * Return: 0 on success, 1 on failure.
 */
int _env(char **args, char *input, __attribute__((unused))int *status)
{
	char **env = environ;

	if (args[1])
		return (1);
	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", _strlen("\n"));
		env++;
	}
	free(args);
	free(input);
	return (0);
}

/**
 * _exxit - exits the shell.
 * @args: pointer to a pointer to an array of parsed input.
 * @input: buffer to the command.
 * @status: exit status of last process.
 * Return: doesn't return.
 */
int _exxit(char **args, char *input, int *status)
{
	if (args[1])
	{
		if (_atoi(args[1]) > 0 ||
		    (_atoi(args[1]) == 0 && _strcmp(args[1], "0") == 0))
			*status = _atoi(args[1]);
		else
		{
			*status = 2;
			return (2);
		}
	}
	free(args);
	free(input);
	exit(*status);
}
/**
 * _cd - changes directory.
 * @args: pointer to an array pointers to parsed input.
 * @input: buffer to the command.
 * @status: exit status of last process.
 * Return: -1 on failure and 0 on success.
 */
int _cd(char **args, char *input, __attribute__((unused))int *status)
{
	char *home, buff[1024];

	if (args[1] == NULL)
	{
		home = getenv("HOME");
		if (!home || chdir(home) != 0)
			return (-1);
	}
	else if (chdir(args[1]) != 0)
		return (-1);

	if (getcwd(buff, sizeof(buff)) != NULL && !isatty(0))
	{
		write(STDOUT_FILENO, buff, _strlen(buff));
		write(STDOUT_FILENO, "\n", _strlen("\n"));
	}
	free(args);
	free(input);
	return (0);
}

/**
 * _setenv - sets environment variable.
 * @args: pointer to a pointer to an array of parsed input.
 * @input: desired variable.
 * @status: exit status.
 * Return: 3 on failure and 0 on success.
 */
int _setenv(char **args, char *input, __attribute__((unused))int *status)
{
	char *new_var, *var, *val, **env = environ;
	int i, var_len, val_len;

	if (!args)
		return (3);
	var = args[1];
	val = args[2];
	var_len = _strlen(var);
	val_len = _strlen(val);
	new_var = (char *)malloc((var_len + val_len + 2) * sizeof(char));
	if (new_var == NULL)
		return (3);
	sprintf(new_var, "%s=%s", var, val);
	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], var, var_len) == 0 && env[i][var_len] == '=')
		{
			free(env[i]);
			env[i] = new_var;
			return (0);
		}
	}
	env[i] = new_var;
	env[i + 1] = NULL;
	free(args);
	free(input);
	return (0);
}

/**
 * _unsetenv - unsets environment variable.
 * @args: pointer to a pointer to an array of parsed input.
 * @input: desired variable.
 * @status: exit status.
 * Return: -3 on failure and 0 on success.
 */
int _unsetenv(char **args, char *input, __attribute__((unused))int *status)
{
	char *var, **env = environ;
	int i, var_len;

	if (!args)
		return (-3);
	var = args[1];
	var_len = _strlen(var);
	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(env[i], var, var_len) == 0 && env[i][var_len] == '=')
		{
			free(env[i]);
			while (env[i + 1] != NULL)
			{
				env[i] = env[i + 1];
				i++;
			}
			env[i] = NULL;
			return (0);
		}
	}
	/* fprintf(stderr, "Error: %s environment variable not found\n", var); */
	free(args);
	free(input);
	return (-3);
}
