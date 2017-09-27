/**
    Zadani:
        Doplnte funkci countdown, aby program vytisknul na prvni dva radky: 
        543210
        Konec

        Zdrojovy kod prekladejte s parametry -pedantic -Wextra -Wall -std=c99 (viz prvni cviceni).
**/

#include <stdio.h>

void countdown(int number);

void countdown(int number) {
    for(; number >= 0; number--) {
        printf("%d", number);
    }

    printf("\nKonec\n");
}

int main() {
    countdown(5);
    return 0;
}