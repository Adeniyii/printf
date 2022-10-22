#include "main.h"

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
		do
		{
			*--ptr = num[value % 10];
			value /= 10;
		} while (value != 0);
		*--ptr = '-';
	}
	else
	{
		do
		{

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
 * convert_uint - handler for string `%u` `%i`specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 * Return: (-1) if error, (0) otherwise
 */
int convert_uint(buf *my_buffer, va_list args, int *parsed_chars)
{
	unsigned int value = va_arg(args, unsigned int);
	char num[] = "0123456789";
	char hold[50];
	char *ptr;

	ptr = &hold[49];
	*ptr = '\0';

	do
	{
		*--ptr = num[value % 10];
		value /= 10;
	} while (value != 0);

	while (*ptr)
	{
		update_buff(my_buffer, *ptr);
		ptr++;
	}

	(*parsed_chars) += 1;
	return (0);
}

/**
 * convert_addr - handler for string `%p` `%i`specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 * Return: (-1) if error, (0) otherwise
 */
int convert_addr(buf *my_buffer, va_list args, int *parsed_chars)
{
	long int value = va_arg(args, long int);
	char num[] = "0123456789abcdef";
	char hold[50];
	char *ptr;
	int i;

	ptr = &hold[49];
	*ptr = '\0';

	while (value != 0) /*converting value to base 2 and turn*/
	/* the number to string*/
	{
		i = value % 16;
		value = value / 16;
		*--ptr = num[i];
	}
	*--ptr = 'x';
	*--ptr = '0';

	while (*ptr) /*sending ptr to buffer so it can be printed*/
	{
		update_buff(my_buffer, *ptr);
		ptr++;
	}

	(*parsed_chars) += 1;
	return (0);
}
