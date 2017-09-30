/**
    Task:
        Compile the source code with arguments -pedantic -Wextra -Wall -std=c99
**/
#include <stdio.h>

int main() {
    /**
     Add additional parameters to function call printf (do not modify the first parameter)
     so the program prints to the terminal:
        IZP 2017 
    **/
    printf("%c%s %d%u\n", 'I', "ZP", 201, 7);

    return 0;
}
