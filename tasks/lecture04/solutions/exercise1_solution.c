/*
    Implementujte funkci print_ascii, ktera dostane parametrem promennou typu char a vytiskne jeho ASCII hodnotu.
    Napr. pro znak 'a' funkce vytiskne 97. 
    Je povoleno pouzit funkci printf z knihovny stdio.h.
    Ostatni knihovni funkce jsou zakazane!
*/

#include <stdio.h>

void print_ascii(const char c) {
    printf("%d\n", c);
}


int main() {
    print_ascii('a');
    return 0;
}
