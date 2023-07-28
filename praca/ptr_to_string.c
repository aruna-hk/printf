#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ptr_to_string(char *ptr)
{
    // Allocate a buffer to store the string.
    char *buffer = malloc(sizeof(char) * strlen(ptr) + 1);

    // Copy the string from the pointer to the buffer.
    strcpy(buffer, ptr);

    // Return the string.
    return buffer;
}

int main()
{
    char *str = "This is a string.";
    char *ptr = str;
    char *new_str = ptr_to_string(ptr);
    printf("The string value of %s is %s\n", ptr, new_str);
    free(new_str);
    return 0;
}

