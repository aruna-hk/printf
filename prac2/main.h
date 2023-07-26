#ifndef _MAIN_H
#define _MAIN_H
#include <unistd.h>
#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>
char *hex_convert(unsigned int num, char id);
int _printf(const char *format, ...);
void change_caps_small(char *point);
char *out_side_call(char s, va_list v);
int _putchar(char c);
void rev_string(char *start, int st_len);
char *int_to_string(int num);
char *uint_to_string(unsigned int num);
void _strcpy(char *dest, char *src);
int _strlen(char *s);
char *uint_to_octal(unsigned int number);
char *check_and_alloc(char s, va_list l);
#endif
