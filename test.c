#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct buff {
	char *buff;
	char *head;
	unsigned int count;
} buff;

int print_var(char *format, ...);
void handler(buff *my_buff, char *specifier, va_list args, int *parsed_chars);

// typedef struct handler {
// 	char specifier;
// 	void (*op)(buff*, va_list);
// } handler;

/**
 * @brief main func
 *
 * @return int
 */
int main(void)
{
	// int count = print_var("How do the rich eat their bread these days?");
	int count = print_var("How do the %s eat their %s these days?", "rich", "bread");
	printf("\ncount: %d\n", count);
	return (0);
}

/**
 * @brief printf body
 *
 * @param format
 * @param ...
 * @return int
 */
int print_var(char *format, ...)
{
	int parsed_chars;
	char *tmp = format;
	buff *my_buffer = malloc(sizeof(buff));

	my_buffer->buff = malloc(1024);
	my_buffer->head = my_buffer->buff;
	my_buffer->count = 0;

	va_list args;
	va_start(args, format);

	while (*tmp)
	{
		parsed_chars = 0;

		if (*tmp == '%')
		{
			handler(my_buffer, tmp+1, args, &parsed_chars);
			tmp += parsed_chars;
			// continue;
		}
		else
		{
			*(my_buffer->buff) = *tmp;
			(my_buffer->count)++;
			(my_buffer->buff)++;
		}

		tmp++;
	}
	write(STDOUT_FILENO, my_buffer->head, my_buffer->count);
	// free();
	return (my_buffer->count);
}

void handler(buff* my_buff, char* specifier, va_list args, int *parsed_chars)
{
	if (*specifier == 's')
	{
		char *value = va_arg(args, char*);
		while (*value)
		{
			*(my_buff->buff) = *value;
			(my_buff->count)++;
			(my_buff->buff)++;
			value++;
		}

		(*parsed_chars) += 1;
	}
}
