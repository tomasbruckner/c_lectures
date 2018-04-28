/**
    Task:
        Implement function calculateRectanglePerimeter so that the program prints Good job! three times.

        Compile the source code with arguments -Werror -Wextra -Wall -std=c99
**/
#include <stdio.h>

void test_numbers(unsigned int result, unsigned int expected);

/**
*   Calculates perimeter of the rectangle.
*
*   @param length rectangle's length
*   @param width rectangle's width
*   @return perimeter of given rectangle
**/
unsigned int calculateRectanglePerimeter(unsigned int length, unsigned int width);

int main() {
    test_numbers(calculateRectanglePerimeter(1, 20), 42);
    test_numbers(calculateRectanglePerimeter(22, 23), 90);
    test_numbers(calculateRectanglePerimeter(42, 1), 86);

    return 0;
}

void test_numbers(unsigned int result, unsigned int expected) {
    if (result == expected) {
        printf("Good job!\n");
    } else {
        printf("Keep trying! Your result was: %u. Expected result was: %u\n", result, expected);
    }
}
