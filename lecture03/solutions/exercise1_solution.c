/**
    Task:
        Implement uppercase function so that the program prints Good job! six times.
        Do not include string.h library.

        Compile the source code with arguments -pedantic -Wextra -Wall -std=c99
**/
#include <stdio.h>
#include <string.h>

#define FALSE 0

/**
*   Converts string to uppercase. Modifies original string.
*
*   @param string string to be uppercased
*   @return uppercased string or NULL if the string is NULL
**/
char * uppercase(char * string);

void test_strings(char * result, char * expected);
int are_strings_equal(char * result, char * expected);

int main() {
    char test1[] = "izp";
    test_strings(uppercase(test1), "IZP");

    char test2[] = "IZP";
    test_strings(uppercase(test2), "IZP");

    char test3[] = "Izp 2017";
    test_strings(uppercase(test3), "IZP 2017");

    char test4[] = "iZ\n\tP";
    test_strings(uppercase(test4), "IZ\n\tP");

    char test5[] = "1337" "\xff" "42";
    test_strings(uppercase(test5), "1337""\xff" "42");

    test_strings(uppercase(NULL), NULL);

    return 0;
}

void test_strings(char * result, char * expected) {
    if(are_strings_equal(result, expected)) {
        printf("Good job!\n");
    } else {
        printf("Keep trying!\n");
    }
}

int are_strings_equal(char * result, char * expected) {
    int valid = FALSE;

    if (expected == NULL) {
        valid = (result == NULL);
    } else if (result != NULL) {
        valid = (strcmp(result, expected) == 0);
    }

    return valid;
}

char * uppercase(char * string) {
    if (string == NULL) {
        return string;
    }

    for(int i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= 32;
        }
    }
    
    return string;
}
