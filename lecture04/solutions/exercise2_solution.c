/*
    Implementujte funkci max s navratovym datovym typem void (ne int!!!). 
    Funkce dostane dve cisla typu int a ukazatelem vrati vetsi z nich (tzv. funkce bude mit tri parametry).
    Funkci implementujte bez pouziti knihovnich funkci (nepouzivat funkce z knihovny pridane pomoci #include).
*/

#include <stdio.h>

void max(const int a, const int b, int * result) {
    if(a > b) {
        *result = a;
    } else {
        *result = b;
    }
}

int main() {
    int result = 0;

    max(14, -20, &result);

    if (result == 14) {
        printf("ok\n");
    }

    return 0;
}
