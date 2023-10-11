#include "shell.h"

/**
* checkbuild - checks if the command is a buildin
* @func: array of arguments
* Return: pointer to function that takes arv and returns void
*/
void(*checkbuild(char **func))(char **func)
{
	int i, j;
	mybuild T[] = {
		{"exit", exits},
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; T[i].name; i++)
	{
		j = 0;
		if (T[i].name[j] == func[0][j])
		{
			for (j = 0; func[0][j]; j++)
			{
				if (T[i].name[j] != func[0][j])
					break;
			}
			if (!func[0][j])
				return (T[i].func);
		}
	}
	return (0);
}

/**
 * _unsetenv - Remove an environment variable
 * @func: array of entered words
 */
void _unsetenv(char **func)
{
	int i, j;

	if (!func[1])
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
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}

/**
 * _echo - a function that checks echo $$ arg and prints pid
 */
void _echo(void)
{
	pid_t pid = getpid();
	int i = 0;
	char  pid_str[20];
	int j;

	do {
		pid_str[i++] = '0' + (pid % 10);
		pid /= 10;

	} while (pid > 0);
	for (j = i - 1; j >= 0; j--)
	{
		write(1, &pid_str[j], 1);
	}
	write(1, "\n", 1);
}

/**
 *_echo_zero - a function that checks echo $? arg and prints zero
 */
void _echo_zero(void)
{
	_printstring("0");
	_printstring("\n");
}

/**
 *_echo_path - a function that checks echo $PATH arg and prints path
 */
void _echo_path(void)
{
	char *path;
	ssize_t path_length;

	path = getenv("PATH");
	path_length = _strlen(path);
	write(1, path, path_length);
	write(1, "\n", 1);
}
