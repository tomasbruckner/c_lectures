---
title: Datový typ číslo
---

Setkali jsme se s datovým typem `int`, který reprezentuje celé číslo.

Zatím jsme ukládali čísla následovně

`int x = 10;`

Existuje i možnost uložit číslo v jiných soustavách. Například pokud chceme uložit číslo v šestnáctkové soustavě, tak před číslo dáme prefix `0x`.

```c
int x = 0xFF; // FF v sestnactkove soustave je 255 v desitkove soustave
```

Pro osmičkovou soustavu používáme prefix `0`.
```c
int x = 011; // F10 v osmickove soustave je 9 v desitkove soustave
```

Můžeme si dané chování ověřit na následujícím programu

```c
#include <stdio.h>

int main()
{
    printf("011 je %i\n", 011);
    printf("0xFF je %i\n", 0xFF);

    return 0;
}
```

Vytisknou se nám hodnoty v desítkové (to je chování %i).
```
011 je 9
0xFF je 255
```

Je potřeba si uvědomit, že libovolná hodnota proměnné je v počítači uložena binárně a je jedno, jestli ji definujeme v desítkové nebo jakékoliv jiné soustavě. Když pak začneme s uloženou binární hodnotou pracovat, tak až tehdy dochází k interpretaci, tzv. určení, zda se jedná o číslo (případně v jaké soustavě), o znak, ukazatel, soubor atd.

## Znaménkové a neznaménkové čísla
Pro číselné datové typy můžeme definovat i prefix `signed` (znaménkové) nebo `unsigned` (neznaménkové).

Co to znamená? Pokud je datový typ znaménkový, tak může obsahovat jak kladná tak záporná čísla. Pokud je neznaménkový, tak může obsahovat jenom kladná čísla (včetně nuly).

```c
#include <stdio.h>

int main()
{
    signed int x = -10;
    unsigned int y = 10;

    printf("x je %i, y je %u\n", x, y);

    return 0;
}
```

Pro tisk `unsigned int` používáme `%u`.

Pokud bychom se pokusili uložit záporné číslo do neznaménkového datového typu, tak se nám to podaří.

```c
#include <stdio.h>

int main()
{
    unsigned int x = -10;

    printf("x je %i\n", x);

    return 0;
}
```
A dokonce se nám vytiskne
```
x je -10
```

Ale je to jenom zdání. Když spustíme následující program

```c
#include <stdio.h>

int main()
{
    unsigned int x = -10;

    if (x > 0) {
        printf("Pravda\n");
    } else {
        printf("Nepravda\n");
    }

    return 0;
}
```

Tak se nám vytiskne `Pravda`. Proč? Protože my jsme proměnnou definovali jako neznaménkovou. Program ji tedy vyhodní jako neznaménkovou, což je hodnota `4294967286` a ne `-10`. Pro zjištění hodnoty jsme použili `%i` a tam se nám vytiskla binární hodnota uložená v počítači (v počítači jsou vždy jenom binární) tak, že jsme ji intepretovali jako `int`, tzv. `signed int`.

Pro vytisknutí hodnoty jako `unsigned int` musíme použít modifikátor `%u`.

```c
#include <stdio.h>

int main()
{
    unsigned int x = -10;

    printf("x je %u\n", x);

    return 0;
}
```

A nyní dostáváme hodnotu

```
x je 4294967286
```

Pokud tedy máme
```c
unsigned int x = -10;

if (x > 0) {
```

Tak v `if` je hodnota proměnné `x` interpretována jako `unsigned int`, tzv. se udělá

```c
if (4294967286 > 0) {
```

A tedy je podmínka pravdivá.

## Znaménkový a neznaménkový char

Podobně jako int, tak char může být také znaménkový nebo neznaménkový. Existuje `signed char` a `unsigned char`. Samotný `char` (bez prefixu `signed` nebo `unsigned`) může být ve výchozím nastavení buď `signed` nebo `unsigned`. Záleží na procesoru počítače. Na vašem počítači bude s největší pravděpodobností `signed`, na ARM procesoru bude pravděpodobně `unsigned`.

Proměnná datového typu `char` je uložena jako 1 byte, tzv. je uložena na 8 bitech. Díky tomu odvodíme, že `char` může reprezentovat 256 hodnot. Jak si to dokážeme odvodit? Počet hodnot lze spočítat tak, že umocníme číslo 2 na počet bitů, které datový typ zabírá v počítači. Pro náš případ s 8 bity by to znamenalo `2^8 = 256`.


