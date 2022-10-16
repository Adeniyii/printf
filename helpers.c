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

	my_buffer->final_str = malloc(BUF_SIZE * sizeof(char));

	if (!my_buffer->final_str)
	{
		free(my_buffer);
		return (NULL);
	}

	my_buffer->head = my_buffer->final_str;
	my_buffer->count = 0;

	return (my_buffer);
}

/**
 * update_buff - update the buffer and/or rerset buffer if full
 *
 * @my_buffer: the buffer
 * @value: value to add to buffer
 */
void update_buff(buf *my_buffer, char value)
{
	if (my_buffer->count >= BUF_SIZE)
	{
		write(STDOUT_FILENO, my_buffer->head, my_buffer->count);
		my_buffer->final_str = my_buffer->head;
		my_buffer->count = 0;
	}

	*(my_buffer->final_str) = value;
	(my_buffer->count)++;
	(my_buffer->final_str)++;
}
