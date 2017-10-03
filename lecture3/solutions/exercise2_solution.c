/**
    Task:
        Implement get_length function so that the program prints Good job! four times.
        Do not include string.h library.

        Compile the source code with arguments -pedantic -Wextra -Wall -std=c99
**/
#include <stdio.h>

/**
*   Returns length of the string.
*
*   @param string string to be checked
*   @return number of characters of the string or -1 if the string is NULL
**/
int get_length(const char * string);

void test_numbers(int result, int expected);

int main() {
    test_numbers(get_length("izp"), 3);
    test_numbers(get_length("IZP"), 3);
    test_numbers(get_length("IZ\n\tP"), 5);
    test_numbers(get_length(NULL), -1);

    return 0;
}

void test_numbers(int result, int expected) {
    if(result == expected) {
        printf("Good job!\n");
    } else {
        printf("Keep trying!\n");
    }
}

int get_length(const char * string) {
    if (string == NULL) {
        return -1;
    }

    int length = 0;
    while(string[length] != '\0') {
        ++length;
    }

    return length;
}
