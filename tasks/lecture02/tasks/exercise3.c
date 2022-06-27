/**
    Task:
        Implement absolute_value function so that the program prints Good job! five times.

        Compile the source code with arguments -Werror -Wextra -Wall -std=c99
**/
#include <stdio.h>

/**
*   Converts number to its absolute value.
*
*   @param number Number that should be converted to absolute value
*   @return Absolute value of the number
**/
int absolute_value(int number);

void test_numbers(int result, int expected);

int main() {
    test_numbers(absolute_value(1), 1);
    test_numbers(absolute_value(-1), 1);
    test_numbers(absolute_value(0), 0);
    test_numbers(absolute_value(-1337), 1337);
    test_numbers(absolute_value(42), 42);

    return 0;
}

void test_numbers(int result, int expected) {
    if (result == expected) {
        printf("Good job!\n");
    } else {
        printf("Keep trying!\n");
    }
}
