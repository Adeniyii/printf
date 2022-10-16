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
	const int BUF_SIZE = 1024;
	int parsed_chars, tmp_count;
	char *tmp = (char *)format;
	buf *my_buffer = malloc(sizeof(buf));

	my_buffer->final_str = malloc(BUF_SIZE * sizeof(char));
	my_buffer->head = my_buffer->final_str;
	my_buffer->count = 0;

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
			*(my_buffer->final_str) = *tmp;
			(my_buffer->count)++;
			(my_buffer->final_str)++;
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
