---
title: Datový typ char
---

Další datový typ, který si tady představíme, je `char`, tzv. jeden znak. Můžeme definovat a uložit hodnotu následovně

```c
int main() {
    char x = 'a';

    return 0;
}
```

Všimněme si, že se zde používají **jednoduché uvozovky**. Pokud bychom použili dvojité

```c
int main() {
    char x = "a";

    return 0;
}
```
Tak dostáváme následující chybu
```
initialization of 'char' from 'char *' makes integer from pointer without a cast
```

Snažíme se uložit řetězec (datový typ `char *`) do proměnné, která čeká znak (datový typ `char`).

Také je potřeba si dát pozor na to, abychom do jednoduchých uvozovek nedali dva znaky. Pokud jich tam dáme více, tak už se nejedná o `char` ale o `int`.

```c
int main() {
    char x = 'aa';

    return 0;
}
```
Vypíše chybu
```
overflow in conversion from 'int' to 'char' changes value from '24929' to '97'
```

Pokud bychom chtěli hodnotu vytisknout, tak používáme `%c`

```c
#include <stdio.h>

int main() {
    char x = 'a';
    printf("Znak je %c\n", x);

    return 0;
}
```
Dostáváme
```
Znak je a
```

## ASCII tabulka
Jelikož počítač umí pracovat jenom s číslama (jedničkama a nulama), tak i `char` není nic jiného, než číslo. V minulosti se lidi domluvili, který znak bude odpovídat jakému číslu. To je definováno v ASCII tabulce (American Standard Code for Information Interchange).

