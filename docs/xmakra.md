---
title: Makra
---


V jazyku C lze definovat tzv. makra. Syntax je 

![makro](./obrazky/makra/makro.png)

Můžeme definovat konstantu `PI`.

```c
#include <stdio.h>

#define PI 3.14

double vrat_obvod_kruhu(double polomer) {
    return 2 * PI * polomer;
}

int main()
{
    double obvod = vrat_obvod_kruhu(2.5);

    printf("Obvod je %lf\n", obvod);

    return 0;
}
```

Makra dokážou definovat i IF strukturu ve formátu

```c
#if vyraz
    // kod
#elif jiny_vyraz
    // kod
#else
    // kod
#endif
```

Ukázka je například tisk podle nastavení konstanty.

```c
#include <stdio.h>

#define TISK_AHOJ 1
#define TISK_NAZDAR 0

int main()
{
    #if TISK_AHOJ
        printf("Ahoj\n");
    #elif TISK_NAZDAR
        printf("Nazdar\n");
    #else
        printf("Zdravim\n");
    #endif

    return 0;
}
```

Se nám vytiskne `Ahoj`.

Konstanta ani nemusí být definovaná (pak se vyhodnotí jako nepravda).
```c
#include <stdio.h>

#define TISK_NAZDAR 1

int main()
{
    #if TISK_AHOJ
        printf("Ahoj\n");
    #elif TISK_NAZDAR
        printf("Nazdar\n");
    #else
        printf("Zdravim\n");
    #endif

    return 0;
}
```

Zde se vytiskne `Nazdar`. Pokud by obě konstanty byly nastavené na 0 nebo nebyly vůbec definované, tak by se nám vytisklo `Zdravim`.

Podobně funguje 
* #ifdef - pokud je definováno
* #ifndef - pokud není definováno
* #elifdef - else if definováno
* #elifndef - else if není definováno


Pomocí makra lze definovat i funkce. Všimněme si, že v makru definujeme proměnné x a y, ale při použití už používáme přímo hodnoty (lze použít i proměnné).
```c
#include <stdio.h>

#define SOUCET(x, y) (x + y)

int main()
{
    int vysledek = SOUCET(4, 10);
    printf("Vysledek je %i\n", vysledek);

    return 0;
}
```

Makra mají své použití ve velmi komplexních programech. V našich programech je můžeme použít pro případy, kdy potřebujeme definovat nějakou konstantu (např. PI).

Více informací najdete [zde](https://devdocs.io/c/preprocessor).