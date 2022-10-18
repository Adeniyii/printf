#include "main.h"

/**
 * specifier_handler - defines list of specifiers to handler map
 * and executes the handler mamtching the `specifier` argument.
 *
 * @my_buffer: struct holding the final string and count
 * @specifier: the given specifier char
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 * Return: (0) on success (-1) on failure
 */
int specifier_handler(buf *my_buffer,
		      char *specifier, va_list args, int *parsed_chars)
{
	int i = 0;
	int converter_ret = 0;

	specifier_map specifier_list[] = {
		{'c', convert_char},
		{'s', convert_str},
		{'%', convert_percent},
		{'d', convert_int},
		{'i', convert_int},
		{'u', convert_unsint},
		{'b', convert_bin},
		{'o', convert_oct},
		{'x', convert_hex},
		{'X', convert_hexa},
		{'\0', NULL}};

	while (specifier_list[i].specifier)
	{
		if (specifier_list[i].specifier == *specifier)
		{
			converter_ret = specifier_list[i].op(my_buffer, args, parsed_chars);
			return (converter_ret);
		}
		i++;
	}
	return (-1);
}
