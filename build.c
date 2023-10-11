#include "shell.h"

/**
 * exits - exits the shell with or without a return of status n
 * @func: array of words of the entered line
 */
void exits(char **func)
{
	int i, n;

	if (func[1])
	{
		n = _stringint(func[1]);
		if (n <= -1)
			n = 2;
		free_exit(func);
		exit(n);
	}
	for (i = 0; func[i]; i++)
		free(func[i]);
	free(func);
	exit(0);
}

/**
 * env - prints the current environment
 * @func: array of arguments
 */
void env(char **func __attribute__ ((unused)))
{

	int i;

	for (i = 0; environ[i]; i++)
	{
		_printstring(environ[i]);
		_printstring("\n");
	}

}

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @func: array of entered words
 */
void _setenv(char **func)
{
	int i, j, k;

	if (!func[1] || !func[2])
	{
		perror(_getenv("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (func[1][j] == environ[i][j])
		{
			while (func[1][j])
			{
				if (func[1][j] != environ[i][j])
					break;

				j++;
			}
			if (func[1][j] == '\0')
			{
				k = 0;
				while (func[2][k])
				{
					environ[i][j + 1 + k] = func[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{

		environ[i] = _strcat_all(func[1], "=", func[2]);
		environ[i + 1] = '\0';

	}
}

/**
 * _getenv - gets the value of the global variable
 * @name: name of the global variable
 * Return: string of value
 */
char *_getenv(const char *name)
{
	int i, j;
	char *value;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;

				j++;
			}
			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (0);
}

/**
 * _strcat_all - concats 3 strings in a newly allocated memory
 * @name: first string
 * @sep: second string
 * @value: Third string
 * Return: pointer to the new string
 */
char  *_strcat_all(char *name, char *sep, char *value)
{
	char *result;
	int l1, l2, l3, i, k;

	l1 = _strlen(name);
	l2 = _strlen(sep);
	l3 = _strlen(value);

	result = malloc(l1 + l2 + l3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}
