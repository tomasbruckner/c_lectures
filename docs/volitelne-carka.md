---
title: Operátor čárka
---

Jazyk C má speciální operátor čárku `,`. Tento operátor funguje tak, že umožňuje na jeden příkaz definovat více výrazů. Není to něco, co bychom používali nějak často, ale je dobré o tomto operátoru vědět.

Dá se použít pro definici několika proměnných najednou. Pokud bych chtěl definovat tři proměnné, tak můžu udělat

```c
int x = 0;
int y = 0;
int z = 0;
```

Pomocí operátoru čárky můžu tyto tři definice sjednotit do jedné

```c
int x = 0, y = 0, z = 0;
```
Někdy se také může setkat s jiným odsazením (viz kapitola XXX)

```c
int x = 0,
    y = 0,
    z = 0;
```

Všechny tři zápisy vytvoří tři proměnné datového typu `int` a nastaví je na nulu.


## Návratová hodnota
Návratová hodnota čárky je její poslední výraz. Mějme program

```c
#include <stdio.h>

int main() {
    int x = (2 * 5, 3 * 5, 4 * 5);
    int y = (1, 2, 3);

    printf("x je %i\n", x);
    printf("y je %i\n", y);

    return 0;
}
```
Dostáváme

```
x je 20
y je 3
```

Zde pozor, že je potřeba obalit celý výraz do závorek.

Jak probíhá uložení do hodnoty `x`?

1. Vynásobí se 2 * 5 a výsledek se zahodí
1. Vynásobí se 3 * 5 a výsledek se zahodí
1. Vynásobí se 4 * 5 a výsledek je poslední výraz operátoru čárka, tudíž se uloží do proměnné `x`

Obdobně pro proměnnou `y`.


Obdobně můžeme udělat i více přiřazení bez definice proměnných.
```c
#include <stdio.h>

int main() {
    int x = 0;
    int y = 0;

    (x = 5, y = 4);

    printf("x je %i\n", x);
    printf("y je %i\n", y);

    return 0;
}
```
Nám dává

```
x je 5
y je 4
```

## For cyklus
Nejčastější použití čárky je ve For cyklu v inicializační sekci. Zde definujeme dvě proměnné `x` a `y`

```c
for (int x = 0, y = 0; x < 3; x = x + 1)
```

Zde je důležité si dát pozor, že čárka neznamená konec sekce ve For cyklu. Jednotlivé sekce se oddělují vždy středníkama. Někdy jsem viděl nefungující For cyklu napsaný jako

```c
for (int x = 0, x < 3, x = x + 1)
```

Což z pohledu jazyka C není validní kód.

## Odkazy
[Následující kapitola: Union](./volitelne-union.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/47)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Operátor přirazení hodnoty](./volitelne-prirazeni.md)
