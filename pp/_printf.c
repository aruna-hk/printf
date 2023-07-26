#include "main.h"
/*void e_xit(const char *pp)
{
	write(1, pp, strlen(pp));
}
*/
int _printf(const char *format, ...)
{
	char *mybuffer = malloc(sizeof(char) * 1024);
	va_list print;
	char ar[2];
	int (*func_ptr)(char *, va_list);
	int len;

	mybuffer[0] = '\0';
	va_start(print, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				_strcat(mybuffer, "%");
			else
			{
				func_ptr = get_op_func(*format);
				if (func_ptr == NULL)
					continue;
				func_ptr(mybuffer, print);
			}
			format++;
		}
		ar[0] = *format;
		ar[1] = '\0';
		_strcat(mybuffer, ar);
		format++;
	}
	write(1, mybuffer, _strlen(mybuffer));
	len = _strlen(mybuffer);
	free(mybuffer);
	return (len);
}
