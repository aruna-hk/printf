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
void rev_string(char *start);
char *int_to_string(int num);
char *uint_to_string(unsigned int num);
void _strcpy(char *dest, char *src);
int _strlen(char *s);
char *uint_to_octal(unsigned int number);
char *check_and_alloc(char s, va_list l);
#endif
