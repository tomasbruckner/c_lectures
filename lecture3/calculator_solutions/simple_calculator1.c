#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
*   Run the program with one number or two numbers and a plus operator.
*   ./simple_calculator 1

    ./simple_calculator 1 + 2

*/
int main(int argc, char ** argv) {
    if (argc == 1) {
        printf("Not enough arguments\n");
        return EXIT_FAILURE;
    }
    
    if (argc == 2) {
        printf("%g\n", atof(argv[1]));
    } else {
        printf("%g\n", atof(argv[1]) + atof(argv[3]));
    }

    return EXIT_SUCCESS;
}
