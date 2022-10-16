#include "main.h"

/**
 * convert_char - handler for char `%c` specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 */
void convert_char(buf *my_buffer, va_list args, int *parsed_chars)
{
	char value = va_arg(args, int);

	*(my_buffer->final_str) = value;
	(my_buffer->count)++;
	(my_buffer->final_str)++;

	(*parsed_chars) += 1;
}

/**
 * convert_percent - handler for percent `%%` specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 */
void convert_percent(buf *my_buffer, __attribute__((unused)) va_list args, int *parsed_chars)
{
	update_buff(my_buffer, '%');

	(*parsed_chars) += 1;
}

/**
 * convert_str - handler for string `%s` specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 */
void convert_str(buf *my_buffer, va_list args, int *parsed_chars)
{
	char *value = va_arg(args, char *);

	while (*value)
	{
		update_buff(my_buffer, *value);
		value++;
	}

	(*parsed_chars) += 1;
}
