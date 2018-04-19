/**
    Task:
        Implement function multiply so that the program prints Good job! six times.

        Compile the source code with arguments -pedantic -Wextra -Wall -std=c99
**/
#include <stdio.h>

void test_numbers(int result, int expected);

/**
*   Calculates multiplication of two operands.
*
*   @param operand1 first number
*   @param operand2 second number
*   @return multiplication of operand1 and operand2
**/
int multiply(int operand1, int operand2);

int main() {
    test_numbers(multiply(1, 2), 2);
    test_numbers(multiply(-22, -23), 506);
    test_numbers(multiply(42, -42), -1764);
    test_numbers(multiply(0, -1337), 0);
    test_numbers(multiply(1, 1), 1);
    test_numbers(multiply(10, 0), 0);

    return 0;
}

void test_numbers(int result, int expected) {
    if (result == expected) {
        printf("Good job!\n");
    } else {
        printf("Keep trying! Your result was: %d. Expected result was: %d\n", result, expected);
    }
}

int multiply(int operand1, int operand2) {
    return operand1 * operand2;
}
