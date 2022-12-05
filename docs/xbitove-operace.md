---
title: Bitové operace
---


Obecně beru tuto kapitolu jako volitelnou a poměrně nedůležitou. S bitovými operacemi se pravděpodobně nikdy nesetkáte. Není na škodu ale mít aspoň základní přehled, že něco takového vůbec existuje.

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




Popis jednotlivých operací

Mějme dvě čísla

```
0101 (5 v desítkové)
1001 (9 v desítkové)
```

Bitový AND (5 & 9)
```
0101
1001
----
0001 (1 v desítkové)
```


Bitový OR (5 | 9)
```
0101
1001
----
1101 (13 v desítkové)
```

Bitový XOR (5 ^ 9)
```
0101
1001
----
1100 (12 v desítkové)
```



Bitový posun doleva o 2 (9 >> 2)
```
1001
----
0010 (2 v desítkové)
```

Bitový posun doprava o 2 (9 << 2)
```
1001
----
100100 (36 v desítkové)
```

Bitová negace (~5)
```
0101
----
1010 (10 v desítkové)
```

Můžeme si to ověřit

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
Jediný rozdíl je v negaci a vyjde nám ~5 je -6. Je to proto, že pokud pracujeme s int, tak on má 32 bitů (tzv. hodně nul nalevo). Zároveň datový typ má v sobě i negativní čísla, což se dělá pomocí dvojkového doplňku. Více informací třeba [zde](https://portal.matematickabiologie.cz/index.php?pg=zaklady-informatiky-pro-biology--teoreticke-zaklady-informatiky--teorie-cisel--dvojkovy-doplnek)

