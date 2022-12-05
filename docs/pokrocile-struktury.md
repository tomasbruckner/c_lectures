---
title: Struktury pro pokročilé
---


V kapitole XXX jsme si ukázali práci s řetězci. Pro řetězce jsme měli tři proměnné. První byl samotný řetězec `char *`. Druhá proměnná byla číslo, které udržovalo maximální možnou délku řetězce. Třetí proměnná byla číslo, které udržovalo aktuální délku řetězce. Tyto proměnné patří logicky k sobě. Proto bychom je mohli dát do jedné struktury. Ta by mohla vypadat následovně

```c
typedef struct { int max_delka; int delka; char * data; } string;
```

Pak bychom mohli s danou strukturou pracovat následovně

```c
#include <stdio.h>
#include <stdlib.h>

#define BLOK_PAMETI 4

typedef struct { int max_delka; int delka; char * data; } string;

string * inicializace() {
    string * retezec = malloc(sizeof(string));

    if (retezec == NULL) {
        printf("Chyba alokace\n");
        return NULL;
    }

    retezec->delka = 0;
    retezec->max = BLOK_PAMETI;
    retezec->data = malloc(sizeof(char)*BLOK_PAMETI);

    if (retezec->data == NULL) {
        printf("Chyba alokace\n");
        free(retezec);
        return NULL;
    }

    retezec[0] = '\0';

    return retezec;
}

char * pridej_pamet(string * retezec, int novy_max) {
    char * novy_retezec = realloc(retezec, novy_max);
    if (novy_retezec == NULL) {
        printf("Chyba realokace\n");
        return NULL;
    }

    retezec->data = novy_retezec;
    retezec->max_delka = novy_max; 

    return novy_retezec;
}

int main() {
    char * retezec = inicializace();
    if (retezec == NULL) {
        return 1;
    }

    // ...

    free(retezec->data);
    free(retezec);

    return 0;
}
```

Zde si můžeme všimnout několika věcí. Pokud pracujeme s ukazatelem na strukturu, můžeme použít `->`. Tyto dva zápisy jsou stejné (obecně se používá zápis se šipkou)

```c
retezec->delka = 0;
(*retezec).delka = 0;
```

Další věc, na kterou je potřeba si dávat pozor je, že když uvolňujeme paměť, tak je potřeba uvolni nejdříve paměť dat uvnitř struktury a až nakonec samotnou strukturu. Pokud bychom nejdříve uvolnili strukturu a až následně data

```c
free(retezec);
free(retezec->data);
```
Dostaneme chybu, protože na druhém řádku přistupujeme k proměnné `retezec`, která ale už má nedostupnou paměť (byla uvolněna).


Poslední věci, které bychom si měli všimnout je, že pokud potřebujeme rozšířit data, tak se realokuje paměť jenom pro `char * data` a není potřeba realokovat paměť pro `string * retezec`. Je to proto, že struktura zůstává pořád stejné velikosti. Mění se jenom paměť řetězce, na kterou ukazujeme a ta není součástí struktury. Ve struktuře je uložena pouze adresa paměti dat řetězce. Tzv. děláme `realloc` pouze pro `retezec->data` a nikoliv pro `retezec`.


## Rekurzivní struktury
Struktury můžou být i rekurzivní. To znamená, že odkazují samy na sebe. Mějme strukturu, která reprezentuje člověka a má odkaz na jeho rodiče.

```c
struct clovek { struct clovek * matka; struct * clovek otec; };
typedef struct clovek clovek;
```

Mohli bychom simulovat data jednoho člověka, jeho rodičů a rodičů jeho maminky

```c
#include <stdio.h>
#include <stdlib.h>

struct clovek { struct clovek * matka; struct clovek * otec; };
typedef struct clovek clovek;

int main() {
    clovek * ja = malloc(sizeof(clovek));
    clovek * mamka = malloc(sizeof(clovek));
    clovek * tatka = malloc(sizeof(clovek));
    clovek * babicka = malloc(sizeof(clovek));
    clovek * dedecek = malloc(sizeof(clovek));

    ja->matka = mamka;
    ja->otec = tatka;
    ja->matka->matka = babicka;
    ja->matka->otec = dedecek;

    return 0;
}
```

Pro zjednodušení jsme nevolali `free` ani nekontrolovali, zda se paměť podařilo alokovat.


XXX