---
title: Řetězce pro pokročilé
---


V kapitole XXX jsme se zabývali řetězci, které měly fixní délku. To nám nemusí ve všech případech stačit a potřebujeme mít délku dynamickou. Můžeme použít stejný postup jako v kapitole XXX.

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

Definovali jsme si několik funkcí

* `char * inicializace()` - vytvoří řetězec
* `char * pridej_pamet(char * retezec, int novy_max)` - nastavení nové velikosti řetězce
* `int delka_retezec(const char * retezec)` - vrátí velikost řetězce
* `char * pridat_retezec(char * retezec_k_upraveni, const char * retezec_k_pridani, int * max_delka)` - přidá jeden řetězec k druhému a vrátí spojený řetězec

