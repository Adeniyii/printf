#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct buffer - a buffer entity
 * @head: pointer to first char of `final_str`
 * @final_str: final string to print
 * @count: number of bytes printed/to print
 */
typedef struct buffer
{
	char *head;
	char *final_str;
	unsigned int tmp;
	unsigned int count;
} buf;

/**
 * struct specifier_to_func_map - maps specifier string to handler function
 * @specifier: specifier value
 * @op: converter function for specifier
 */
typedef struct specifier_to_func_map
{
	char specifier;
	int (*op)(buf *, va_list, int *);
} specifier_map;

/* Function declarations */
buf *init_buff();
void cleanup_buff(buf *my_buffer);
int _printf(const char *format, ...);
void update_buff(buf *my_buffer, char value);
int init_printf(const char *format, buf *my_buffer, va_list args);
int convert_str(buf *my_buffer, va_list args, int *parsed_chars);
int convert_char(buf *my_buffer, va_list args, int *parsed_chars);
int convert_int(buf *my_buffer, va_list args, int *parsed_chars);
int convert_percent(buf *my_buffer, va_list args, int *parsed_chars);
int specifier_handler(buf *my_buffer,
		      char *specifier, va_list args, int *parsed_chars);
int convert_unsint(buf *my_buffer, va_list args, int *parsed_chars);
int convert_bin(buf *my_buffer, va_list args, int *parsed_chars);
int convert_oct(buf *my_buffer, va_list args, int *parsed_chars);
int convert_hex(buf *my_buffer, va_list args, int *parsed_chars);
int convert_hexa(buf *my_buffer, va_list args, int *parsed_chars);
#endif /* MAIN_H */
