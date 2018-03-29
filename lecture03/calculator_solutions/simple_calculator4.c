#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
*   Run the program with unlimited number of arguments and operators.
    ./simple_calculator 1 + 2 - 5 x 105.4 + 4 / 7.0
*/
int main(int argc, char ** argv) {
    if (argc == 1) {
        printf("Invalid number of arguments\n");
        return EXIT_FAILURE;
    }
        
    double result = atof(argv[1]);
    int i = 3;

    while (argc > i) {
        char * op = argv[i-1];
        if (strcmp(op, "+") == 0) {
            result = result + atof(argv[i]);
        } else if (strcmp(op, "-") == 0) {
            result = result - atof(argv[i]);
        } else if (strcmp(op, "x") == 0) {
            result = result * atof(argv[i]);
        } else if (strcmp(op, "/") == 0) {
            result = result / atof(argv[i]);
        } else {
            printf("Invalid operator: %s\n", op);
            return EXIT_FAILURE;
        }

        i = i + 2;
    }

    printf("%g\n", result);

    return EXIT_SUCCESS;
}
