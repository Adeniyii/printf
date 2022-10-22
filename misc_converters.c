#include "main.h"

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
