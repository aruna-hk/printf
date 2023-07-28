#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void check_and_alloc(char s, char *dest, va_list args, int *index_insert) {
    if (s == 'c') {
        char c = va_arg(args, int);
        char str[2] = {c, '\0'};
        strcat(dest, str);
        (*index_insert)++;
    } else if (s == 's') {
        char *string_ = va_arg(args, char *);
        strcat(dest, string_);
        *index_insert += strlen(string_);
    } else if (s == 'd' || s == 'u') {
        int integer = va_arg(args, int);
        char int_s[20];
        sprintf(int_s, "%d", integer);
        strcat(dest, int_s);
        *index_insert += strlen(int_s);
    }
}

void cpy(char *dest, char *src, va_list args) {
    int index_add = 0;

    while (*src != '\0')
    {
        if (*src == '%')
	{
            src++;
            char c = *src;
            check_and_alloc(c, dest, args, &index_add);
            src++;
	}
        dest[index_add] = *src;
        index_add++;
		
        src++;
        }
    

    dest[index_add] = '\0';
}

int simple_print(const char *string, ...) {
    va_list args;
    va_start(args, string);

    const int BUFFER_SIZE = 100; // Updated to a reasonable size, can be increased as needed
    char *max_buffer = malloc(sizeof(char) * BUFFER_SIZE);
    max_buffer[0] = '\0'; // Initialize the buffer as an empty string
    char *str = malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(str, string);
    cpy(max_buffer, str, args);
    write(1, max_buffer, strlen(max_buffer));
    int len =(strlen(max_buffer));
     printf("%dru\n",len);
    va_end(args);
    free(max_buffer);
    free(str);

    return (len);
}

int main(void) {
    int len;
    int age = 22;
    int hk = 567;
    char letter = 'F';
    char *name = "kiptoo";
    char *surname = "ngenoh";
    int len2;

    len = simple_print("Let's %s try %d to printf a simple %s sentence.\n",name, age,surname);
    len2 = printf("Let's try to printf a simple sentence.\n");

    printf("Length:[%d, %i]\n", age, len);
    printf("Length:[%d, %i]\n", len2, len2);

    return 0;
}

