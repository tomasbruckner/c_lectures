---
title: Operátor podmínky
---


Operátor podmínky je ternární operátor (má tři operandy). Je velmi podobný IF struktuře

![operator podminky](./obrazky/operator_podminky/operator_podminky.png)

Zde vidíme jednotlivé části operátor podmínky

* **podmínka**
* **výraz, pokud je podmínka pravdivá**
* **výraz, pokud je podmínka nepravdivá**


Mějme program, kde podmínka je pravdivá
```c
#include <stdio.h>

int main() {
    int x =  0 < 1 ? 5 + 5 : 2 + 2 + 1;

    printf("x je %i\n", x);

    return 0;
}
```

Nám dává
```
x je 10
```
Podmínka se vyhodnotí jako pravdivá a do proměnné `x` se uloží výsledek výrazu `5 + 5`.


Mějme program, kde podmínka je nepravdivá
```c
#include <stdio.h>

int main() {
    int x =  0 > 1 ? 5 + 5 : 2 + 2 + 1;

    printf("x je %i\n", x);

    return 0;
}
```

Nám dává
```
x je 5
```
Podmínka se vyhodnotí jako nepravdivá a do proměnné `x` se uloží výsledek výrazu `2 + 2 + 1`.

Mohli bychom samozřejmě použít i závorky

```c
#include <stdio.h>

int main() {
    int x =  (0 > 1) ? (5 + 5) : (2 + 2 + 1);

    printf("x je %i\n", x);

    return 0;
}
```

A program by fungoval pořád stejně.

## Zanoření podmínkových operátorů

Podmínkové operátory se dají zanořovat. Mějme funkci s jedním parametrem typu `int`. Pokud je hodnota parametru záporná, funkce vrátí -1. Pokud je kladná, tak vrátí 1. Pokud je nula, tak se vrátí nula.

```c
int vrat_hodnotu(int x) {
    if (x < 0) {
        return -1;
    }

    if (x > 0) {
        return 1;
    }

    return 0;
}
```

Tuto funkci bychom mohli napsat jako dva operátory podmínky v sobě.

```c
#include <stdio.h>

int vrat_hodnotu(int x) {
    return x < 0
        ? -1
        : x > 0
        ? 1
        : 0;
}

int main() {
    int x =  vrat_hodnotu(-10);

    printf("x je %i\n", x);

    return 0;
}
```

Dostáváme
```
x je -1
```

Velmi jednoduché operátory podmínky se někdy používají pro přiřazení hodnoty, například

```c
int y = x > 0 ? 1 : -1;
```

Je to přehlednější, než mít

```c
int y = 1;

if (x < 0) {
    y = -1;
}
```

Ale je to subjektivní. Neexistuje případ, kdy byste operátor podmínky museli použít. Vše jde přepsat i bez použití operátoru podmínky (s použitím struktury IF).


## Odkazy
[Následující kapitola: Priorita operátorů](./volitelne-priorita-operatoru.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/34)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Aritmetické operace (zkráceně)](./volitelne-aritmeticke-operace.md)
