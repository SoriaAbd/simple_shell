#include "shell.h"
/**
 * incommand - input commands function
 * @l:line char
 * Return:char
 */
char **incoommand(char *l)
{
	char *a,char *t;/*array and toen*/
	char *buffer;
	int i;/*index*/

	if (!l)
		return(NULL);
	 buffer = strcpy(l);
        t = strtok(buffer, " \t\n");
        if (!t)
        {
                free(l);
                free(buffer);
                return (NULL);
        }
        for (i = 0; t; i++)
        t = strtok(NULL, " \t\n");
        free(buffer);
        a = malloc(sizeof(char *) * (i + 1));
        if (!a)
        {
        free(l);
        return (NULL);
        }
        t = strtok(l, " \t\n");
        for (i = 0; t; i++)
        {
        a[i] = strcpy(t);
        t = strtok(NULL, " \t\n");
	}
	free(l);
	a[i] = NULL;
	return (a);
}
/**
 * print_environment - print a stander shell
 * Return: void
*/

void print_environment(void)
{
	int x;

	for (x = 0; env[x]; x++)
	{
		_putchar(env[x]);
		_putchar("\n");
	}
}

/**
 * exit_com - exit from command system
 * @com: command line
 * @argv: command char
 * @i: index
 * Return: int
*/

int exit_com(char **com, char **argv, int i)
{
	int s;/*ststus*/
	pid_t child;
	char *comand;

	comand = _getpath(com[0]);
	if (!comand)
	{
		printerror(argv[0], com[0], i);
		f_array(com);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(comand, com, env) == -1)
		{
			free(comand);
			freearray(com);
		}
	}
	else
	{
		waitpid(child, &s, 0);
		freearray(com);
		free(comand);
	}
	return (WEXITSTATUS(s));
}
