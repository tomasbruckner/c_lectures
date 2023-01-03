---
title: Aritmetické operace (zkráceně)
---

V kapitole [Aritmetické operace](./zaklady-aritmeticke-operace.md) jsme se setkali s aritmetickými operacemi. Nyní si ukážeme jejich zkrácený zápis, který funguje stejně jako klasický zápis (jenom je napsaný kratším zápisem)

| Operátor  | Klasický zápis  | Zkrácený zápis  |
|---|---|---|
| sčítání | a = a + b | a += b |
| odečítání | a = a - b | a -= b |
| násobení | a = a * b | a *= b |
| dělení | a = a / b | a /= b |
| modulo | a = a % b | a %= b |

Pokud bychom měli program

```c
#include <stdio.h>

int main() {
    int x = 0;
    x += 3;

    printf("x je %i\n", x);

    return 0;
}
```

Nám dává

```
x je 3
```
Pokud tedy nápíšeme `x = x + 3`, tak se přičte k proměnné `x` hodnota 3. Stejně to můžeme napsat `x += 3`, což také přičte k proměnné `x` hodnotu 3.


Zkrácený zápis můžeme použít i pro bitové operace (viz kapitola [Bitové operace](./volitelne-bitove-operace.md))

| Operátor  | Klasický zápis  | Zkrácený zápis  |
|---|---|---|
| bitový AND | a = a & b | a &= b |
| bitový OR | a = a \| b | a \|= b |
| bitový XOR | a = a ^ b | a ^= b |
| bitový posun doprava | a = a << b | a <<= b |
| bitový posun doprava | a = a >> b | a >>= b |


## Inkrement/dekrement operátory
V jazyku C najdeme speciální operátory pro přičtení a odečtení jedničky. Jedná se o nejkratší zápis přičtení.

Máme čtyři varianty

| Operátor  | Zápis | Význam |
|---|---|---|
| Postfix inkrement | a++ | a = a + 1 |
| Prefix inkrement | ++a | a = a + 1 |
| Postfix dekrement | a-- | a = a - 1 |
| Prefix dekrement | --a | a = a - 1 |


Možná se divíte, proč je zde dvakrát přičtení a jednou odečtení jedničky. Nestačil by jeden zápis? Jaký je rozdíl mezi prefix a postfix variantou?

Pro postfix variantu je chování ve výrazu takové, že pokud je použita ve výrazu, tak se nejdříve vrátí hodnota a následně se proměnná inkrementuje. V prefix variantě se hodnota nejdříve inkrementuje a až následně vrátí ve výrazu.

Mějme program pro postfix operátor
```c
#include <stdio.h>

int main() {
    int x = 0;

    printf("x je %i\n", x);
    printf("x++ je %i\n", x++);
    printf("x je %i\n", x);

    return 0;
}
```
Dostáváme 
```
x je 0
x++ je 0
x je 1
```
Jak proběhne vyhodnocení daného programu?
1. Definuje se proměnná `x` a nastaví se na nulu
1. vytiskne se proměnná `x` (hodnota 0)
1. Vytiskne se proměnná `x` (hodnota 0)
1. Inkrementuje se `x` o jedničku (hodnota 1)
1. Vytiskne se proměnná `x` (hodnota 1)
1. Program se ukončí `return 0`

Následující použití postfix operátor
```c
printf("x++ je %i\n", x++);
```
Si můžeme představit jako
```c
printf("x++ je %i\n", x);
x = x + 1;
```
Oba zápis se chovají stejně.


Pro prefix operátor mějme program

```c
#include <stdio.h>

int main() {
    int x = 0;

    printf("x je %i\n", x);
    printf("++x je %i\n", ++x);
    printf("x je %i\n", x);

    return 0;
}
```
Dostáváme 

```
x je 0
++x je 1
x je 1
```
Jak proběhne vyhodnocení daného programu?
1. Definuje se proměnná `x` a nastaví se na nulu
1. vytiskne se proměnná `x` (hodnota 0)
1. Inkrementuje se `x` o jedničku (hodnota 1)
1. Vytiskne se proměnná `x` (hodnota 1)
1. Vytiskne se proměnná `x` (hodnota 1)
1. Program se ukončí `return 0`

Následující použití prefix operátor
```c
printf("x++ je %i\n", ++x);
```
Si můžeme představit jako
```c
x = x + 1;
printf("x++ je %i\n", x);
```
Oba zápis se chovají stejně. Všimněme si rozdílu mezi postfix operátoru, kdy se přičtení jedničky provedlo až po vytisknutí pomocí funkce `printf`.

### Použití v IF struktuře
Pro demonstraci si můžeme ukázat ve struktuře IF
```c
#include <stdio.h>

int main() {
    int x = 0;

    if (x++) {
        printf("Pravda\n");
    } else {
        printf("Nepravda\n");
    }

    printf("x je %i\n", x);

    return 0;
}
```

Dostáváme

```
Nepravda
x je 1
```
Protože se nejdříve vyhodnotí `if(0)` a až následně se provede inkrement.


Pro prefix mějme program
```c
#include <stdio.h>

int main() {
    int x = 0;

    if (++x) {
        printf("Pravda\n");
    } else {
        printf("Nepravda\n");
    }

    printf("x je %i\n", x);

    return 0;
}
```

Dostáváme

```
Pravda
x je 1
```
Zde se nejdříve provede inkrement a následně se vyhodnotí `if(1)`.

### Použití jako příkaz

Pokud inkrement/dekrement operátor není použit jako výraz, ale je použit jako příkaz, tak nemusíme řešit, zda se jedná o prefix nebo postfix operátor.


```c
#include <stdio.h>

int main() {
    int x = 0;

    printf("x je %i\n", x);
    ++x;
    printf("x je %i\n", x);
    x++;
    printf("x je %i\n", x);

    return 0;
}
```

Dostáváme.
```
x je 0
x je 1
x je 2
```

### Použití ve For cyklu
Nejčastější použití inkrement/dekrementu operátoru uvidíte ve for cyklu v iterační sekci
```c
#include <stdio.h>

int main() {
    for (int i = 0; i < 10; i++) {
        // neni dulezite
    }

    return 0;
}
```

Můžete použít jaký chcete zápis. Někdo preferuje klasický zápis, někdo zkrácený a někdo inkrement/dekrement operátor. Osobně jsem v kurzu používal klasický zápis, protože často se studenti naučí jenom inkrement/dekrement operátory, ale když pak mají v inkrementační sekci For cyklu inkrementovat proměnnou `i` o jiné číslo, než o 1, tak jsou zmatení a neví, jak to udělat. Pokud se naučí klasický zápis, tak je to pro ně obecně jednodušší.

Například mějme program, který má vytisknout násobky 3 od 0 do 9.

```c
#include <stdio.h>

int main() {
    for (int i = 0; i < 10; i = i + 3) {
        printf("%i\n", i);
    }

    return 0;
}
```

Tím dostaneme
```
0
3
6
9
```


## Odkazy
[Následující kapitola: Operátor podmínky](./volitelne-operator-podminky.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/33)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Práce s uživatelskám vstupem pro pokročilé](./pokrocile-vstup.md)
