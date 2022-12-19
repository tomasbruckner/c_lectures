---
title: Operátor přirazení hodnoty
---

S přiřazením (operátor `=`) jsme se již setkali jak při definici proměnné

```c
int x = 5;
```

Tak při přiřazení hodnoty mimo definici

```c
x = 10;
```

Co je dobré vědět je, že i samotné přiřazení vrací hodnotu a to takovou, která byla přiřazena. Mějme program

```c
#include <stdio.h>

int main() {
    int x = 0;
    int y = 0;

    y = (x = 5);

    printf("x je %i\n", x);
    printf("y je %i\n", y);

    return 0;
}
```

Dostáváme

```
x je 5
y je 5
```

Jak probíhá vyhodnocení programu?

1. Vytvoří se proměnná `x` a její hodnota se nastaví na 0
1. Vytvoří se proměnná `y` a její hodnota se nastaví na 0
1. Do `x` se přiřadí hodnota 5
1. Do `y` se uloží výsledek předchozího přiřazení (hodnota 5)
1. Vytiskne se `x je 5`
1. Vytiskne se `y je 5`
1. Program se ukončí přes `return 0`

Můžeme takto nastavit i více proměnných najednou (závorky jsou volitelné v `y = (x = 5);` a nemusíme je tam psát)

```c
#include <stdio.h>

int main() {
    int x = 0;
    int y = 0;
    int z = 0;

    y = x = z = 5;

    printf("x je %i\n", x);
    printf("y je %i\n", y);
    printf("y je %i\n", z);

    return 0;
}
```

Dostáváme

```
x je 5
y je 5
z je 5
```


Někdy se můžeme setkat s tímto chováním v IF struktuře


```c
#include <stdio.h>

int main() {
    int x = 0;
    if (x = 10) {
        printf("Pravda\n");
    }
    
    if (x = 0) {
        printf("Nepravda\n");
    }

    return 0;
}
```

Nám dává 
```
Pravda
```
Vyhodnocuje se to následovně
```c
if (x = 10)
```
Uloží se do proměnné `x` hodnota 10 a vrátí se jako výsledek výrazu hodnota 10, takže dostáváme

```c
if (10)
```

Pro druhý IF pak máme

```c
if (x = 0)
```
Uloží se do proměnné `x` hodnota 0 a vrátí se jako výsledek výrazu hodnota 0, takže dostáváme

```c
if (0)
```
Proto se podmínka vyhodnotí jako nepravdivá.

Můžete tedy použít něco jako

```c
#include <stdio.h>

int vrat_hodnotu() {
    int vysledek = 0;
    scanf("%i", &vysledek);

    return vysledek;
}

int main() {
    int x = 0;
    if ((x = vrat_hodnotu()) == 3) {
        printf("Hodnota je 3\n");
    } else {
        printf("Hodnota neni 3\n");
    }

    printf("x je %i\n", x);

    return 0;
}
```

Když zadáme 2, tak se nám vytiskne 

```
Hodnota neni 3
x je 2
```

Jak se vyhodnotí podmínka?
1. Zavolá se funce `vrat_hodnotu`
1. Ta vrátí hodnotu 2
1. Hodnota 2 se uloží do proměnné `x`
1. Výsledek přiřazení (hodnota 2) se porovná s 3
1. Podmínka není pravdivá

Zde je potřeba dát pozor na prioritu operátorů (kapitola XXX). Pokud bychom vynechali závorky v IF podmínce

```c
#include <stdio.h>

int vrat_hodnotu() {
    int vysledek = 0;
    scanf("%i", &vysledek);

    return vysledek;
}

int main() {
    int x = 0;
    if (x = vrat_hodnotu() == 3) {
        printf("Hodnota je 3\n");
    } else {
        printf("Hodnota neni 3\n");
    }

    printf("x je %i\n", x);

    return 0;
}
```
Tak pro hodnotu 2 dostáváme
```
Hodnota neni 3
x je 0
```

Proč? Podívejme se, jak se podmínka vyhodnocuje

1. Zavolá se funce `vrat_hodnotu`
1. Ta vrátí hodnotu 2
1. Hodnota 2 se porovná s 3
1. Porovnání vrátí hodnotu 0
1. Výsledek porovnání (hodnota 0) se uloží do proměnné x
1. Výsledek přiřazení (hodnota 0) se porovná v IF podmínce
1. Podmínka není pravdivá


Osobně tyto konstrukce jako (ať už několiknásobné přiřazení nebo přiřazení v IF podmínkách) nepoužívám. Přijde mi to málo přehledné, ale každý to může mít jinak a pokud se vám tyto použití přiřazení líbí, tak je klidně používejte.

## Odkazy
[Zpátky na přehled](./index.md)

[Předchozí kapitola: Středník](./volitelne-strednik.md)

[Následující kapitola: Operátor čárka](./volitelne-carka.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/46)

