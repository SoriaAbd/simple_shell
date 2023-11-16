#include "shell.h"
/**
 * incoommand - input commands function
 * @l:line char
 * Return:char
 */
char **incoommand(char *l)
{
	char *a, char *t;/*array and toen*/
	char *buffer;
	int i;/*index*/

	if (!l)
		return (NULL);
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

	comand = get_path(com[0]);
	if (!comand)
	{
		p_error(argv[0], com[0], i);
		f_array(com);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(comand, com, env) == -1)
		{
			free(comand);
			f_array(com);
		}
	}
	else
	{
		waitpid(child, &s, 0);
		f_array(com);
		free(comand);
	}
	return (WEXITSTATUS(s));
}
/**
 * p_error - print a massage
 * @n: name char
 * @com: command char
 * @i: index int
 * Return: void
*/

void p_error(char *n, char *com, int i)
{
	char *x, massage[] = ": not found\n";

	x = _it(i);
	write(STDERR_FILENO, n, strlen(n));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, x, strlen(x));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, com, strlen(com));
	write(STDERR_FILENO, msg, strlen(massage));
	free(x);
}
/**
 * _it - change int to string
 * @in:int
 * Return:a string
*/

char *_it(int in)
{
	char buffer[20];
	int index = 0;

	if (in == 0)
		buffer[index++] = '0';
	else
	{
		while (in > 0)
		{
			buffer[index++] = (in % 10) + '0';
			in /= 10;
		}
	}
	buffer[index] = '\0';
	strrev(buffer, index);
	return (strcpy(buffer));
}
