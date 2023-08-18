#include "shell.h"
/**
 * parse - parses the input string.
 * @input: pointer to a string.
 * Return: pointer to a pointer to an array of strings
 */
char **parse(char *input)
{
	int token_size = TOK_BUF, idx = 0;
	char *portion, **argv = malloc(token_size * sizeof(char *));

	if (argv == NULL)
	{
		free(input);
		exit(EXIT_FAILURE);
	}

	portion = strtok(input, DELIMS);
	while (portion != NULL)
	{
		argv[idx] = portion;
		idx++;
		portion = strtok(NULL, DELIMS);
	}
	argv[idx] = NULL;
	if (argv[0] == NULL)
	{
		free(argv);
		free(input);
		return (NULL);
	}
	return (argv);
}

/**
 * execute_cmd - executes commands.
 * @argv: array of pointers to parsed line.
 * @arv0: name of the shell program.
 * @line: buffer containing line.
 * @cx: pointer to the full path of command.
 * @status: exit status of child proc will be stored here.
 * Return: void.
 */
void execute_cmd(char **argv, char *arv0, char *line, int *status, char *cx)
{
	pid_t child_proc;

	child_proc = fork();

	forkcheck_f(child_proc, line);
	if (child_proc == 0)
	{
		argv[0] = cx;
		execve(argv[0], argv, environ);
		perror(arv0);
		free(argv);
		free(line);
		free(cx);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(status);
		if (WIFEXITED(*status) != 0)
			*status = WEXITSTATUS(*status);
		free(argv);
		free(line);
		free(cx);
	}
}
