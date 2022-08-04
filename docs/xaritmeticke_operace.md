---
title: Aritmetické operace
---

V předchozí kapitole jsme si ukazali sčítání. V programování můžeme použít i další operátory

| Operátor | Název | Ukázka | Výsledek | 
|---|---|---|---|
| + | sčítání  | 2 + 5  | 7 | 
| - | odečítání  | 2 - 5  | -3 |
| * | násobení  | 2 * 5  | 10 |
| / | dělení  | 4 / 2  | 2 |
| % | modulo (zbytek po dělení)  | 10 % 3  | 1 |


Pokud jste se ještě nesetkali s operátorem modulo, tak to funguje následovně.

Pokud chci spočítat `10 % 3`, tak se udělá `10 / 3`, což je výsledek 3 a zbytek 1. A tento zbytek 1 je právě výsledek operace modulo.

| x | y | x % y |
|---|---|---|
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
|---|---|---|
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
Tak pokud je výsledek 0, tak víme, že je číslo sudé.


## Dělení
Velký pozor je potřeba dát v jazyku C na dělení. Pokud máme

```c
5 / 2
```

Tak bychom mohli čekat, že výsledek bude `2.5`. V jazyce C ale platí, že pokud jsou obě hodnoty operace dělení datového typu `int`, tak i výsledek je `int`. V jazyce C tedy platí, že výsledek je `2` (a ne `2.5`). Označujeme to jako celočíselné dělení.

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

Mínus můžeme použít mezi dvěma hodnotami `10 - 3`. Pokud máme dvě hodnoty a mezi nimi operátor, tak takovému operátoru říkáme, že je **binární** (pracuje s dvěma hodnotama).

Pokud operátor pracuje s jednou hodnotou, tak o takovém operátoru mluvíme jako o **unárním**.

Ukázka může být 

```
x * -y
```
V tomto případě je mínus použito jako unární (pracuje jenom s proměnnou `y` a ne s `x`).

Jak udělat z kladné proměnné zápornou a ze záporné kladnout? Buď můžeme udělat

```c
x = -1 * x;
```
nebo zkráceně

```c
x = -x;
```
