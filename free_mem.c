#include "shell.h"

/**
 * free_dp - A function that frees all the memory allocated for func.
 * @func: The pointer to allocated memory to free.
 * Return: Nothing.
 */
void free_dp(char **func)
{
	size_t i = 0;

	if (func == NULL)
		return;

	while (func[i])
	{
		free(func[i]);
		i++;
	}

	if (func[i] == NULL)
		free(func[i]);
	free(func);
}


/**
 * free_exit - A function that frees all the memory allocated and exit.
 * @func: The pointer to allocated func memory to free.
 * Return: Nothing.
 */
void free_exit(char **func)
{
	size_t i = 0;

	if (func == NULL)
		return;

	while (func[i])
	{
		free(func[i]);
		i++;
	}

	if (func[i] == NULL)
		free(func[i]);
	free(func);
	exit(EXIT_FAILURE);
}
