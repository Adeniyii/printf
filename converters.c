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

	update_buff(my_buffer, value);

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
 * convert_int - handler for string `%d` `%i`specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 * Return: (-1) if error, (0) otherwise
 */
int convert_int(buf *my_buffer, va_list args, int *parsed_chars)
{
	int fig, value = va_arg(args, int);
	char num[] = "0123456789", hold[50], *ptr;

	ptr = &hold[49];
	*ptr = '\0';
	if (value < 0)
	{
		if (value == INT_MIN)
		{
			fig = value % 10;
			fig *= -1;
			value = value / 10;
			*ptr = num[fig];
		}
		value *= -1;
		do {
			*--ptr = num[value % 10];
			value /= 10;
		} while (value != 0);
		*--ptr = '-';
	} else
	{
		do {

			*--ptr = num[value % 10];
			value /= 10;
		} while (value != 0);
	}
	while (*ptr)
	{
		update_buff(my_buffer, *ptr);
		ptr++;
	}
	(*parsed_chars) += 1;
	return (0);
}

/**
 * convert_unsint - handler for string `%u` `%i`specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 * Return: (-1) if error, (0) otherwise
 */
int convert_unsint(buf *my_buffer, va_list args, int *parsed_chars)
{
	unsigned int value = va_arg(args, unsigned int);
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
