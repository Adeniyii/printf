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

	do {
		i = value % 2;
		value = value / 2;
		*--ptr = num[i];
	} while (value != 0); /*converting value to base 2 and turn*/
	/* the number to string*/

	while (*ptr) /*sending ptr to buffer so it can be printed*/
	{
		update_buff(my_buffer, *ptr);
		ptr++;
	}


	(*parsed_chars) += 1;
	return (0);
}

/**
 * convert_oct - handler for string `%o` `%i`specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 * Return: (-1) if error, (0) otherwise
 */
int convert_oct(buf *my_buffer, va_list args, int *parsed_chars)
{
	unsigned int value = va_arg(args, unsigned int);
	char num[] = "0123456789";
	char hold[50];
	char *ptr;
	int i;

	ptr = &hold[49];
	*ptr = '\0';
	do {
		i = value % 8;
		value = value / 8;
		*--ptr = num[i];
	} while (value != 0); /*converting value to base 2 and turn*/
	/* the number to string*/

	while (*ptr) /*sending ptr to buffer so it can be printed*/
	{
		update_buff(my_buffer, *ptr);
		ptr++;
	}


	(*parsed_chars) += 1;
	return (0);
}
/**
 * convert_hex - handler for string `%x` `%i`specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 * Return: (-1) if error, (0) otherwise
 */

int convert_hex(buf *my_buffer, va_list args, int *parsed_chars)
{
	unsigned int value = va_arg(args, unsigned int);
	char num[] = "0123456789abcdef";
	char hold[50];
	char *ptr;
	int i;

	ptr = &hold[49];
	*ptr = '\0';

	do {
		i = value % 16;
		value = value / 16;
		*--ptr = num[i];
	} while (value != 0); /*converting value to base 2 and turn*/
	/* the number to string*/

	while (*ptr) /*sending ptr to buffer so it can be printed*/
	{
		update_buff(my_buffer, *ptr);
		ptr++;
	}


	(*parsed_chars) += 1;
	return (0);
}
/**
 * convert_hexa - handler for string `%X` `%i`specifier
 *
 * @my_buffer: struct holding the final string and count
 * @args: list of variable arguments
 * @parsed_chars: pointer to variable tracking the chars parsed
 * Return: (-1) if error, (0) otherwise
 */

int convert_hexa(buf *my_buffer, va_list args, int *parsed_chars)
{
	unsigned int value = va_arg(args, unsigned int);
	char num[] = "0123456789ABCDEF";
	char hold[50];
	char *ptr;
	int i;

	ptr = &hold[49];
	*ptr = '\0';

	do {
		i = value % 16;
		value = value / 16;
		*--ptr = num[i];
	} while (value != 0); /*converting value to base 2 and turn*/
	/* the number to string*/

	while (*ptr) /*sending ptr to buffer so it can be printed*/
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
	char hold[50], *ptr;
	int i, b;

	ptr = &hold[49];
	*ptr = '\0';
	if (value < 0)
	{
		for (b = 0; b < 16; b++)
		{
		*--ptr = num[15];
		}
		*--ptr = 'x';
		*--ptr = '0';
	} else if (value == 0)
	{
		*--ptr = ')';
		*--ptr = 'l';
		*--ptr = 'i';
		*--ptr = 'n';
		*--ptr = '(';
	} else
	{
	do {
		i = value % 16;
		value = value / 16;
		*--ptr = num[i];
	} while (value != 0); /*converting value to base 2 and turn*/
	/* the number to string*/
	*--ptr = 'x';
	*--ptr = '0';
	}
	while (*ptr) /*sending ptr to buffer so it can be printed*/
	{
		update_buff(my_buffer, *ptr);
		ptr++;
	}
	(*parsed_chars) += 1;
	return (0);
}
