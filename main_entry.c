#include "shell.h"
/**
 * main - main function for the shell.
 * @arc: argument count.
 * @arv: ana array of pointers to the program.
 * Return: always 0 (succes).
 */
int main(__attribute__((unused)) int arc, char **arv)
{
	int loop = 1;

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		check_mode(arv[0], &loop);
		loop++;
	}
	return (0);
}
