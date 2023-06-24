#include "main.h"

/**
 * _pucha - function that prints out a
 * character to the standard output.
 * @t: input character.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno
 * is set appropriately.
 */

int _pucha(char t)
{
	return (write(1, &t, 1));
}
