/**
    Task:
        Implement max function so that the program prints Good job! four times.
        Do not include string.h library.

        Compile the source code with arguments -pedantic -Wextra -Wall -std=c99
**/
#include <stdio.h>
#include <limits.h>

/**
*   Find max number in array of integer numbers.
*
*   @param array array of integer numbers to be checked
*   @param arrayLength length of the array
*   @return highest number in the array, for empty array returns minimum int number
**/
int max(const int * array, const int arrayLength);

void test_numbers(int result, int expected);

int main() {
    int test1[] = {-1, 0, 1, 2, 3, 4, 5};
    test_numbers(max(test1, 7), 5);
    
    int test2[] = {-1, -2, -3, -1, 0, -3};
    test_numbers(max(test2, 6), 0);
    
    int test3[] = {2};
    test_numbers(max(test3, 1), 2);
    
    int test4[] = {077, 0xff, 0xfe, 042, 42};
    test_numbers(max(test4, 5), 255);

    return 0;
}

void test_numbers(int result, int expected) {
    if(result == expected) {
        printf("Good job!\n");
    } else {
        printf("Keep trying!\n");
    }
}

int max(const int * array, const int arrayLength) {
    if (arrayLength  < 1) {
        return INT_MIN;
    }

    int result = array[0];
    for(int i = 1; i < arrayLength; i++) {
        if (array[i] > result) {
            result = array[i];
        }
    }

    return result;
}
