---
title: Struktury
---

V této kapitole si představíme, jak si můžeme sami vytvářet komplexní datové typy. Sloužit nám k tomu budou `struktury` (klíčové slovo `struct`).

Mějme program, který dostane tři souřadnice bodu a vytiskne daný bod tolikrát, kolikrát mu definujeme parametrem `pocet_tisk`.

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

Struktury se definují následovně

![struct definition](./obrazky/struktury/struct_definition.png)

Kde název struktury je klasický identifikátor jako u proměnných a funkcí (spolu se stejnými omezeními).

Každá struktura může mít libovolný počet tzv. fieldů. Field obsahuje název a datový typ. Je to velmi podobné definování proměnné.

Definujme si strukturu s názvem `bod`, která bude mít tři fieldy typu int.
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

Stejně jako můžeme vytvořit více proměnných typu `int`, tak můžeme vytvořit i více proměnných datového typu `struct bod`.

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
Všimněme si, že struktury definujeme v hlavním bloku programu (pod `#include`). Další důležitá věc je, že pokud chceme pracovat s fieldy struktury, tak musíme napsat název proměnné, pak tečku a pak název fieldu. Například pokud chceme nastavit field `x` naší proměnné `prvni_bod`, tak uděláme

```c
prvni_bod.x = 1;
```

Pozor na to, že pokud byste definovali strukturu uvnitř funkce, tak se vám to sice podaří

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

Ale jakmile se ji pokusíte použít v jiné funkci, tak dojde k chybě. Například zde

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

Dostáváme informaci
```
...\main.c|3|warning: 'struct bod' declared inside parameter list will not be visible outside of this definition or declaration|
```
To nám říká, že počítač si myslí, že se snažíme definovat strukturu na řádku 3 (protože nevidí na definici uvnitř funkce `main`).

Dále dostáváme chybu
```
...\main.c|3|error: parameter 1 ('bod_k_tisku') has incomplete type|
```

Počítač si myslí, že se snažíme definovat strukturu, ale definice je špatně (chybí fieldy). To je ale omyl, my jsme se na řádku 3 nesnažili nic definovat, akorát program nevidí naši definici uvnitř funkce `main`.

Proto musíme dávat definice struktur vždy mimo funkce.

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

Můžeme vytvořit alias naší struktůře pomocí

```c
typedef struct bod bod_alias;
```

A pak můžeme definovat proměnné typu `struct bod` pomocí
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


Vytvářet aliasy můžete i pro libovolné jiné datové typy. Například si můžete vytvořit vlastní alias pro datový typ `int`.

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

Aliasy je možné pak kombinovat i s původním datovým typem. Je to pouze pro programátory pro lepší přehlednost.

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


## Úkoly na procvičení
### Úkol 1
XXXXXXXXXX

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


## Fun fact
Jedna z velmi vlivných programátorek byla Margaret Hamilton. Podílela se na vývoji softwaru pro Apollo program od NASA.

Právě ona definovala pojem "softwarové inženýrství". Tím přidala další typ inženýrství (jako chemické, mechanické, elektrické atd.).

Na obrázku je Margaret vyfocená s vytisknutým zdrojovým kódem, který dostal Apollo 11 na Měsíc. Tento zdrojový kód je dnes veřejně dostupný [na Githubu zde](https://github.com/chrislgarry/Apollo-11/).
![kod](https://upload.wikimedia.org/wikipedia/commons/d/db/Margaret_Hamilton_-_restoration.jpg)

Více například [zde (anglický zdroj)](https://en.wikipedia.org/wiki/Margaret_Hamilton_%28software_engineer%29)


## Odkazy
[Zpátky na přehled](./index.md)

[Předchozí kapitola: Řetězce](./zaklady-retezce.md)

[Následující kapitola: Práce se soubory](./zaklady-soubory.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/17)
