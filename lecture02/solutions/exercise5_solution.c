/**
    Zadani:
        Implement function countdown so that the program prints on the first three lines: 
        543210
        543210
        543210

        Compile the source code with arguments -pedantic -Wextra -Wall -std=c99
**/
#include <stdio.h>

/**
*   Prints numbers from maxNumber to zero.
*   Prints x lines specified by repeat parameter.
*
*   @param maxNumber highest number to be printed
*   @param repeat number of lines printed
**/
void countdown(int maxNumber, int repeat);

void countdown(int maxNumber, int repeat) {
    for(int j = 0; j < repeat; j++) {
        for(int i = maxNumber; i >= 0; i--) {
            printf("%d", i);
        }

        printf("\n");
    }
}

int main() {
    countdown(5, 3);
    return 0;
}
