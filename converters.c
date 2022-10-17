#include "main.h"

/**
 * convert_char - handler for char `%c` specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 * Return: (-1) if error, (0) otherwise
 */
int convert_char(buf *my_buffer, va_list args, int *parsed_chars)
{
	char value = va_arg(args, int);

	printf("value: %c\n", value);

	if (!value)
		return (-1);

	*(my_buffer->final_str) = value;
	(my_buffer->count)++;
	(my_buffer->final_str)++;

	(*parsed_chars) += 1;

	return (0);
}

/**
 * convert_percent - handler for percent `%%` specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 * Return: (-1) if error, (0) otherwise
 */
int convert_percent(buf *my_buffer,
		    __attribute__((unused)) va_list args, int *parsed_chars)
{
	update_buff(my_buffer, '%');

	(*parsed_chars) += 1;

	return (0);
}

/**
 * convert_str - handler for string `%s` specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 * Return: (-1) if error, (0) otherwise
 */
int convert_str(buf *my_buffer, va_list args, int *parsed_chars)
{
	char *value = va_arg(args, char *);

	if (value == NULL)
		return (-1);

	while (*value)
	{
		update_buff(my_buffer, *value);
		value++;
	}

	(*parsed_chars) += 1;

	return (0);
}
