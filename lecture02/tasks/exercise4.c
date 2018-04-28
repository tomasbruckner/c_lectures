/**
    Task:
        Implement function countdown so that the program prints on the first two lines: 
        543210
        Konec

        Compile the source code with arguments -Werror -Wextra -Wall -std=c99
**/
#include <stdio.h>

/**
*   Prints numbers from maxNumber to zero on the first line
*   and string Konec on the second line.
*
*   @param maxNumber highest number to be printed
**/
void countdown(int maxNumber);

int main() {
    countdown(5);
    return 0;
}
