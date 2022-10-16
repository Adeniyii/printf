#include "main.h"

/**
 * init_bufff - Initialize the buffer and handle error
 *
 * Return: the created buffer if successful, NULL otherwise
 */
buf *init_buff()
{
	const int BUF_SIZE = 1024;
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
