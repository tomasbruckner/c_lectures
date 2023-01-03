---
title: Práce s uživatelským vstupem pro pokročilé
---

Práci s uživatelským vstupem jsme si vyzkoušeli v kapitole [Práce s uživatelskám vstupem](./zaklady-vstup.md). Nyní si představíme funkci `int getchar();`. Ta nemá žádný parametr a funguje tak, že přečte jeden znak ze standardního vstupu.

Mějme program
```c
#include <stdio.h>

int main() {
    int c = getchar();
    while (c != EOF) {
        printf("%c", c);
        c = getchar();
    }

    return 0;
}
```

Nám dává

```
100
25
```

Všimněme si, že jsme netiskli nový řádek `\n` ve funkci `printf`. Pokud bychom to tak udělali, tak bychom měli každý znak na novém řádku.

Čtení po jednom znaku nám dává větší kontrolu nad tím, co můžeme se vstupem dělat. 


Jak bychom naprogramovali, kdybychom chtěli načíst celý standardní vstup? Mohli bychom například načíst každý řadek do pole řetězců.

Mějme program

```c
#include <stdio.h>
#include <stdlib.h>

#define BLOK_PAMETI 4

char * inicializace() {
    char * retezec = malloc(sizeof(char)*BLOK_PAMETI);

    if (retezec == NULL) {
        printf("Chyba alokace\n");
        return NULL;
    }

    retezec[0] = '\0';

    return retezec;
}

char * pridej_pamet(char * retezec, int novy_max) {
    char * novy_retezec = realloc(retezec, novy_max);
    if (novy_retezec == NULL) {
        printf("Chyba realokace\n");
        return NULL;
    }

    return novy_retezec;
}

int delka_retezec(const char * retezec) {
    int delka = 0;

    while (retezec[delka] != '\0') {
        delka += 1;
    }

    return delka;
}

char * pridat_retezec(char * retezec_k_upraveni, const char * retezec_k_pridani, int * max_delka) {
    int delka_k_upraveni = delka_retezec(retezec_k_upraveni);
    int delka_k_pridani = delka_retezec(retezec_k_pridani);

    if (delka_k_upraveni + delka_k_pridani >= *max_delka) {
        retezec_k_upraveni = pridej_pamet(retezec_k_upraveni, delka_k_upraveni + delka_k_pridani + 1);

        if (retezec_k_upraveni == NULL) {
            return NULL;
        }
    }

    for (int i = 0; i <= delka_k_pridani; i = i + 1) {
        retezec_k_upraveni[i + delka_k_upraveni] = retezec_k_pridani[i];
    }

    return retezec_k_upraveni;
}

int main() {
    char * retezec = inicializace();
    int max_delka = BLOK_PAMETI;

    if (retezec == NULL) {
        return 1;
    }

    char * novy_retezec = pridat_retezec(retezec, "novy retezec", &max_delka);
    if (novy_retezec == NULL) {
        free(retezec);
        return 1;
    } else {
        retezec = novy_retezec;
    }

    printf("%s\n", retezec);

    free(retezec);

    return 0;
}
```
XXX


## Odkazy
[Následující kapitola: Aritmetické operace (zkráceně)](./volitelne-aritmeticke-operace.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/32)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Přesměrování](./pokrocile-presmerovani.md)
