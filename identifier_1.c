#include "main.h"
/**
* identifier_d - handle d and i identifiers
* convert to string and copy to buffer
* @buffer: to copy int to
* @list: variable list of the variadic function
* Return: 1/o 1-sucess 0 -failuer
*/
int identifier_d(char *buffer, va_list list)
{
	int n;
	char *to_string;

	n = va_arg(list, int);
	to_string = int_to_string(n);
	_strcat(buffer, to_string);
	free(to_string);
	return (1);
}
/**
* identifier_c -- handles character identifier
* @buffer: to copy character to
* @list: variable arguement list
* Return: 1- sucee o -failure
*/
int identifier_c(char *buffer, va_list list)
{
	char c;
	char arr[2];

	c = va_arg(list, int);
	arr[0] = c;
	arr[1] = '\0';
	_strcat(buffer, arr);
	return (1);
}
/**
* identifier_s - handles insertion of intergers
* @buffer: to copy string to
* @list: variable list
* Return: 1 if sucess or 0 failure
*/
int identifier_s(char *buffer, va_list list)
{
	char *from = va_arg(list, char *);

	_strcat(buffer, from);
	return (1);
}
/**
* identifier_u - handle octal
* @buffer: -- to copy unsigned uint to
* @list: variable list
* Return: 1-sucess ,0 failure
*/
int identifier_u(char *buffer, va_list list)
{
	unsigned int q;
	char *uq;

	q = va_arg(list, unsigned int);
	uq = uint_to_string(q);
	_strcat(buffer, uq);
	free(uq);
	return (1);
}
/**
* identifier_o - octal identifier
* @buffer: to append octal number
* @list: variables list of variadic function;
* Return: 1-sucess o -failure;
*/
int identifier_o(char *buffer, va_list list)
{
	unsigned int oct;
	char *ostring;

	oct = va_arg(list, unsigned int);
	ostring = uint_to_octal(oct);

	_strcat(buffer, ostring);
	return (1);
}
