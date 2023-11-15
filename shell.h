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

#endif
