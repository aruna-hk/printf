#include <stdio.h>
#include <stdlib.h>

char *hex_to_string(unsigned int hex) {
    char *result = NULL;
    int num_digits = 1;
    unsigned int temp = hex;

    // Count the number of digits in the hexadecimal number
    while (temp >= 16) {
        temp /= 16;
        num_digits++;
    }

    // Allocate memory for the string representation of the hexadecimal number
    result = (char *)malloc(sizeof(char) * (num_digits + 1)); // +1 for null-terminator

    if (result == NULL) {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    // Convert the hexadecimal number to string
    int index = num_digits - 1;
    while (index >= 0) {
        int digit = hex % 16;
        if (digit < 10) {
            result[index] = digit + '0'; // Convert digits 0-9 to characters
        } else {
            result[index] = digit - 10 + 'A'; // Convert digits A-F to characters
        }
        hex /= 16;
        index--;
    }

    result[num_digits] = '\0'; // Null-terminate the string

    return result;
}

int main() {
    unsigned int hex_num = 800003FF;
    char *hex_str = hex_to_string(hex_num);
    printf("Hexadecimal Number: 0x%X\n", hex_num);
    printf("Hexadecimal String: %s\n", hex_str);
    
    // Don't forget to free the dynamically allocated memory
    free(hex_str);

    return 0;
}

