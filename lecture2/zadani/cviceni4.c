/**
    Zadani:
        Doplnte funkci countdown, aby program vytisknul na prvni dva radky: 
        543210
        Konec

        Zdrojovy kod prekladejte s parametry -pedantic -Wextra -Wall -std=c99 (viz prvni cviceni).
**/

#include <stdio.h>

/**
*   Prints numbers from maxNumber to zero on the first line
*   and Konec on the second line.
*
*   @param maxNumber highest number to be printed
**/
void countdown(int maxNumber);

int main() {
    countdown(5);
    return 0;
}