Pro `signed` platí, že nejmenší hodnota je -128 a největší 127 (256 hodnot).

Pro `unsigned` platí, že nejmenší hodnota je 0 a největší 255 (256 hodnot).

## Přetečení datového typu
Každý datový typ má své limity. Limity jsou stanovené podle toho, kolik bitů/bytů daný datový typ zabírá v paměti. Pro `int` (znaménkový i neznaménkový) platí, že typicky zabíra 4 byty (32 bitů) - to se liší podle typu procesoru, na kterém program poběží. Na některých procesorech může `int` zabírát v paměti jen 2 byty (16 bitů). 

Kolik datový typ zabírá v paměti ve skutečnosti lze zjistit pomocí `sizeof`.

```c
#include <stdio.h>

int main()
{
    printf("int zabira %i\n", sizeof(int));

    return 0;
}
```
A dostáváme, že datový typ `int` zabírá 4 byty.

Jaké jsou tedy hranice proměnné `unsigned int`? Ta má 4 byty, to je 32 bitů. Vleze se do ní tedy 2^32 (dvě na třicátou druhou) hodnot. To nám dává rozpětí od 0 do 4294967295. Co by se stalo, kdybychom chtěli uložit nějaké větší číslo do proměnné typu `unsigned int`? Pokud bychom přičetli jedničku k maximálnímu číslu pro `unsgined int` (4294967295), tak se hodnota vyresetuje a začíná se znova od 0. Pokud bychom k maximálnímu číslu přičetli 2, tak dostáváme jedničku.

Mějme program
```c
#include <stdio.h>

int main()
{
    unsigned int max = 4294967295;

    printf("Max je %u\n", max);
    printf("Max+1 je %u\n", max + 1);
    printf("Max+2 je %u\n", max + 2);

    return 0;
}
```

A dostáváme
```
Max je 4294967295
Max+1 je 0
Max+2 je 1
```

Na toto omezení je potřeba myslet, když pracujeme s velkými čísly.


## Další datové typy pro celá čísla
V jazyce C jsou i další datové typy pro celá čísla. Liší se od `int` jenom velikostí v paměti (tzv. i rozsahem minimální a maximálni hodnoty).

Kolik jednotlivé datové typy zabírají v paměti místa?
* `int` - 2 nebo 4 byty (podle procesoru)
* `short` - 2 byty
* `long` - 4 nebo 8 bytů  (podle procesoru)
* `long long` - 8 bytů

Opět existují znaménkové a neznaménkové varianty `signed`/`unsigned` a řídí se stejnými pravidly.

```c
#include <stdio.h>

int main()
{
    printf("int je %u\n", sizeof(int));
    printf("short je %u\n", sizeof(short));
    printf("long je %u\n", sizeof(long));
    printf("long long je %u\n", sizeof(long long));

    return 0;
}
```
Nám dává na mojem počítači
```
int je 4
short je 2
long je 4
long long je 8
```

Limity jednotlivých datových typů (maximální a minimální hodnoty) můžeme ověřit konstantami definovanými v knihovně `limits.h`. Například pro datový typ `int` můžeme použít konstanty `INT_MAX` a `INT_MIN`, které obsahují největší a nejmenší hodnotu datového typu `int`.

```c
#include <stdio.h>
#include <limits.h>

int main()
{
    printf("INT_MAX je %i\n", INT_MAX);
    printf("INT_MIN je %i\n", INT_MIN);

    return 0;
}
```

