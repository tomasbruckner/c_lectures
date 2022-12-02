---
title: Přetypování
---

Přetypování funguje tak, že máme nějaký datový typ a my o něm řekneme, že je to ve skutečnosti jiný datový typ.

Vezmeme si typickou situaci, kdy chceme vydělit dvě `int` čísla, ale chceme, aby výsledek bylo číslo desetinné. Aby to bylo možné, tak musí být aspoň jedno číslo při dělení desetinné viz kapitola XXX.

Tato situace se dá vyřešit operátorem `pretypování` (v angličtině `cast`)

```c
#include <stdio.h>

int main()
{
    int x = 5;
    int y = 2;
    double vysledek = (double) x / (double) y;

    return 0;
}
```

Jak program funguje?

1. Vytvoří se proměnná `x` a nastaví se na 5
1. Vytvoří se proměnná `y` a nastaví se na 2
1. Proměnná `x` se přetypuje s `int` na `double`
1. Proměnná `y` se přetypuje s `int` na `double`
1. Vydělí se `5.0 / 2.0`
1. Výsledek `2.5` se uloží do definované proměnné `vysledek`
1. Program se ukončí

Program by fungoval stejně, i kdybychom přetypovali pouze proměnnou `x`

```c
#include <stdio.h>

int main()
{
    int x = 5;
    int y = 2;
    double vysledek = (double) x / y;

    return 0;
}
```

Nebo pouze proměnnou `y`

```c
#include <stdio.h>

int main()
{
    int x = 5;
    int y = 2;
    double vysledek = x / (double) y;

    return 0;
}
```

Je potřeba dávat pozor na to, že nelze všechno přetypovat na cokoliv. Kdybychom se poksuli přetypovat číslo na strukturu (viz kapitola XXX).


```c
#include <stdio.h>

struct struktura { int x; };

int main()
{
    struct struktura test = { .x = 10 };
    int x = (int) test;

    return 0;
}
```

Tak už se nám to nepodaří.

Obecně přetypování většinou nebudete potřebovat, ale je dobré o něm vědět.

## Přetypování na void


## Implicitní přetypování
Pokud použijeme operátor přetypování, tak se jedná o **explicitní** přetypování. Pokud se hodnota přetypuje automaticky bez operátoru, tak se jedná o **implicitní** přetypování.

Implicitní přetypování nastane například, pokud uložíme hodnotu typu`unsigned int` do proměné typu `int` (tyto typy viz kapitola XXX).


```c
#include <stdio.h>

int main()
{
    unsigned int x = 10;
    int y = x;

    printf("%i\n", y);

    return 0;
}
```


