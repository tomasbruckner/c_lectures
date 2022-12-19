---
title: Aritmetické operace
---

V předchozí kapitole jsme si ukazali sčítání. V programování můžeme použít i další operátory

| Operátor | Název | Ukázka | Výsledek | 
|:---:|:---:|:---:|:---:|
| + | sčítání  | 2 + 5  | 7 | 
| - | odečítání  | 2 - 5  | -3 |
| * | násobení  | 2 * 5  | 10 |
| / | dělení  | 4 / 2  | 2 |
| % | modulo (zbytek po dělení)  | 10 % 3  | 1 |


Pokud jste se ještě nesetkali s operátorem modulo, tak to funguje následovně.

Pokud chci spočítat `10 % 3`, tak se udělá `10 / 3`, což je výsledek 3 a zbytek 1. A tento zbytek 1 je právě výsledek operace modulo.

| x | y | x % y |
|:---:|:---:|:---:|
| 0 | 3 | 0 |
| 1 | 3 | 1 |
| 2 | 3 | 2 |
| 3 | 3 | 0 |
| 4 | 3 | 1 |
| 5 | 3 | 2 |
| 6 | 3 | 0 |
| 7 | 3 | 1 |
| 8 | 3 | 2 |
| 9 | 3 | 0 |
| 10 | 3 | 1 |

Pro negativní čísla pak platí
| x | y | x % y |
|:---:|:---:|:---:|
| -1 | 3 | -1 |
| -2 | 3 | -2 |
| -3 | 3 | 0 |
| -4 | 3 | -1 |
| -5 | 3 | -2 |
| -6 | 3 | 0 |
| -7 | 3 | -1 |
| -8 | 3 | -2 |
| -9 | 3 | 0 |
| -10 | 3 | -1 |

Velmi často se používá modulo ke zjištění, zda je číslo sudé. Mějme číslo X, u kterého chceme zjistit, zda je sudé nebo liché. Pokud uděláme
```c
x % 2
```
Tak pokud je výsledek 0, tak víme, že je číslo sudé. V opačném případě je číslo liché.


## Dělení
Velký pozor je potřeba dát v jazyku C na dělení. Pokud máme

```c
5 / 2
```

Tak bychom mohli čekat, že výsledek bude `2.5`. V jazyce C ale platí, že pokud jsou obě hodnoty operace dělení datového typu `int`, tak i výsledek je `int`. V jazyce C tedy platí, že výsledek je `2` (a ne `2.5`). Označujeme to jako **celočíselné dělení**.

Pokud bychom chtěli dostat výsledek `2.5` museli bychom jednu z hodnot nastavit jako desetinné. To se v C dá udělat několik způsoby. Všechny tyto způsoby způsobí, že výsledek bude `2.5` datového typu double.

```
5.0 / 2
5 / 2.0
5.0 / 2.0
```

Proč to funguje? Protože pokud použijeme číslo s tečkou, tak ho označíme jako datový typ `double`, což je datový typ pro desetinná čísla. Používáme ho podobně jako datový typ `int`. Definice proměnné vypadá

```c
double x = 5.0;
```

Pokud použijeme tvar s desetinnou tečkou, tak se vždy jedná o `double`. Dále platí, že pokud je jedno z čísel při dělení datového typu `double`, tak výsledek bude také typu `double`.


## Unární mínus

Mínus můžeme použít mezi dvěma hodnotami `10 - 3`. Pokud máme dvě hodnoty a mezi nimi je operátor, tak takovému operátoru říkáme, že je to **binární operátor** (pracuje s dvěma hodnotama).

Pokud operátor pracuje s jednou hodnotou, tak o takovém operátoru mluvíme jako o **unárním operátoru**.

Ukázka může být 

```c
x * -y
```

nebo

```c
5 * -3
```

V tomto případě je mínus použito jako unární (pracuje jenom s jednou hodnotou/proměnnou a ne s dvěma).

Jak udělat z kladné proměnné zápornou a ze záporné kladnout? Buď můžeme udělat

```c
x = -1 * x;
```
nebo zkráceně

```c
x = -x;
```


## Úkoly na procvičení
### Úkol 1
Napište funkci, která bude mít 2 parametry typu int a vytiskne jejich součet.

<details>
  <summary>Klikni pro zobrazení možného řešení</summary>

```c
#include <stdio.h>

void secti(int x, int y) {
    printf("%i\n", x + y);
}

int main()
{
    secti(1, 2);
    return 0;
}
```
</details>

### Úkol 2
Napište funkci, která bude mít 2 parametry typu int a vytiskne jejich součet.

<details>
  <summary>Klikni pro zobrazení možného řešení</summary>

```c
#include <stdio.h>

void secti(int x, int y) {
    printf("%i\n", x + y);
}

int main()
{
    secti(1, 2);
    return 0;
}
```
</details>


## Fun fact
Programátoři nemají Oskary ani Nobelovy ceny, ale mají `Turingovu cenu` podle Alana Turinga (1912 - 1954), který je považován za zakladatele moderní informatiky.
O části jeho životě bylo natočeno spoustu filmů. Mezi nejpopulárnější patří například [Kód Enigmy](https://www.csfd.cz/film/283747-kod-enigmy/prehled/).

Více o Alanovi Turingovi například [zde](https://cs.wikipedia.org/wiki/Turingova_cena).

![Turing](https://upload.wikimedia.org/wikipedia/commons/a/a1/Alan_Turing_Aged_16.jpg)

## Odkazy
[Následující kapitola: Řídící struktura IF](./zaklady-if.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/8)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Definujeme vlastní funkce](./zaklady-funkce.md)

