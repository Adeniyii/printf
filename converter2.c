#include "main.h"

/**
 * convert_bin - handler for string `%b` `%i`specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 * Return: (-1) if error, (0) otherwise
 */
int convert_bin(buf *my_buffer, va_list args, int *parsed_chars)
{
	unsigned int value = va_arg(args, unsigned int);
	char num[] = "01";
	char hold[50];
	char *ptr;
	int i;

	ptr = &hold[49];
	*ptr = '\0';

	while (value != 0) /*converting value to base 2 and turn*/
	/* the number to string*/
	{
		i = value % 2;
		value = value / 2;
		*--ptr = num[i];
	}

	while (*ptr) /*sending ptr to buffer so it can be printed*/
	{
		update_buff(my_buffer, *ptr);
		ptr++;
	}


	(*parsed_chars) += 1;
	return (0);
}
