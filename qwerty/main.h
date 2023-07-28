#ifndef _MAIN_H
#define _MAIN_H
#include <unistd.h>
#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int _putchar(char c);
void rev_string(char *start, int st_len);
char *convert_to_hex(unsigned long num_v);
void percent(const char *string);
void write_f(char *buf);
int _isalpha(int c);
void change_caps_small(char *point);
char *int_to_string(int num);
char *uint_to_string(unsigned int num);
char *hex_convert(unsigned int num, char id);
void change_caps_small(char *point);
char *out_call(char v, va_list vv);
void _strcpy(char *dest, char *src);
 void change_caps_small(char *point);
int _strlen(char *s);
char *uint_to_octal(unsigned int number);
char *check_and_alloc(char s, va_list l);
#endif
