/*
    Implementujte funkci get_total_chars, ktera vrati pocet znaku na standardnim vstupu (stdin).
    Tato funkce nebude mit zadny parametr.
    Je povoleno pouzit funkci getchar nebo scanf z knihovny stdio.h.
    Ostatni knihovni funkce jsou zakazane!
*/

#include <stdio.h>

unsigned int get_total_chars() {
    int c = getchar();
    int count = 0;

    while(c != EOF) {
        c = getchar();
        count++;
    }

    return count;
}

int main() {
    printf("%d\n", get_total_chars());

    return 0;
}
