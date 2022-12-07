---
title: Závorky
---

V této kapitole si představíme koncept, že některé závorky v jazyku C nejsou povinné.

Mějme jednoduchou IF strukturu

```c
if (x > 10) {
    printf("X je vetsi nez 10\n");
}
```

Pro jazyk C platí, že pokud má IF struktura jenom jeden příkaz, tak můžeme závorky vynechat. Dostáváme tedy

```c
if (x > 10)
    printf("X je vetsi nez 10\n");
```

Jazyk C je poměrně volný v psaní mezer (viz kapitola XXX), tak můžeme udělat daný zápis i na jeden řádek

```c
if (x > 10) printf("X je vetsi nez 10\n");
```

Případně nemusíte udělat ani odsazení příkazu v IF struktuře

```c
if (x > 10)
printf("X je vetsi nez 10\n");
```

Rád bych připomněl, že i když něco udělat jde, tak to neznamená, že bychom to měli udělat.

Zde je potřeba dát si pozor, že pokud nepoužijete závorky a napíšete více příkazů, tak v IF struktuře bude pouze ten první. Můžeme si to demonstrovat následovně

```c
if (x > 10)
    printf("Uvnitr IF\n");
    printf("Mimo IF\n");
```

V tomto případě se tisk `Mimo IF` **provede vždy nezávisle na tom, jestli je podmínka pravdivá nebo nepravdivá**. Stejně tomu bude v případě

```c
if (x > 10)
    printf("Uvnitr IF\n"); printf("Mimo IF\n");
```

Nebo

```c
if (x > 10) printf("Uvnitr IF\n"); printf("Mimo IF\n");
```

Pokud budeme mít následující program
```c
#include <stdio.h>

int main() {
    int x = 5;
    if (x > 10) printf("Uvnitr IF\n"); printf("Mimo IF\n");

    return 0;
}
```

Tak dostáváme varování
```
...\main.c|5|warning: this 'if' clause does not guard... [-Wmisleading-indentation]|
...\main.c|5|note: ...this statement, but the latter is misleadingly indented as if it were guarded by the 'if'
```

Tím se nás kompilátor snaží upozornit, že druhé volání funkce `printf` se provede vždy.

Obdobné chování platí i cykly. Pokud máme jenom jeden příkaz, tak můžeme složené závorky vynechat

```c
while (x > 10)
    printf("Uvnitr while\n");
```

Ale opět se nám může stát, že si neuvědomí, že druhý příkaz je mimo cyklus.

Následující program poběží někonečně, protože inkrementace je mimo cyklus.

```c
#include <stdio.h>

int main() {
    int x = 0;
    while (x < 5)
        printf("Uvnitr while\n");
        x = x + 1;

    return 0;
}
```

Často se stává, že například IF podmínka začne jako jeden příkaz, tak to lidi napíšou bez závorek

```c
if (x > 10)
    printf("Uvnitr IF\n");
```

Časem je ale potřeba přidat druhý příkaz do IF struktury. V lepší případě tam budou muset závorky stejně dopsat (to je mohli napsat na začátku)-
```c
if (x > 10) {
    printf("Uvnitr IF\n");
    printf("Uvnitr IF\n");
}
```

V horším případě zapomenout závorky přídat a dostávájí špatné chování
```c
if (x > 10)
    printf("Uvnitr IF\n");
    printf("Uvnitr IF\n");
```

Moje osobní doporučení je **používat závorky vždy**, ale každý to může vnímat jinak a je to čistě subjektivní záležitost.