Konstanty pro další datové typy najdete například [zde](https://devdocs.io/c/types/limits)

## Desetinná čísla
Pro desetinná čísla máme také několik datových typů

* `float` - 4 byty
* `double` - 8 bytů
* `long double` - 10 bytů

U těchto datových typů se nezvyšuje jenom rozsah (minimální a maximální hodnota), ale i přenost (na kolik desetinných čísel dokážeme číslo uložit).

Desetinná čísla definujeme několika způsoby. Pokud potřebujeme definovat číslo typu `double`, tak můžeme použít libovolný z následujících formátů

```c
double x1 = 15.75;      // 15.75
double x2 = 1.575E1;    // 15.75
double x3 = 1575e-2;    // 15.75
double x4 = 0.7;        // 0.7
double x5 = .7;         // 0.7
```

Zápis s exponentem (E) funguje tak, že se vezme číslo před exponentem, a pak se posune desetinná čárka buď doprava (pokud je číslo za exponentem kladné) nebo doleva (pokud je číslo za exponentem záporné). Tzv. `1575e-2` posuneme čárku o dvě místa doleva a dostáváme `15.75`.

Pokud bychom chtěli definovat desetinné číslo jako datový typ `float`, tak přidáme na konec `f` nebo `F`. Pokud potřebujeme long double, tak `l` nebo `L`. Lze použít i zápis s exponentem.

```c
float f1 = 10.0f;
float f2 = .3F;
float f3 = .3E1F;
long double ld1 = 10.0l;
long double ld2 = .3L;
long double ld3 = .3E1L;
```

Limity (jejich konstanty) můžeme najít v knihovně `float.h`

```c
#include <stdio.h>
#include <float.h>

int main()
{
    printf("DBL_MAX je %f\n", DBL_MAX);
    printf("DBL_MIN je %f\n", DBL_MIN);

    return 0;
}
```

## Uložení desesetinných čísel
Desetinná čísla jsou uložená složitějším způsobem. Pokud vás to zajímá, tak můžete mrknout na vysvětlení třeba [zde](https://en.wikipedia.org/wiki/Double-precision_floating-point_format).

Pro nás je ale důležité vědět, že pro desetinná čísla v jazyku C platí, že některá čísla nejde správně zobrazit.

Mějme program
```c
#include <stdio.h>

int main()
{
    float vysledek = 0;
    for (int i = 0; i < 10000; i = i + 1) {
        vysledek += 0.0001;
    }

    printf("vysledek je %f\n", vysledek);

    return 0;
}
```

Dostáváme `vysledek je 1.000054`. Pokud bychom použili místo `float` datový typ s lepší přesností (např. `double`), tak už dostáváme `vysledek je 1.000000`.

Tahle nepřesnost vzniká právě tím, že některá desetinná čísla nejdou správně uložit v některých datových typech. Proto je běžné, že třeba pro finanční systémy se všechny částky násobí tisícovkou a následně se všechny součty a odečty dělají v celých číslech a až výsledek se převede zase zpětně na desetinné číslo.

## Nekonečno
Oproti celým číslům, tak desetinná čísla nikdy nepřetečou (overflow), ale nastaví se jim speciální hodnota nekonečno (inifinity). Buď plus nebo mínus (podle toho, jestli by měl double přetéct do kladných čísel nebo záporných).

Mějme program

```c
#include <stdio.h>
#include <float.h>

int main()
{
    double vysledek  = DBL_MAX * 10;

    printf("vysledek je %f\n", vysledek);

    return 0;
}
```
Tak dostáváme
```
vysledek je 1.#INF00
```

Pokud bychom potřebovali použít hodnotu nekonečna, tak se nachází konstanta v knihovně `math.h`
```c
double vysledek  = INFINITY;
```

Ke kontrole, zda je číslo nekonečno můžeme použít funkci `isinf` z knihovny `math.h`.

```c
#include <stdio.h>
#include <float.h>
#include <math.h>

int main()
{
    double vysledek  = DBL_MAX * -10;

    if (isinf(vysledek)) {
        printf("Pravda\n");
    }

    return 0;
}
```


## NaN
Desetinná čísla můžou také nabít hodnoty `NaN` (Not a Number). Jedná se o případy, kdy použijeme nevalidní operaci a dostáváme nevalidní hodnotu. Například pokud dělíme nulu nulou, děláme odmocninu z mínus jedna atd.

Mějme program

```c
#include <stdio.h>
#include <float.h>

int main()
{
    double vysledek  = 0.0 / 0.0;

    printf("vysledek je %f\n", vysledek);

    return 0;
}
```
Tak dostáváme
```
vysledek je -1.#IND00
```
IND zde znamená indeterminate. Můžeme se taky setkat s hodnotou QNAN (quiet NaN) nebo SNAN (signal NaN). Více informací [zde](https://studiofreya.com/cpp/1-inf-1-ind-and-qnan-floating-point-numbers-and-errors/).

Pokud bychom potřebovali použít hodnotu NaN, tak se nachází konstanta v knihovně `math.h`
```c
double vysledek  = NAN;
```

Ke kontrole, zda je číslo nekonečno můžeme použít funkci `isnan` z knihovny `math.h`.

```c
#include <stdio.h>
#include <float.h>
#include <math.h>

int main()
{
    double vysledek  = 0.0 / 0.0;

    if (isnan(vysledek)) {
        printf("Pravda\n");
    }

    return 0;
}
```


## Odkazy
[Následující kapitola: Makra](./pokrocile-makra.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/21)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Funkce - prototypy](./pokrocile-prototypy.md)
