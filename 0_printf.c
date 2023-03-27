#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Prints output to stdout according to a format.
 * @format: A pointer to a string that contains a format string.
 *
 * Return: The number of characters printed (excluding the null byte used to
 * terminate output to strings).
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *p = NULL;
	int count = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	for (p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;

			switch (*p)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _print_string(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(*p);
					break;
			}
		}
		else
			count += _putchar(*p);
	}

	va_end(args);

	return (count);
}

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to write.
 *
 * Return: The number of characters written (always 1).
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_string - Writes a string to stdout.
 * @str: The string to write.
 *
 * Return: The number of characters written.
 */
int _print_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str != '\0')
	{
		count += _putchar(*str);
		str++;
	}

	return (count);
}
