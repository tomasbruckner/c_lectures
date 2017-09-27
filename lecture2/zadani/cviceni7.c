/**
    Zadani:
        Doplnte funkci max, aby program vytisknul sestkrat Good job!

        Zdrojovy kod prekladejte s parametry -pedantic -Wextra -Wall -std=c99 (viz prvni cviceni).
**/
#include <stdio.h>

void test_numbers(int result, int expected);

/**
*   Checks which of the two numbers specified in the parameters is bigger and returns it.
*
*   @param number1 first number
*   @param number2 second number
*   @return number that is bigger
**/
int max(int number1, int number2);

int main() {
    test_numbers(max(1, 2), 2);
    test_numbers(max(-22, -23), -22);
    test_numbers(max(42, 42), 42);
    test_numbers(max(0, -1337), 0);
    test_numbers(max(1111, 11111), 11111);
    test_numbers(max(-1000000, -000000001), -1);

    return 0;
}

void test_numbers(int result, int expected) {
    if (result == expected) {
        printf("Good job!\n");
    } else {
        printf("Keep trying!\n");
    }
}