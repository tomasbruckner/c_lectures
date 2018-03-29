/**
    Task:
        Implement program that prints your name if you run the program with argument author
        otherwise it does nothing.
        On Windows
        exercise5.exe author

        or in Codeblocks
        Project -> set program's arguments and set the program's arguments to author

        If set program's arguments does not open dialog window, you have to create new
        project (not just open file). New -> project -> console application (see lecture 1 wiki).

        On Linux
        ./exercise5 author

        The program also does nothing if there are more arguments than just author. For example
        if you run the program with 
        ./exercise author izp
        It does nothing because there is another argument izp.

        Compile the source code with arguments -pedantic -Wextra -Wall -std=c99
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {

    return EXIT_SUCCESS;
}
