#include "shell.h"
/**
 * main - main function
 * @argc: num of argument
 * @argv: list of argument
 * Return:intger
 */
int main(int argc, char **argv)
{
	int i = 0, s = 0;/*i for index and s for status*/
	char **com, *l = NULL;/*command and line*/
	(void)argc;

	while (1)
	{
		l = rcom();/*for read the command line*/
		if (l == NULL)
		{
			if (isatty(STDIN_FILENO))
				_putchar("\n");
			return (s);
		}
		i++;
		com = incommand(l);
		if (!com)
			continue;
		if (strcmp(com[0], "exit") == 0)
		{
			f_array(com);/*to free array*/
			return (s);
		}
		else if (strcmp(com[0], "env") == 0)
		{
			print_environment();
			f_array(com);
		}
		else
			s = exit_com(com, argv, i);/*exit command*/
	}
}
/**
 * rcom - function to read the command line
 * Return: line
 */
char *rcom(void)
{
	size_t l_size = 0;
	ssize_t k;
	char *l = NULL;

	if (isatty(STDIN_FILENO))
		_putchar("#cisfun$ ");

	k = getline(&l, &l_size, stdin);
	if (k == -1)
	{
		free(l);
		return (NULL);
	}
	return (l);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
