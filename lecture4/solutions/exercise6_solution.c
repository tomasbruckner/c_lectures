/*
    Implementujte funkci get_number, ktera dostane ukazatel typu char obsahujici pouze cislice 0 az 9. 
    Pokud retezec obsahuje jiny znak, tak funkce vrati -1. Pro prazdny retezec funkce vraci 0.
    Pokud je vstup validni, vrati dekadickou hodnotu tohoto cisla (podobne jako funkce atoi).
    Pro "123a4" funkce vrati -1 (nepovoleny znak a).
    Pro "1423" funkce vrati cislo 1423.
    Pro "" funkce vrati 0 .
    Je povoleno pouzit funkci strlen z knihovny string.h.
    Ostatni knihovni funkce (napr. atoi) jsou zakazane!
*/

#include <stdio.h>
#include <string.h>

int get_number(const char * string) {
    int result = 0;
    
    for(int i = 0, length = strlen(string); i < length; i++) {
        if (string[i] >= '0' && string[i] <= '9') {
            result = result * 10 + (string[i] - '0');
        } else {
            return -1;
        }
    }

    return result;
}

int main() {
    if (get_number("123a4") == -1) {
        printf("ok 1\n");
    }

    if (get_number("1423") == 1423) {
        printf("ok 2\n");
    }

    if (get_number("") == 0) {
        printf("ok 3\n");
    }

    return 0;
}
