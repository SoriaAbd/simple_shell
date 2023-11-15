#include "shell.h"
/*
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
	}
}
/*
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
