/**
    Task:
        Implement string_compare function so that the program prints Good job! seven times.
        Do not include string.h library.

        Compile the source code with arguments -pedantic -Wextra -Wall -std=c99
**/
#include <stdio.h>

#define FALSE 0
#define TRUE 1

/**
*   Compares two string.
*
*   @param string1 first string for comparison
*   @param string2 second string for comparison
*   @return 1 if the strings are equal or both are NULL, otherwise returns 0
**/
int string_compare(const char * string1, const char * string2);

void test_numbers(int result, int expected);

int main() {
    test_numbers(string_compare("izp", "izp"), TRUE);
    test_numbers(string_compare("IZP", "IzP"), FALSE);
    test_numbers(string_compare(NULL, "a"), FALSE);
    test_numbers(string_compare("", "a"), FALSE);
    test_numbers(string_compare("", NULL), FALSE);
    test_numbers(string_compare(NULL, NULL), TRUE);
    test_numbers(string_compare("", ""), TRUE);

    return 0;
}

void test_numbers(int result, int expected) {
    if(result == expected) {
        printf("Good job!\n");
    } else {
        printf("Keep trying!\n");
    }
}

int string_compare(const char * string1, const char * string2) {
    if (string1 == NULL || string2 == NULL) {
        return (string1 == string2);
    }
    
    int valid = FALSE;
    for(int i = 0; ; i++) {
        if (string1[i] == '\0' || string2[i] == '\0') {
            valid = (string1[i] == '\0' && string2[i] == '\0');
            break;
        } else if (string1[i] != string2[i]) {
            break;
        }
    }

    return valid;
}
