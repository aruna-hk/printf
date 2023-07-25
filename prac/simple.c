#include "main.h"
/**
* _strlen - check string legthn
* @s: pointer to array of chaacters
* Return: len-length of the string
*/
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len = len + 1;
		s++;
	}
	return (len);
}
/**
* rev_string - reverse string--*numnumber case
* @s: pointer to the string literal to operate on--
*/
void rev_string(char *start)
{
        char swap;
        int len = strlen(start);
        char *end = start+ (len - 1); 

        while (start < end)
        {
                swap = *start;
                *start = *end;
                *end = swap;
                start++;
                end--;
        }
}

/**
* int_to_string -- convert interger to string
* to append to buffer to flush to stdout
* @*numnum: take *numnumber as arguemen
*/
char *int_to_string(int num)
{
	int flag;

	if (num < 0)
	{
		flag = 1;
		num = -num;
	}
	int i = 0;
	char store_num[20];

	while (num != 0 && i < 20)
	{
		store_num[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	if (flag == 1)
	{
		store_num[i] = '-';
	}
	rev_string(store_num);

	char *ptr_ss = malloc(sizeof(char) * (strlen(store_num)  + 1));
	strcpy(ptr_ss,store_num);
	return (ptr_ss);
}
/**
* check_identifier - and print map it to a variable value
* @c:character
* @args: variable list
* Return: pointer to allocated space;
*/
char *check_identifier(char ss, va_list *args1)
{
	char *ptr = malloc(sizeof(char) * 1024);
	int mn;
	if (ptr == NULL)
		return (NULL);
	if (ss = 'c')
	{
		char st = va_arg(*args1,int);
		char str2[2] = {st,'\0'};
		strcpy(ptr,str2);
		return (ptr);
	}
	else if (ss = 's')
	{
		char *strr = va_arg(*args1, char *);
		printf("%s--str\n",strr);
		strcpy(ptr,strr);
		return(ptr);
	}
	else if (ss == 'd' || ss == 'i')
	{
		mn = va_arg(*args1,int);
		char *intstring = int_to_string(mn);
		printf("%s -- contnt",intstring);
		return (intstring);
	}
	else
		return (NULL);
}
/**
* _printf - funtion print arg passed to it
* @mn:first arg determines other ars by format specifiers
* Return: strlen
*/
int _print(char *mn, ...)
{
	int i = 0;
	va_list args;
	char *ptr;
	va_start(args,mn);
	while(*mn != '\0')
	{
		if (*mn == '%')
		{
			mn++;
			char c = *mn;
			char *j = check_identifier(c, &args);
			while( *j != '\0')
			{
				write(1,j,1);
				i++;
				j++;
			}
			mn++;
			i++;
		}
		write(1,mn,1);
		i++;
		mn++;
	}
	printf("%d",va_arg(args,int));
	va_end(args);
	return (i + 1);
}
int main(void)
{
	int age = 22;
	char *lname = "ngenoh";
	int len=_print("Let's %d trce.", age);
	printf("\n%d\n",len);
	return (0);
}
