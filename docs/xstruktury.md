---
title: Struktury
---


Struktury nám umožňují definovat si naše vlastní komplexní datové typy. Mějme program, který dostane tři souřadnice bodu a vytiskne daný bod tolikrát, kolikrát mu řekneme.

```c
#include <stdio.h>

void vytiskni_bod(int x, int y, int z, int pocet_tisku) {
    for (int i = 0; i < pocet_tisku; i = i + 1) {
        printf("x je %i, y je %i, z je %i\n", x, y, z);
    }
}

int main()
{
    int x = 1;
    int y = 2;
    int z = 3;
    int pocet_tisku = 1;

    vytiskni_bod(x, y, z, pocet_tisku);

    return 0;
}
```

S rostoucím počtem parametrů a proměnných je někdy těžké pak určit, co patří k čemu. Tento problém nám řeší struktury, které nám umožňují logicky spojit hodnoty, které patří k sobě.

Struktury se definují takto

![struct definition](./obrazky/struktury/struct_definition.png)

Kde název struktury je klasický identifikátor jako u proměnných a funkcí (spolu se stejnými omezeními).

Každá struktura může mít libovolný počet tzv. fieldů. Field obsahuje název a datový typ. Je to velmi podobné definování proměnné.

Definujeme si strukturu s názvem `bod`, která bude mít tři fieldy typu int.
```c
struct bod { int x; int y; int z; };
```
Tohle je náš nový datový typ s názvem `struct bod`. Jak vytvoříme proměnnou tohoto datového typu? Stejně jako bychom to udělali v případě datového typu int. Tzv. nejdříve napíšeme datový typ a následně název proměnné. Vytvořme si tedy proměnnou s názvem `prvni_bod`.

```c
struct bod prvni_bod;
```

Pro použití struktury tedy potřebujeme dva kroky
1. Nejdříve datovou strukturu definovat
1. Poté vytvořit proměnnou, která bude datového typu námi vytvořené struktury

Stejně jako můžeme vytvořit více proměnných typu int, tak můžeme vytvořit i více proměnných datového typu `struct bod`.

```c
struct bod prvni_bod;
struct bod druhy_bod;
struct bod treti_bod;
```

Můžeme nyní přepsat náš program pomocí struktury
```c
#include <stdio.h>

struct bod { int x; int y; int z; };

void vytiskni_bod(struct bod bod_k_tisku, int pocet_tisku) {
    for (int i = 0; i < pocet_tisku; i = i + 1) {
        printf("x je %i, y je %i, z je %i\n", bod_k_tisku.x, bod_k_tisku.y, bod_k_tisku.z);
    }
}

int main()
{
    struct bod prvni_bod;
    prvni_bod.x = 1;
    prvni_bod.y = 2;
    prvni_bod.z = 3;
    int pocet_tisku = 1;

    vytiskni_bod(prvni_bod, pocet_tisku);

    return 0;
}
```
Všimněme si, že struktury definujeme v hlavním bloku programu. Další důležitá věc je, že pokud chceme pracovat s fieldy struktury, tak musíme napsat název proměnné, pak tečka a pak název fieldu. Například pokud chceme nastavit field x, tak uděláme

```c
prvni_bod.x = 1;
```

Pozor na to, že pokud byste definovali funkci uvnitř funkce, tak se vám to podaří

```c
#include <stdio.h>

int main()
{
    struct bod { int x; int y; int z; };
    struct bod prvni_bod;
    prvni_bod.x = 1;
    prvni_bod.y = 2;
    prvni_bod.z = 3;

    return 0;
}
```

Ale jakmile se ji pokusíte použít v jiné funkce, tak dojde k chybě. Například zde

```c
#include <stdio.h>

void vytiskni_bod(struct bod bod_k_tisku, int pocet_tisku) {
    for (int i = 0; i < pocet_tisku; i = i + 1) {
        printf("x je %i, y je %i, z je %i\n", bod_k_tisku.x, bod_k_tisku.y, bod_k_tisku.z);
    }
}

int main()
{
    struct bod { int x; int y; int z; };
    struct bod prvni_bod;
    prvni_bod.x = 1;
    prvni_bod.y = 2;
    prvni_bod.z = 3;

    return 0;
}
```

## Anonymní struktura
Pokud bychom chtěli strukturu použít jenom v jedné funkci a pouze pro jednu proměnnou, tak můžeme strukturu definovat anonymně (bez názvu) přímo u dané proměnné

```c
#include <stdio.h>

int main()
{
    struct { int x; int y; int z; } prvni_bod;
    prvni_bod.x = 1;
    prvni_bod.y = 2;
    prvni_bod.z = 3;

    return 0;
}
```

Tento zápis není moc praktický a využívá se především při vytváření aliasů pomocí klíčového slova `typedef` viz níže.

## Inicializace

Strukturu můžeme inicializovat tak, že dáme honotu do složených závorek a pro každý field dáme tečku, název fieldu, rovnítko a hodnota. Následující program
```c
#include <stdio.h>

struct bod { int x; int y; int z; };

int main()
{
    struct bod prvni_bod = { .x = 1, .y = 2, .z = 3 };
    printf("x je %i, y je %i, z je %i\n", prvni_bod.x, prvni_bod.y, prvni_bod.z);

    return 0;
}
```

Vytiskne
```
x je 1, y je 2, z je 3
```

## Typedef

Klíčové slovo `typedef` nám umožňuje definovat nové jméno již existujícímu datovému typu (říkáme alias).

![alias](./obrazky/struktury/alias.png)

Velmi často se to používá se strukturama. Abychom nemuseli psát při definici proměnné

```c
struct bod prvni_bod;
```

Můžeme vytvořit alias naší struktůře

```c
typedef struct bod bod_alias;
```

A pak můžeme definovat proměnné pomocí
```c
bod_alias prvni_bod;
```

Náš předchozí program bychom mohli přepsat na

```c
#include <stdio.h>

struct struktura_bod { int x; int y; int z; };
typedef struct struktura_bod bod;

void vytiskni_bod(bod bod_k_tisku, int pocet_tisku) {
    for (int i = 0; i < pocet_tisku; i = i + 1) {
        printf("x je %i, y je %i, z je %i\n", bod_k_tisku.x, bod_k_tisku.y, bod_k_tisku.z);
    }
}

int main()
{
    bod prvni_bod;
    prvni_bod.x = 1;
    prvni_bod.y = 2;
    prvni_bod.z = 3;
    int pocet_tisku = 1;

    vytiskni_bod(prvni_bod, pocet_tisku);

    return 0;
}
```

A již můžeme všude psát `bod` místo `struct bod`.

Definici struktury a její alias můžeme spojit i do jednoho řádku. Místo

```c
struct struktura_bod { int x; int y; int z; };
typedef struct struktura_bod bod;
```
Napíšeme
```c
typedef struct { int x; int y; int z; } bod;
```

Využívá se tu principu anonymní struktury.


Vytvářet aliasy můžete i pro libovolné jiné datové typy. Například si můžete vytvořit vlastní alias pro datový typ int.

```c
#include <stdio.h>

typedef int muj_int;

int main()
{
    muj_int x = 10;
    printf("x je %i\n", x);

    return 0;
}
```

Aliasy je možné pak kombinovat i s původním datovým typem. Je to pouze pro přehlednost pro programátory.

```c
#include <stdio.h>

typedef int muj_int;

int main()
{
    muj_int x = 10;
    int y = x;
    printf("x je %i, y je %i\n", x, y);

    return 0;
}
```