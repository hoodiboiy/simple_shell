#include "shell.h"
/**
 * check_mode - checks for interactive and non interactive mode.
 * @arv0: The name of the shell program.
 * @i: pointer to main counter.
 * Return: void.
 */
void check_mode(char *arv0, int *i)
{
	char *prmpt = "#cisfun$ ", *cx, *line, **argv;
	int status = 0;

	if (isatty(0) == 0)
	{
		while ((line = get_input()) != NULL)
		{
			if (_strlen(line) == 1)
			{
				free(line);
				continue;
			}
			argv = parse(line);
			if (argv == NULL ||
			    builtin_cmds(i, argv, line, arv0, &status) == 0)
				exit(EXIT_SUCCESS);
			cx = pathfinder(argv[0]);
			if (cx == NULL)
				error_clean(i, arv0, line, argv, &status);
			else
				execute_cmd(argv, arv0, line, &status, cx);
		}
		exit(status);
	}
	else
	{
		print_prmpt(prmpt);
		line = get_input();
		argv = parse(line);
		if (argv == NULL || builtin_cmds(i, argv, line, arv0, &status) == 0)
			return;
		cx = pathfinder(argv[0]);
		if (cx == NULL)
			error_clean(i, arv0, line, argv, &status);
		else
			execute_cmd(argv, arv0, line, &status, cx);
	}
}
