#include "main.h"

/**
 * _put - function that prints out strings.
 * @str: string character.
 *
 * Return: count of the string.
 */

int _put(char *str)
{
	int i = 0;
	int r_val = 0;

	if (str)
	{
		while (str[i] != '\0')
		{
			_pucha(str[i]);
			r_val += 1;
			i++;
		}
	}
	return (r_val);
}