Tu nalezneme například [zde](https://cs.wikipedia.org/wiki/ASCII).

Když se do ní podíváme, tak vidíme, že `'a'` má hodnotu v ASCII tabulce 97 v desítkové soustavě. To si můžeme ověřit.

```c
#include <stdio.h>

int main() {
    char x = 'a';
    printf("Znak je %i\n", x);

    return 0;
}
```
Dostáváme
```
Znak je 97
```


```c
#include <stdio.h>

int main() {
    char x = 'a';

    if (x == 'a') {
        printf("Prvni porovnani\n");
    }

    if (x == 97) {
        printf("Druhe porovnani\n");
    }

    return 0;
}
```

Nám vytiskne 
```
Prvni porovnani
Druhe porovnani
```

K charu se můžeme chovat jako k libovolnému číslu. Pokud bychom chtěli zjistit, zda je znak malé písmeno abecedy

```c
#include <stdio.h>

int main() {
    char x = 'd';

    if (x >= 'a' && x <= 'z') {
        printf("Mala abeceda\n");
    }

    return 0;
}
```

Program tiskne 

```
Mala abeceda
```

Písmeno `'d'` má hodnotu 100 v ASCII tabulce a písmeno `'a'` má 97 a písmeno `'z'` má 122. Proto platí

```c
100 >= 97 && 100 <= 122
```

Velikost datového typu char je 1 byte. To si můžeme ověřit
```c
#include <stdio.h>

int main() {
    int velikost = sizeof(char);
    printf("Velikost %i\n", velikost);

    return 0;
}
```

## Načítání více znaků
Mějme program

```c
#include <stdio.h>

int main()
{
    char vstup;
    printf("Zadejte znak:\n");
    scanf("%c", &vstup);
    printf("Znak je %c\n", vstup);

    printf("Zadejte znak:\n");
    scanf("%c", &vstup);
    printf("Znak je %c\n", vstup);

    return 0;
}
```
Tak když program spustíme a zadáme `x`.

```
Zadejte znak:
x
Znak je x
Zadejte znak:
Znak je

```

Stalo se to, že jsme nemohli zadat druhý znak. Proč se to tak stalo? Můžeme si vytisknout hodnotu znaku.

```c
#include <stdio.h>

int main()
{
    char vstup;
    printf("Zadejte znak:\n");
    scanf("%c", &vstup);
    printf("Znak je %c a jeho hodnota je %i\n", vstup, vstup);

    printf("Zadejte znak:\n");
    scanf("%c", &vstup);
    printf("Znak je %c a jeho hodnota je %i\n", vstup, vstup);

    return 0;
}
```
Dostáváme tisk
```
Zadejte znak:
x
Znak je x a jeho hodnota je 120
Zadejte znak:
Znak je
 a jeho hodnota je 10
```

Možná nám už začíná být jasné, co se stalo. Podle zalomeného řádku vidíme, že druhý načtený znak je vlastně `\n`, tzv. nový řádek. V ASCII tabulce vidíme, že hodnotu 10 má znak LF, což je znak nového řádku.

Na to je potřeba dávat pozor, když budeme načítat více znaků po sobě.


## Úkoly na procvičení
### Úkol 1
Napište program, který načte jeden znak od uživatele a následně ho vytiskne.


<details>
  <summary>Klikni pro zobrazení možného řešení</summary>

```c
#include <stdio.h>

int main()
{
    char vstup;
    printf("Zadejte znak:\n");
    scanf("%c", &vstup);
    
    printf("Zadali jste znak %c\n", vstup);

    return 0;
}
```
</details>

### Úkol 2
Napište program, který načte jeden znak od uživatele.
* Pokud je znak číslo, tak se přičte číslo k součtu a načte se další znak
* Pokud je znak cokoliv jiného, tak se vytiskne součet a program se ukončí

Například
1. Uživatel zadá: 5
1. Uživatel zadá: 10
1. Uživatel zadá: 5
1. Uživatel zadá: x
1. Vytiskne se 20
1. Program se ukončí


<details>
  <summary>Klikni pro zobrazení možného řešení</summary>

```c
#include <stdio.h>

int main()
{
    int soucet = 0;
    char vstup;
    while(1) {
        printf("Zadejte znak:\n");
        scanf("%c", &vstup);
        if (vstup >= '0' && vstup <= '9') {
            soucet = soucet + vstup - '0';
        } else {
            break;
        }

        // nacteni noveho radku
        scanf("%c", &vstup);
    }
    
    printf("Soucet je %i\n", soucet);

    return 0;
}
```
</details>

### Úkol 3
Napište program, který načte jeden znak od uživatele.
* Pokud je znak malé písmeno abecedy, tak ho přičte do počtu daných písmenek
* Pokud je znak nového řádku, tak se načte nový znak
* Pokud je znak cokoliv jiného, tak se vytiskne nejčastěji zadaný znak + kolikrát byl zadán


Například:
Uživatel zadá postupně
a,b,c,c,g,c,b,Q

Vytiskne se
```
Nejcasteji zadany znak je c, byl zadan 3 krat
```


<details>
  <summary>Klikni pro zobrazení možného řešení</summary>

```c
#include <stdio.h>

void nastav_na_nulu(int pole[], int velikost_pole) {
    for (int i = 0; i < velikost_pole; i = i + 1) {
        pole[i] = 0;
    }
}

int vrat_max_index(int pole[], int velikost_pole) {
    int max = 0;
    for (int i = 0; i < velikost_pole; i = i + 1) {
        if (pole[max] < pole[i]) {
            max = i;
        }
    }

    return max;
}

int main()
{
    int pocet[26];
    nastav_na_nulu(pocet, 26);

    char vstup;
    while(1) {
        printf("Zadejte znak:\n");
        scanf("%c", &vstup);
        if (vstup >= 'a' && vstup <= 'z') {
            int index = vstup - 'a';
            pocet[index] = pocet[index] + 1;
        } else {
            break;
        }

        // nacteni noveho radku
        scanf("%c", &vstup);
    }

    int max_index = vrat_max_index(pocet, 26);
    if (pocet[max_index] > 0) {
        printf("Nejcasteji zadany znak je %c, byl zadan %i krat\n", max_index + 'a', pocet[max_index]);
    } else {
        printf("Nebyl nacten zadny znak\n");
    }

    return 0;
}
```
</details>

## Fun fact
JavaScript je jeden z nejpopulárnějších programovacích jazyků na světě. Jeho původní název byl ale LiveScript. V době vzniku byl však velmi populární (a stále je) jiný programovací jazyk - Java. Tvůrci LiveScriptu tento svůj jazyk přejmenovali na JavaScript, aby mu zvýšili popularitu.
I dnes sem tam narazíte na člověka, který si myslí, že Java a JavaScript je jeden a ten stejný jazyk.


## Odkazy
[Následující kapitola: Ukazatele](./zaklady-ukazatele.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/13)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Pole](./zaklady-pole.md)

