/*
    Implementujte funkci, ktera vrati 1 pokud je x patri do intervalu <a;b>, v opacnem pripade vrati 0.
    Napr. a = 3, b = 5.3, pro x = 4.9 vrati 1, pro x = 1.3 vrati 0.
    Funkci implementujte bez pouziti knihovnich funkci (nepouzivat funkce z knihovny pridane pomoci #include).
*/

#include <stdio.h>

int in_interval(const double a, const double b, const double x) {
    if (x >= a && x <= b) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    if (in_interval(3, 5.3, 4.9) == 1) {
        printf("ok 1\n");
    }

    if (in_interval(3, 5.3, 1.3) == 0) {
        printf("ok 2\n");
    }

    return 0;
}
