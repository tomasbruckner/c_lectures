/*
    Implementujte funkci sum_array, ktera dostane jako parametr pole typu unsigned int a velikost daneho pole.
    Funkce vrati soucet prvku v danem poli.
    Funkci implementujte bez pouziti knihovnich funkci (nepouzivat funkce z knihovny pridane pomoci #include).
*/

#include <stdio.h>

unsigned int sum_array(const unsigned int array[], const unsigned int array_size) {
    unsigned int sum = 0;

    for(unsigned int i = 0; i < array_size; i++) {
        sum += array[i];
    }

    return sum;
}

int main() {
    unsigned int array[] = {1, 2, 3, 4};

    if (sum_array(array, 4) == 10) {
        printf("ok\n");
    }

    return 0;
}
