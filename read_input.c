#include "shell.h"

/**
 * print_prmpt - prints prompt.
 * @prmpt: prompt to be printed
 * Return: void
 */
void print_prmpt(char *prmpt)
{
	if (isatty(0) != 0)
	{
		write(STDOUT_FILENO, prmpt, strlen(prmpt));
		fflush(stdout);
	}
}
/**
 * get_input - gets input from the user
 * Return: void
 */
char *get_input(void)
{
	char *line = NULL;
	size_t num = 0;

	if (getline(&line, &num, stdin) == -1)
	{
		if (feof(stdin))
		{
			if (isatty(0) != 0)
			{
				free(line);
				write(STDERR_FILENO, "\n", _strlen("\n"));
				exit(EXIT_SUCCESS);
			}
			else
			{
				free(line);
				return (NULL);
			}
		}
		else
		{
			perror("getline");
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
