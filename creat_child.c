#include "shell.h"

/**
 * create_child - A function that creates a sub process.
 * @func: The pointer to tokenized func
 * @name: The pointer to the name of shell.
 * @env: The pointer to the enviromental variables.
 * @circle: Number of executed circle.
 * Return: Nothing.
 */
void create_child(char **func, char *name, char **env, int circle)
{
	int pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_exit(func);
	}
	else if (pid == 0)
	{
		execute(func, name, env, circle);
		free_dp(func);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			free_exit(func);
		}
		free_dp(func);
	}
}


/**
  * change_dir - Afunction that changes working directory.
  * @path: The new current working directory.
  * Return: 0 on success, -1 on failure.
  */
int change_dir(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}
