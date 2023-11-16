#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

extern char **env;

char *rcom(void);
int _putchar(char c);
char **incoommand(char *l);
void f_array(char **a);
void print_environment(void);
int exit_com(char **com, char **argv, int i);
void p_error(char *n, char *com, int i);
char *_it(int in);
char *get_path(char *com);
#endif
