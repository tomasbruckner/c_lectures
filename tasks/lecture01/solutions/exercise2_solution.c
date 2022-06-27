/**
    Task:
        Implement function calculateCuboidSurfaceArea so that the program prints Good job! three times.

        Compile the source code with arguments -Werror -Wextra -Wall -std=c99
**/
#include <stdio.h>

void test_numbers(unsigned int result, unsigned int expected);

/**
*   Calculates surface area of a cuboid.
*
*   @param length cuboid's length
*   @param width cuboid's width
*   @param height cuboid's height
*   @return perimeter of given cuboid
**/
unsigned int calculateCuboidSurfaceArea(unsigned int length, unsigned int width, unsigned int height);

int main() {
    test_numbers(calculateCuboidSurfaceArea(1, 2, 3), 22);
    test_numbers(calculateCuboidSurfaceArea(9, 10, 1), 218);
    test_numbers(calculateCuboidSurfaceArea(42, 1, 1), 170);

    return 0;
}

void test_numbers(unsigned int result, unsigned int expected) {
    if (result == expected) {
        printf("Good job!\n");
    } else {
        printf("Keep trying! Your result was: %u. Expected result was: %u\n", result, expected);
    }
}

unsigned int calculateCuboidSurfaceArea(unsigned int length, unsigned int width, unsigned int height) {
    return 2 * (length*width + length*height + width*height);
}
