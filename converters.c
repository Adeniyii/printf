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

/**
 * convert_int - handler for string `%d` specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 * Return: (-1) if error, (0) otherwise
 */
int convert_int(buf *my_buffer, va_list args, int *parsed_chars)
{
	int value = va_arg(args, int);
	int i;
	char num[] = "0123456789";
	char hold[50];
	char *ptr;

	ptr = &hold[49];
	*ptr = '\0';


	while (value != 0)
	{
		*--ptr = num[value % 10];
		value /= 10;
	}

	while (*ptr)
	{
		update_buff(my_buffer, *ptr);
		ptr++;
	}

	(*parsed_chars) += 1;
	return (0);
}
