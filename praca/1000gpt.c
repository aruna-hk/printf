#include "main.h"
void check_and_alloc(char s, char *dest, va_list args, int *index_insert)
{
    if (s == 'c')
    {
        char c = va_arg(args, int);
        char str[2] = {c, '\0'};
        strcat(dest, str);
        (*index_insert)++;
    }
    else if (s == 's')
    {
        char *string_ = va_arg(args, char *);
        strcat(dest, string_);
        *index_insert += strlen(string_);
    }
    else if (s == 'd' || s == 'u')
    {
        int integer = va_arg(args, int);
        char int_s[20];
        sprintf(int_s, "%d", integer);
        strcat(dest, int_s);
        *index_insert += strlen(int_s);
    }
}

int get_formatted_length(const char *string, va_list args)
{
    int length = 0;

    while (*string)
    {
        if (*string == '%')
        {
            string++;
            char c = *string;
            int index_insert = 0;
            check_and_alloc(c, NULL, args, &index_insert);
            length += index_insert;
        }
        else
        {
            length++;
        }
        string++;
    }

    return length;
}

void cpy(char *dest, char *src, va_list args)
{
    int index_add = 0;
    while (*src != '\0')
    {
        if (*src == '%')
        {
            src++;
            char c = *src;
            int index_insert = 0;
            check_and_alloc(c, NULL, args, &index_insert);
            src++; // Skip format specifier
            index_add += index_insert;
        }
        else
        {
            dest[index_add] = *src;
            index_add++;
            src++;
        }
    }

    dest[index_add] = '\0';
}

int simple_print(const char *string, ...)
{
    va_list args;
    va_start(args, string);

    int formatted_length = get_formatted_length(string, args);
    int BUFFER_SIZE = formatted_length + 1; // Add 1 for the null-terminator

    char *max_buffer = malloc(sizeof(char) * BUFFER_SIZE);
    char *str = malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(str, string);
    cpy(max_buffer, str, args);
    write(1, max_buffer, strlen(max_buffer));

    va_end(args);
    free(max_buffer);
    free(str);

    return strlen(max_buffer);
}
int main(void)
{
    int len;
    int len2;

    len = simple_print("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");

    printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);

    return 0;
}
