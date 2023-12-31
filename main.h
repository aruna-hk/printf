#ifndef _3_CALC_H
#define _3_CALC_H
#include <stddef.h>
#include <string.h>
#include "unistd.h"
#include <stdarg.h>
#include <stdlib.h>
/**
* struct op - Struct op
* @op: The operator
* @f: The function associated
*/
typedef struct op
{
	char *op;
	int (*f)(char *, va_list);
} op_t;

int (*get_op_func(char s))(char *, va_list);
int _printf(const char *format, ...);
void buffer_set(char *arr, char *buffer, char s);
void append_to_buffer(char *buffer_s, va_list ss, char p);
void e_xit(const char *pp);
void _strcat(char *dest, char *src);
void _sstrcat(char *dest, char *src);
char *uint_to_octal(unsigned long int number);
char *uint_to_string(unsigned long int num);
char *_memset(char *s, char b, unsigned int n);
void change_caps_small(char *point);
char *hex_convert(unsigned int num);
void rev_string(char *start, int st_len);
int _strlen(const char *s);
void _strcpy(char *dest, char *src);
void write_function(char *buf);
int _strcmp(char *s1, char *s2);
char *int_to_string(int num);
int identifier_b(char *buffer, va_list list);
int identifier_d(char *buffer, va_list list);
int identifier_c(char *buffer, va_list list);
int identifier_s(char *buffer, va_list list);
int identifier_S(char *buffer, va_list list);
int identifier_p(char *buffer, va_list list);
int identifier_u(char *buffer, va_list list);
int identifier_o(char *buffer, va_list list);
int identifier_x(char *buffer, va_list list);
int identifier_X(char *buffer, va_list list);
int identifier_f(char *buffer, va_list list);
#endif
