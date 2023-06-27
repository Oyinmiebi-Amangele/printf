#include "main.h"

/**
 * cmp_func - Entry point.
 * @b: character.
 *
 * Return: 0.
 */

int (*cmp_func(const char b))(va_list)
{
	print_f printf[] = {
		{'c', printc},
		{'s', print_str},
		{'d', print_n},
		{'i', print_n},
		{'\0', NULL}
	};

	int r;

	for (r = 0; printf[r].ptr != '\0'; r++)
	{
		if (printf[r].ptr == b)
		{
			return (printf[r].func);
		}
	}

	return (0);
}
