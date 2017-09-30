/**
    Zadani:
        Implement function uppercase so that the program prints Good job! six times.

        Compile the source code with arguments -pedantic -Wextra -Wall -std=c99
**/
#include <stdio.h>

void test_characters(char result, char expected);

/**
*   Converts single character to uppercase.
*
*   @param c character to be uppercased
*   @return uppercased character or -1 if the character is not alphabet letter.
**/
char uppercase(char c);

int main() {
    test_characters(uppercase('A'), 'A');
    test_characters(uppercase('a'), 'A');
    test_characters(uppercase('z'), 'Z');
    test_characters(uppercase('/'), -1);
    test_characters(uppercase('\\'), -1);
    test_characters(uppercase('\n'), -1);

    return 0;
}

void test_characters(char result, char expected) {
    if (result == expected) {
        printf("Good job!\n");
    } else {
        printf("Keep trying!\n");
    }
}

char uppercase(char c) {
    char result = -1;

    if (c >= 'a' && c <= 'z') {
        result = c - 32;
    } else if (c >= 'A' && c <= 'Z') {
        result = c;
    }

    return result;
}
