#include <stdio.h>
#include <stdlib.h>

char *octal_to_string(unsigned int octal) {
    char *result = NULL;
    int num_digits = 1;
    unsigned int temp = octal;

    // Count the number of digits in the octal number
    while (temp >= 8) {
        temp /= 8;
        num_digits++;
    }

    // Allocate memory for the string representation of the octal number
    result = (char *)malloc(sizeof(char) * (num_digits + 1)); // +1 for null-terminator

    if (result == NULL) {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    // Convert the octal number to string
    int index = num_digits - 1;
    while (index >= 0) {
        result[index] = (octal % 8) + '0'; // Convert each digit to character
        octal /= 8;
        index--;
    }

    result[num_digits] = '\0'; // Null-terminate the string

    return result;
}

int main() {
    unsigned int octal_num = 020000001777; // Prefix '0' denotes an octal number

    char *octal_str = octal_to_string(octal_num);
    printf("Octal Number: %o\n", octal_num);
    printf("Octal String: %s\n", octal_str);
    
    // Don't forget to free the dynamically allocated memory
    free(octal_str);

    return 0;
}

