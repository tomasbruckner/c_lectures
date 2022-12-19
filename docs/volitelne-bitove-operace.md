---
title: Bitové operace
---

S bitovými operacemi se pravděpodobně nikdy nesetkáte. Není na škodu ale mít alespoň základní přehled, že něco takového vůbec existuje.

Jazyk C má speciální operátory na práci s bitama. Pro zopakování dvojkové soustavy například [zde](https://cs.khanacademy.org/computing/informatika-pocitace-a-internet/x8887af37e7f1189a:digitalni-informace/x8887af37e7f1189a:binarni-cislo/a/bits-and-binary).

Podporované jsou následující operátory

| Operátor | Název | Ukázka | 
|---|---|---|
| ~ | bitová negace | ~x |
| & | bitový AND | x & y |
| \| | bitový OR | x \| y |
| ^ | bitový XOR | x ^ y |
| << | bitový posun doleva  | x << y  |
| >> | bitový posun doprava  | x >> y  |


Mějme dvě dvoubitové čísla

```
0101 (5 v desítkové soustavě)
1001 (9 v desítkové soustavě)
```

Bitový AND (5 & 9) funguje tak, že první bit prvního čísla udělá AND operaci s prvním bitem druhého čísla. Pak druhý bit prvního čísla udělá AND s druhým bitem druhého čísla atd.
```
0101
1001
----
0001 (1 v desítkové soustavě)
```
Pro náš příklad je výsledek `0001`, protože první bit obou čísel je 1.


Bitový OR (5 | 9) funguje tak, že první bit prvního čísla udělá OR operaci s prvním bitem druhého čísla. Pak druhý bit prvního čísla udělá OR s druhým bitem druhého čísla atd.
```
0101
1001
----
1101 (13 v desítkové soustavě)
```

Bitový XOR (5 ^ 9) funguje tak, že první bit prvního čísla udělá XOR operaci s prvním bitem druhého čísla. Pak druhý bit prvního čísla udělá XOR s druhým bitem druhého čísla atd. Pro zopakování XOR funguje tak, že výsledek je 1 právě tehdy, pokud právě jeden z operandů je 1. Pokud jsou oba 0 nebo oba 1, tak je výsledek 0.
```
0101
1001
----
1100 (12 v desítkové soustavě)
```



Bitový posun doleva o 2 (9 >> 2) je operace, která posune všechny bity doleva o x (v našem případě o 2). Bity na levém kraji se zahazují.
```
1001
----
0010 (2 v desítkové soustavě)
```
Zde se nejdříve provede jeden posun a z `1001` se stane `0100`. Následně se provede druhý posun a z `0100` se stane `0010`. 


Bitový posun doprava o 2 (9 << 2) funguje opačně jako bitový posun doleva.
```
1001
----
100100 (36 v desítkové soustavě)
```
Zde se nejdříve provede jeden posun a z `1001` se stane `10010`. Následně se provede druhý posun a z `10010` se stane `100100`. 


Bitová negace (~5) funguje tak, že se obrátí všechny bity na opačnou hodnotu. Jedná se o unární operátor (pracuje jenom s jednou hodnotou).
```
0101
----
1010 (10 v desítkové soustavě)
```

Můžeme si všechny operace ověřit v následujícím programu

```c
#include <stdio.h>

int main() {
    printf("5 & 9 je %i\n", 5 & 9);
    printf("5 | 9 je %i\n", 5 | 9);
    printf("5 ^ 9 je %i\n", 5 ^ 9);
    printf("9 >> 2 je %i\n", 9 >> 2);
    printf("9 << 2 je %i\n", 9 << 2);
    printf("~5 je %i\n", ~5);

    return 0;
}
```

Dostáváme

```
5 & 9 je 1
5 | 9 je 13
5 ^ 9 je 12
9 >> 2 je 2
9 << 2 je 36
~5 je -6
```

Jediný rozdíl je v negaci a vyjde nám, že `~5` je `-6`. Je to proto, že pokud pracujeme s `int`, tak on má 32 bitů (tzv. hodně nul nalevo). Zároveň datový typ `int` má v sobě i negativní čísla, což se dělá pomocí **dvojkového doplňku**. Více informací třeba [zde](https://portal.matematickabiologie.cz/index.php?pg=zaklady-informatiky-pro-biology--teoreticke-zaklady-informatiky--teorie-cisel--dvojkovy-doplnek)

Můžeme si pomoct, když vytiskneme negaci jako `unsigned int`

```c
#include <stdio.h>

int main() {
    printf("~5 je %u\n", ~5);

    return 0;
}
```
Nyní dostáváme

```
~5 je 4294967290
```

Což pro 32 bitů sedí.

## Odkazy
[Následující kapitola: Závorky](./volitelne-zavorky.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/43)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Zkrácené vyhodnocení](./volitelne-zkracene-vyhodnoceni.md)
