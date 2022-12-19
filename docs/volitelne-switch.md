---
title: Struktura Switch
---

`Switch` struktura je velmi podobná IF struktuře. Mějme program

```c
#include <stdio.h>

int main()
{
    int x = 20;

    if (x == 10) {
        printf("Hodnota je 10\n");
    } else if (x == 20) {
        printf("Hodnota je 20\n");
    }

    return 0;
}
```

Tento program můžeme přepsat pomocí struktury `Switch`. Struktura `switch` má následující diagram

![switch](./obrazky/switch/switch.png)

V kódu bychom měli

```c
#include <stdio.h>

int main()
{
    int x = 20;

    switch (x) {
        case 10:
            printf("Hodnota je 10\n");
            break;
        case 20:
            printf("Hodnota je 20\n");
            break;
    }

    return 0;
}
```

Dostáváme stejný výsledek jako v programu s IF strukturou. `Switch` se skládá z hodnoty, kterou dáme do závorek za klíčové slovo `switch` (v našem případě proměnná `x`).
```c
switch (x)
```

Dále se skládá z jednotlivých `case` bloků (někdy také říkáme `case` větví).

```c
case 10:
```

Jak se program vykonává
1. Vytvoří se proměnná typu `int` s identifikátorem `x` a nastaví se jí hodnota `20`
1. `switch` zkontroluje hodnotu proměnné `x`
1. Zkontroluje se, zda je hodnota `x` rovná `10` - není, pokračuje se na další `case`
1. Zkontroluje se, zda je hodnota `x` rovná `20` - ano, je
1. Vytiskne se `Hodnota je 20`
1. Ukončí se `switch` pomocí klíčového slova `break`
1. Program se ukončí pomocí `return 0`

## Hodnota "default"
Co kdybychom chtěli mít ve `Switch` i `case`, který by odchytil libovolnou jinou hodnotu? Něco jako `else` v `if` struktuře. 

Mějme program s IF strukturou
```c
#include <stdio.h>

int main()
{
    int x = 25;

    if (x == 10) {
        printf("Hodnota je 10\n");
    } else if (x == 20) {
        printf("Hodnota je 20\n");
    } else {
        printf("Hodnota je neznama\n");
    }

    return 0;
}
```
K tomu nám slouží v případě `switch` struktury klíčové slovo `default`.

Předchozí program můžeme přepsat pomocí `switch` struktury následovně
```c
#include <stdio.h>

int main()
{
    int x = 25;

    switch (x) {
        case 10:
            printf("Hodnota je 10\n");
            break;
        case 20:
            printf("Hodnota je 20\n");
            break;
        default:
            printf("Hodnota je neznama\n");
            break;
    }

    return 0;
}
```

Při spuštění dostáváme
```
Hodnota je neznama
```

K čemu slouží klíčové slovo `break`? Ukončuje nám aktuální `case`. Můžeme se podívat, co se stane, když ho tam nedáme. Změňme hodnotu `x` na `10`.
```c
#include <stdio.h>

int main()
{
    int x = 10;

    switch (x) {
        case 10:
            printf("Hodnota je 10\n");
        case 20:
            printf("Hodnota je 20\n");
            break;
        default:
            printf("Hodnota je neznama\n");
            break;
    }

    return 0;
}
```

Vytiskne se nám
```
Hodnota je 10
Hodnota je 20
```

Jak se program vykonává
1. Vytvoří se proměnná typu `int` s identifikátorem `x` a nastaví se jí hodnota `10`
1. `switch` zkontroluje hodnotu proměnné `x`
1. Zkontroluje se, zda je hodnota `x` rovná `10` - ano, je
1. Vytiskne se `Hodnota je 10`
1. `Case 20` se ignoruje
1. Vytiskne se `Hodnota je 20`
1. Ukončí se `switch` pomocí klíčového slova `break`
1. Program se ukončí pomocí `return 0`

Toho platí i pro `default` sekci. Vynechme v našem programu i druhý `break`

```c
#include <stdio.h>

int main()
{
    int x = 10;

    switch (x) {
        case 10:
            printf("Hodnota je 10\n");
        case 20:
            printf("Hodnota je 20\n");
        default:
            printf("Hodnota je neznama\n");
    }

    return 0;
}
```

Tisknou se všechny větve. Dostáváme

```
Hodnota je 10
Hodnota je 20
Hodnota je neznama
```

Pokud bychom nastavili `x` na `20`, tisklo by se 
```
Hodnota je 20
Hodnota je neznama
```

Toho se dá využít v případě, že chceme pro několik hodnot stejný kód
```c
#include <stdio.h>

int main()
{
    int x = 10;

    switch (x) {
        case 10:
        case 20:
            printf("Hodnota je 10 nebo 20\n");
            break;
        default:
            printf("Hodnota je neznama\n");
    }

    return 0;
}
```

Což bychom mohli napsat pomocí IF struktury například takto
```c
#include <stdio.h>

int main()
{
    int x = 10;

    if (x == 10 || x == 20) {
        printf("Hodnota je 10 nebo 20\n");
    } else {
        printf("Hodnota je neznama\n");
    }

    return 0;
}
```

Kdy použít `if` a kdy `switch`? `Switch` nám dává jasně najevo, že kontrolujeme jeden výraz akorát na různé hodnoty. V případě `if` můžeme mít mnohem komplexnější podmínky.

Je to hodně o osobních preferencích. Někdo nepíše `switch` nikdy, někdo ho používá pokaždé, když může. Nelze říct, že jedno řešení je výrazně lepší než to druhé. Pokud se vám `switch` líbí, tak ho můžete používat.

## Odkazy
[Následující kapitola: Rekurzivní funkce](./volitelne-rekurze.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/36)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Priorita operátorů](./volitelne-priorita-operatoru.md)
