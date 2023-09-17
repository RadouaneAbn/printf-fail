#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include "main.h" // Include your custom printf function

int main() {
    // Test %s specifier
    char *str = "Hello, World!";

    printf("Expected: %s\n", str);
    _printf("Output: %s\n", str);

    // Test %s specifier with empty string
    char *empty_str = "";

    printf("Expected: %s\n", empty_str);
    _printf("Output: %s\n", empty_str);

    // Test %s specifier with NULL string
    char *null_str = NULL;

    printf("Expected: %s\n", null_str);
    _printf("Output: %s\n", null_str);

    // Test %s specifier with long string
    char *long_str = "This is a very long string that should test the capacity of your custom printf function.";

    printf("Expected: %s\n", long_str);
    _printf("Output: %s\n", long_str);

    // Test %s specifier with special characters
    char *special_str = "Hello, World! @#$%^&*()";

    printf("Expected: %s\n", special_str);
    _printf("Output: %s\n", special_str);

    // Test %s specifier with escape sequences
    char *escape_str = "Hello, World! \n\t\r";

    printf("Expected: %s\n", escape_str);
    _printf("Output: %s\n", escape_str);

    // Test %s specifier with maximum length string
    char max_str[4096];

    memset(max_str, 'A', sizeof(max_str) - 1);
    max_str[sizeof(max_str) - 1] = '\0';
    printf("Expected: %s\n", max_str);
    _printf("Output: %s\n", max_str);

    // Test %s specifier with non-ASCII characters
    char *non_ascii_str = "Hello, World! ñçøå";

    printf("Expected: %s\n", non_ascii_str);
    _printf("Output: %s\n", non_ascii_str);

    // Test %c specifier
    char ch = 'A';

    printf("Expected: %c\n", ch);
    _printf("Output: %c\n", ch);

    // Test %c specifier with non-printable character
    char non_print_ch = '\n';

    printf("Expected: %c\n", non_print_ch);
    _printf("Output: %c\n", non_print_ch);
}
