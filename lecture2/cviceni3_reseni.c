/**
    Zadani:
        Doplnte funkci absolute_value, aby program vytisknul ctyrikrat Good job!
        Zdrojovy kod prekladejte s parametry -pedantic -Wextra -Wall -std=c99 (viz prvni cviceni).
**/

#include <stdio.h>

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

int absolute_value(int number) {
    if (number < 0) {
        number *= -1;
    }

    return number;
}

void test_numbers(int result, int expected) {
    if (result == expected) {
        printf("Good job!\n");
    } else {
        printf("Keep trying!\n");
    }
}