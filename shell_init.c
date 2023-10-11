#include "shell.h"

/**
 * main - A function that runs our shell.
 * @ac: The number of inputed arguments.
 * @av: The pointer to array of inputed arguments.
 * @env: The pointer to array of enviromental variables.
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL, **func = NULL;
	size_t buf_size = 0;
	ssize_t chars_readed = 0;
	int circle = 0;
	(void)ac;

	while (1)
	{
		circle++;
		prompt();
		signal(SIGINT, handle);
		chars_readed = getline(&buffer, &buf_size, stdin);
		if (chars_readed == EOF)
			_EOF(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			func = token(buffer, " \0");
			free(buffer);
			if (_strcmp(func[0], "exit") != 0)
				shell_exit(func);
			else if (_strcmp(func[0], "cd") != 0)
				change_dir(func[1]);
			else if (_strcmp(func[0], "echo") != 0 && _strcmp(func[1], "$$") != 0)
				_echo();
			else if (_strcmp(func[0], "echo") != 0 && _strcmp(func[1], "$?") != 0)
				_echo_zero();
			else if (_strcmp(func[0], "echo") != 0 && _strcmp(func[1], "$PATH") != 0)
				_echo_path();
			else
				create_child(func, av[0], env, circle);
		}
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (chars_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


/**
 * prompt - A function that prints the prompt
 * Return: Nothing.
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "{simple_shell}>> ", 16);
}


/**
 * handle - A function to handle Ctr + C signal.
 * @signals: The signal to handle.
 * Return: Nothing.
 */
void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\n{simple_Shell}>> ", 16);
}


/**
 * _EOF - A function that chaecks if buffer is EOF
 * @buffer: The pointer to the input string.
 * Return: Nothing
 */
void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}


/**
 * shell_exit - A function that exits the shell.
 * @func: The pointer to tokenized func.
 * Return: Nothing.
 */
void shell_exit(char **func)
{
	int sta_tus = 0;

	if (func[1] == NULL)
	{
		free_dp(func);
		exit(EXIT_SUCCESS);
	}

	sta_tus = _stringint(func[1]);
	if (sta_tus == -1)
	{
		_printstring("Invalid exit status");
		free_dp(func);
		exit(EXIT_FAILURE);
	}

	free_dp(func);
	exit(sta_tus);
}
