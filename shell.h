#ifndef SHELL_H
#define SHELL_H
#define TOK_BUF 64
#define DELIMS " \t\r\n\a"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
/* helper functions for string manipulation */
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
/* handles printing of prompt and parsing user input to the shell */
void print_prmpt(char *prmpt);
char *get_input(void);
char **parse(char *input);
/* executes commands */
void forkcheck_f(pid_t child, char *input);
void execute_cmd(char **argv, char *arv0, char *line, int *status,
                     char *c);
/* checks and selects interactive or non-interactive mode */
void check_mode(char *av0, int *i);
/* handles the path of the command inputed */
char *pathfinder(char *command);
char *fpath_cmd(char *cmd);
void error_clean(int *i, char *av0, char *input, char **argv, int *status);
/* helper functions for builtin commands */
int number_builtins(void);
int builtin_cmds(int *i, char **argv, char *input, char *av0, int *status);
int num_builtins_error(void);
/* helper functions, custom implementation of  impermissible functions */
char *_memset(char *s, char b, unsigned int n);
char *itoa(int i, char b[]);
int _atoi(const char *str);
/* builtin functions declarations */
int _cd(char **args, char *input, int *status);
int _exxit(char **argv, char *input, int *status);
int _env(char **args, char *input, int *status);
int _setenv(char **args, char *input, int *status);
int _unsetenv(char **args, char *input, int *status);

/* builtin error messages */
void cd_error(int *i, char *av0, char *input, char **argv, int *status);
void exit_error(int *i, char *av0, char *input, char **argv, int *status);
void env_error(char *input, char **argv, int *status);
void setenv_error(int *i, char *av0, char *input, char **argv, int *status);
void unsetenv_error(int *i, char *av0, char *input, char **argv, int *status);
#endif /* MAIN_H */
