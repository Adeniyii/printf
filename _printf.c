#include "main.h"

/**
 * _printf - prints a format string
 *
 * @format: string to print
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	buf *my_buffer;
	int parsed_chars, tmp_count;
	char *tmp = (char *)format;

	if (!format)
		return (-1);

	my_buffer = init_buff();

	if (!my_buffer)
		return (-1);

	va_start(args, format);

	while (*tmp)
	{
		parsed_chars = 0;

		if (*tmp == '%')
		{
			specifier_handler(my_buffer, tmp + 1, args, &parsed_chars);
			tmp += parsed_chars;
		}
		else
		{
			update_buff(my_buffer, *tmp);
		}

		tmp++;
	}
	write(STDOUT_FILENO, my_buffer->head, my_buffer->count);
	tmp_count = my_buffer->count;
	free(my_buffer->head);
	free(my_buffer);
	va_end(args);

	return (tmp_count);
}
