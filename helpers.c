#include "main.h"

/**
 * init_bufff - Initialize the buffer and handle error
 *
 * Return: the created buffer if successful, NULL otherwise
 */
buf *init_buff()
{
	buf *my_buffer = malloc(sizeof(buf));

	if (!my_buffer)
		return (NULL);

	my_buffer->final_str = malloc(1024 * sizeof(char));

	if (!my_buffer->final_str)
	{
		free(my_buffer);
		return (NULL);
	}

	my_buffer->head = my_buffer->final_str;
	my_buffer->count = 0;
	my_buffer->tmp = 0;

	return (my_buffer);
}

/**
 * update_buff - update the buffer and/or reset buffer if full
 *
 * @my_buffer: the buffer
 * @value: value to add to buffer
 */
void update_buff(buf *my_buffer, char value)
{
	if (my_buffer->tmp == 1024)
	{
		write(STDOUT_FILENO, my_buffer->head, my_buffer->tmp);
		my_buffer->final_str = my_buffer->head;
		my_buffer->tmp = 0;
	}

	*(my_buffer->final_str) = value;
	(my_buffer->count)++;
	(my_buffer->tmp)++;
	(my_buffer->final_str)++;
}

/**
 * cleanup_buff - free all allocated memory to buff
 *
 * @my_buffer: buffer to clean up
 */
void cleanup_buff(buf *my_buffer)
{
	free(my_buffer->head);
	free(my_buffer);
}

/**
 * get_int_len - Get the length of an integer
 *
 * @value: integer to evaluate
 * Return: leength of the integer
 */
int get_int_len(int value)
{
	int len = 1;

	while (value > 9)
	{
		len++;
		value /= 10;
	}

	return (len);
}
