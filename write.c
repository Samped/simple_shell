#include "shell.h"

/**
 * _putchar - A function that prints a char
 * @c:  a char
 * Return: a char
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printstring - A function that prints a string
 * @str: a string of char
 * Return: The string
*/

int _printstring(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		count += _putchar(str[i++]);
	}
	return (count);
}
