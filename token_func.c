#include "shell.h"

/**
 * token - A function that split and create a full string command.
 * @s: The delimiter for strtok.
 * @buffer: The pointer to input string.
 * Return: A string with full command.
 */
char **token(char *buffer, const char *s)
{
	char *token = NULL, **func = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	bufsize = _strlen(buffer);
	func = malloc((bufsize + 1) * sizeof(char *));
	if (func == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		free_dp(func);
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, s);
	while (token != NULL)
	{
		func[i] = malloc(_strlen(token) + 1);
		if (func[i] == NULL)
		{
			perror("Unable to allocate buffer");
			free_dp(func);
			return (NULL);
		}
		_strcpy(func[i], token);
		token = strtok(NULL, s);
		i++;
	}
	func[i] = NULL;
	return (func);
}
