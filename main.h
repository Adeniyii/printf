#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * struct buffer - a buffer entity
 * @head: pointer to first char of `final_str`
 * @final_str: final string to print
 * @count: number of bytes printed/to print
 * @tmp: buffer size monitor printed/to print
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
int get_int_len(int value);
void cleanup_buff(buf *my_buffer);
int _printf(const char *format, ...);
void update_buff(buf *my_buffer, char value);
int recursively_add_to_buffer(int len, int val, buf *my_buffer);
int init_printf(const char *format, buf *my_buffer, va_list args);
int convert_str(buf *my_buffer, va_list args, int *parsed_chars);
int convert_char(buf *my_buffer, va_list args, int *parsed_chars);
int convert_int(buf *my_buffer, va_list args, int *parsed_chars);
int convert_percent(buf *my_buffer, va_list args, int *parsed_chars);
int specifier_handler(buf *my_buffer,
		      char *specifier, va_list args, int *parsed_chars);
int convert_uint(buf *my_buffer, va_list args, int *parsed_chars);
int convert_bin(buf *my_buffer, va_list args, int *parsed_chars);
int convert_oct(buf *my_buffer, va_list args, int *parsed_chars);
int convert_hex(buf *my_buffer, va_list args, int *parsed_chars);
int convert_hexa(buf *my_buffer, va_list args, int *parsed_chars);
int convert_addr(buf *my_buffer, va_list args, int *parsed_chars);
#endif /* MAIN_H */
