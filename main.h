#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define BUF_SIZE 1024

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
	unsigned int count;
} buf;

/**
 * struct specifier_to_func_map - maps specifier string to handler function
 * @head: pointer to first char of `final_str`
 * @final_str: final string to print
 * @count: number of bytes printed/to print
 */
typedef struct specifier_to_func_map
{
	char specifier;
	void (*op)(buf *, va_list, int *);
} specifier_map;

/* Function declarations */
buf *init_buff();
int _printf(const char *format, ...);
void update_buff(buf *my_buffer, char value);
void convert_str(buf *my_buffer, va_list args, int *parsed_chars);
void convert_char(buf *my_buffer, va_list args, int *parsed_chars);
void convert_percent(buf *my_buffer, va_list args, int *parsed_chars);
void specifier_handler(buf *my_buffer, char *specifier, va_list args, int *parsed_chars);

#endif /* MAIN_H */
