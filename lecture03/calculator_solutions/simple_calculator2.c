#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
*   Run the program with two numbers and an operator.
    ./simple_calculator 1 + 2
    ./simple_calculator 1 - 2
    ./simple_calculator 1 x 2
    ./simple_calculator 1 / 2  (nekdy na windows taky 1 // 2)
*/
int main(int argc, char ** argv) {
    if (argc != 4) {
        printf("Invalid number of arguments\n");
        return EXIT_FAILURE;
    }
        
    char * op = argv[2];
    if (strcmp(op, "+") == 0){
        printf("%g\n", atof(argv[1]) + atof(argv[3]));
    } else if (strcmp(op, "-") == 0) {
        printf("%g\n", atof(argv[1]) - atof(argv[3]));
    } else if (strcmp(op, "x") == 0) {
        printf("%g\n", atof(argv[1]) * atof(argv[3]));
    } else if (strcmp(op, "/") == 0) {
        printf("%g\n", atof(argv[1]) / atof(argv[3]));
    } else {
        printf("Invalid operator: %s\n", op);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
