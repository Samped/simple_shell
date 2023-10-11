#include "shell.h"

/**
 * execute - A function that executes a func.
 * @func: The pointer to tokienized func
 * @name: The name of the shell.
 * @env: The pointer to the enviromental variables.
 * @cirle: Number of executed cirle.
 * Return: Nothing.
 */
void execute(char **func, char *name, char **env, int cirle)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(func[0], "env") != 0)
		print_env(env);
	if (stat(func[0], &st) == 0)
	{
		if (execve(func[0], func, env) < 0)
		{
			perror(name);
			free_exit(func);
		}
	}
	else
	{
		pathways = _get_path(env);
		while (pathways[i])
		{
			full_path = _strcat(pathways[i], func[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, func, env) < 0)
				{
					perror(name);
					free_dp(pathways);
					free_exit(func);
				}
				return;
			}
		}
		msgerror(name, cirle, func);
		free_dp(pathways);
	}
}


/**
 * print_env - A function that prints all enviromental variables.
 * @env: The pointer to enviromental variables.
 * Return: Nothing.
 */
void print_env(char **env)
{
	size_t i = 0, len = 0;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}


/**
 * _get_path - A function to gets the full value from.
 * enviromental variable PATH.
 * @env: The pointer to enviromental variables.
 * Return: All tokenized pathways for funcs.
 */
char **_get_path(char **env)
{
	char *pathvalue = NULL, **pathways = NULL;
	unsigned int i = 0;

	pathvalue = strtok(env[i], "=");
	while (env[i])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathways = token(pathvalue, ":");
			return (pathways);
		}
		i++;
		pathvalue = strtok(env[i], "=");
	}
	return (NULL);
}


/**
 * msgerror - A function that prints message not found.
 * @name: The name of the shell.
 * @cirle: Number of cirle.
 * @func: The pointer to tokenized func.
 * Return: Nothing.
 */
void msgerror(char *name, int cirle, char **func)
{
	char c;

	c = cirle + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, func[0], _strlen(func[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
