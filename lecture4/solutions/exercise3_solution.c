/*
    Implementujte funkci get_even_count, ktera dostane pole typu unsigned int a velikost daneho pole a vrati pocet sudych cisel v poli. Nula je sude cislo.
    Napr. pro pole obsahujici ctyri cisla: 52, 32, 1, 1994
    vrati funkce cislo 3 (suda cisla: 52, 32, 1994)
    Funkci implementujte bez pouziti knihovnich funkci (nepouzivat funkce z knihovny pridane pomoci #include).
*/

#include <stdio.h>

unsigned int get_even_count(const unsigned int array[], const unsigned int array_size) {
    unsigned int count = 0;

    for(unsigned int i = 0; i < array_size; i++) {
        if ((array[i] % 2) == 0) {
            count++;
        }
    }

    return count;
}


int main() {
    unsigned int array[] = {52, 32, 1, 1994};

    if (get_even_count(array, 4) == 3) {
        printf("ok\n");
    }

    return 0;
}
