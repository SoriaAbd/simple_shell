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
