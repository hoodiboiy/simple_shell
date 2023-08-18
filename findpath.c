#include "shell.h"
/**
 * pathfinder - gets the full path of a file.
 * @cmd: array which holds the command typed by user.
 * Return: char pointer
 */
char *pathfinder(char *cmd)
{
	char *path, *path_cpy, *directory, *fpath;

	if (!cmd)
		return (NULL);
	if (access(cmd, F_OK) == 0)
		return (fpath_cmd(cmd));

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_cpy = malloc(_strlen(path) + 1);
	if (path_cpy == NULL)
		return (NULL);
	_strcpy(path_cpy, path);
	directory = strtok(path_cpy, ":");
	while (directory != NULL)
	{
		fpath = malloc(_strlen(cmd) + _strlen(directory) + 2);
		if (fpath == NULL)
		{
			free(path_cpy);
			return (NULL);
		}
		_strcpy(fpath, directory);
		_strcat(fpath, "/");
		_strcat(fpath, cmd);
		if (access(fpath, F_OK) == 0)
		{
			free(path_cpy);
			return (fpath);
		}
		free(fpath);
		directory = strtok(NULL, ":");
	}
	free(path_cpy);
	return (NULL);
}

/**
 * error_clean - prints error message and cleans up if a command doesn't exist.
 * @i: pointer to the current shell iteration.
 * @arv0: the name of the shell program.
 * @argv: parsed user input.
 * @input: user input to shell.
 * @status: execution status.
 * Return: void.
 */
void error_clean(int *i, char *arv0, char *input, char **argv, int *status)
{
	char error_msg[200];

	_memset(error_msg, 0, sizeof(error_msg));
	sprintf(error_msg, "%s: %d: %s: not found", arv0, *i, argv[0]);
	write(STDERR_FILENO, error_msg, strlen(error_msg));
	write(STDERR_FILENO, "\n", _strlen("\n"));
	free(argv);
	free(input);
	if (!isatty(0))
		*status = 127;
}

/**
 * fpath_cmd - checks if a user typed in the fpath of a cmd.
 * @cmd: the cmd.
 * Return: a pointer to the fpath on success or null on failure.
 */
char *fpath_cmd(char *cmd)
{
	char *fpath;

	if (getenv("PATH") == NULL)
		return (NULL);
	fpath = malloc(_strlen(cmd) + 1);
	if (!fpath)
		return (NULL);
	_strcpy(fpath, cmd);
	return (fpath);
}
