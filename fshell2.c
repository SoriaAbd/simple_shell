#include "shell.h"

/**
 * get_env - show environment
 * @p: char
 * Return: char or null
 */

char *get_env(char *p)
{
	int x;
	char *buffer, *k, *v, *envo;

	for (x = 0; environ[x]; x++)
	{
		buffer = strdup(environ[x]);
		k = strtok(buffer, "=");
		if (strcmp(k, p) == 0)
	{
	v = strtok(NULL, "\n");
	envo = strdup(value);
	free(buffer);
	return (envo);
	}
	free(buffer);
	}
	return (NULL);
}
