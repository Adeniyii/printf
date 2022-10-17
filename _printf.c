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
	int tmp_count, printf_ret;

	if (!format)
		return (-1);

	my_buffer = init_buff();

	if (my_buffer == NULL)
		return (-1);

	va_start(args, format);

	printf_ret = init_printf(format, my_buffer, args);

	if (printf_ret < 0)
	{
		cleanup_buff(my_buffer);
		va_end(args);
		return (-1);
	}

	write(STDOUT_FILENO, my_buffer->head, my_buffer->count);
	tmp_count = my_buffer->count;
	cleanup_buff(my_buffer);
	va_end(args);

	return (tmp_count);
}

/**
 * init_printf - printf engine
 *
 * @format: format string
 * @my_buffer: buffer that holds final string and count
 * @args: variadic argument list
 * Return: the value of the handler function
 */
int init_printf(const char *format, buf *my_buffer, va_list args)
{
	char *tmp = (char *)format;
	int parsed_chars, handler_value;

	while (*tmp)
	{
		parsed_chars = 0;

		if (*tmp == '%')
		{
			handler_value = specifier_handler(my_buffer, tmp + 1, args, &parsed_chars);

			if (handler_value < 0)
				return (-1);

			tmp += parsed_chars;
		}
		else
		{
			update_buff(my_buffer, *tmp);
		}

		tmp++;
	}
	return (handler_value);
}
