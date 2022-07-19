# Dynamické pole
V některých případech neznámé velikost pole dopředu. Mějme například program, který načítá čísla od uživatele, dokud uživatel nenapíše číslo 0. Pak program vypíše všechny hodnoty a ukončí se.

Ať vytvoříme libovolně velké statické pole (pevně daná velikost pole), tak vždy může uživatel zadat o číslo navíc.

Mějme variantu se statickým polem

```c
#include <stdio.h>

#define VELIKOST_POLE 3

void vytiskni_pole(int pole[], int velikost) {
    for (int i = 0; i < velikost; i = i + 1) {
        printf("%i\n", pole[i]);
    }
}

int main() {
    int pole[VELIKOST_POLE];
    int pocet = 0;
    int hodnota = 0;

    while (1) {
        scanf("%i", &hodnota);
        if (hodnota == 0) {
            break;
        }

        pole[pocet] = hodnota;
        pocet += 1;
        if (pocet >= VELIKOST_POLE) {
            printf("Nelze nacist dalsi\n");
            break;
        }
    }

    vytiskni_pole(pole, pocet);

    return 0;
}
```

V C však můžeme pracovat s dynamickou pamětí. Tzv. můžeme vytvářet libovolně velká pole. Slouží nám na to funkce `malloc` (memory allocation) z knihovny `stdlib.h`. Má jeden parametr a to počet bytů, které chceme alokovat (přiřadit) ukazateli. Funkce může selhat. V takovém případě vrátí `NULL` (ve vašich programech se asi nikdy nestane pokud neuděláte nějaké nekonečné zacyklení).

```c
#include <stdio.h>
#include <stdlib.h>

void vytiskni_pole(int pole[], int velikost) {
    for (int i = 0; i < velikost; i = i + 1) {
        printf("%i\n", pole[i]);
    }
}

int main() {
    int * ukazatel = malloc(4 * sizeof(int));

    if (ukazatel == NULL) {
        printf("Doslo k chybe\n");
        return 1;
    }

    *ukazatel = 1;
    *(ukazatel + 1) = 2;
    *(ukazatel + 2) = 3;
    *(ukazatel + 3) = 4;

    vytiskni_pole(ukazatel, 4);

    free(ukazatel);
    ukazatel = NULL;

    return 0;
}
```

Všimněmě si, že po skončení práce s pamětí, kterou jsme si alokovali přes `malloc`, tak musíme zavolat funkci `free`. Ta dělá to, že uvolní paměť a může ji pak používat někdo jiný. Pokud bychom paměť neuvolnili a program by běžel dlouho (dny, měsíce, roky), tak by náš program mohl postupně zabírat více a více paměti, kterou neuvolňuje, a tím použít všechny prostředky počítače. Tomu se anglicky říká `memory leak`. Pokud byste program ukončili, tak se všechna paměť uvolní automaticky sama.

Další dobrá zásada je, že když skončíte práci s ukazatelem, tak mu nastavit hodnotu NULL. Tím dáváte najevo, že již s touto pamětí nebudete pracovat. Pokud byste to neudělali a následně pracovali s proměnnou `ukazatel`, tak pracujete s nedefinovaným chováním. Lepší je pracovat s NULL, která vám okamžitě hodí chybu. 

> Je potřeba dávat pozor na to, že malloc vám přiřadí náhodou paměť, kde může být něco uložené. Je potřeba s tím počítat a nastavit si to dle potřeby. Pokud byste potřebovali mít nastavené hodnoty na nula, tak můžete použít funkci `calloc` viz dokumentace například [zde](https://devdocs.io/c/memory/calloc)


Pomocí funkce malloc dokážeme generovat libovolně velkou paměť. To nám ale neřeší náš případ, protože my na začátku programu nevíme, jak velkou paměť potřebujeme. K řešení nám pomůže funkce `realloc` (reallocation). Ta dostane parametrem paměť, která byla vytvořená pomocí `malloc`/`calloc`/`realloc` funkce (a nebyla zatím na ní zavolaná funkce `free`). Tuto paměť pak následně zvětší/zmenší dle potřeby.

```c
int main() {
    int * ukazatel = malloc(4 * sizeof(int));

    if (ukazatel == NULL) {
        printf("Doslo k chybe\n");
        return 1;
    }

    int * novy_ukazatel = realloc(ukazatel, 10 * sizeof(int));
    if (novy_ukazatel == NULL) {
        printf("Doslo k chybe\n");
        free(ukazatel);
        return 1;
    }

    ukazatel = novy_ukazatel;
    novy_ukazatel = NULL;

    // provedu neco s ukazatelem

    free(ukazatel);
    ukazatel = NULL;

    return 0;
}
```

Jak tím vyřešit náš původní program?

```c
#include <stdio.h>
#include <stdlib.h>

#define VELIKOST_ALOKACE 3

void vytiskni_pole(int pole[], int velikost) {
    for (int i = 0; i < velikost; i = i + 1) {
        printf("%i\n", pole[i]);
    }
}

int main() {
    int * ukazatel = malloc(VELIKOST_ALOKACE * sizeof(int));
    if (ukazatel == NULL) {
        printf("Doslo k chybe alokaci\n");
        return 1;
    }

    int pocet = 0;
    int hodnota = 0;
    int velikost_pole = VELIKOST_ALOKACE;
    while (1) {
        scanf("%i", &hodnota);
        if (hodnota == 0) {
            break;
        }

        ukazatel[pocet] = hodnota;
        pocet += 1;
        if (pocet >= velikost_pole) {
            velikost_pole += VELIKOST_ALOKACE;
            int * novy_ukazatel = realloc(ukazatel, velikost_pole * sizeof(int));
            if (novy_ukazatel == NULL) {
                printf("Doslo k chybe pri realokaci\n");
                free(ukazatel);
                return 1;
            }
        }
    }

    vytiskni_pole(ukazatel, pocet);

    return 0;
}
```

Velikost alokace (3) používáme jenom pro demonstrační účely. V reálném programu můžete použít mnohem větší konstanty (stovky, tisíce, desetitisíce). Dle vašich potřeb.


## Halda

> Obecně je potřeba myslet na to, že práce s dynamickou pamětí je mnohem pomalejší a náročnější než práce se statickou pamětí.