---
title: Funkce - prototypy
---


Při psaní programu se nám může stát následující problém.

```c
#include <stdio.h>

int main()
{
    tisk();

    return 0;
}

void tisk() {
}
```

Když program spustíme, tak program končí s chybou

![prototyp implicit error](./obrazky/prototypy/error_implicit_definition.PNG)


Na řádku 6 se snažíme volat funkci `tisk`, která není definovaná. A na řádku 11 se snažíme definovat funkci `tisk` znova.

To je způsobeno tím, že před prvním použitím funkce `tisk` je potřeba funkci `tisk` definovat. Problém se opraví tím, že přesuneme funkci `tisk` před funkci `main`.

```c
#include <stdio.h>

void tisk() {
}

int main()
{
    tisk();

    return 0;
}
```

Existuje však i ještě jiné řešení. Můžeme definovat `prototyp funkce`. Prototyp funkce obsahuje návratový typ funkce, její název a parametr. Neobsahuje tedy tělo funkce. Prototyp funkce navíc končí středníkem. Příkladem je

```c
void tisk();
```

Tímhle dáváme programu najevo, že existuje taková funkce a bude definována až později. V našem programu by to pak vypadalo následovně 

```c
#include <stdio.h>

void tisk();

int main()
{
    tisk();

    return 0;
}

void tisk() {
}
```

Prototypem funkce `tisk` se nám problém vyřešil. Je nutné nezapomenout na definici funkce včetně těla funkce. Pokud bychom to neudělali a funkci `tisk` nedefinovali a nechali v našem programu jenom prototyp funkce `tisk`

```c
#include <stdio.h>

void tisk();

int main()
{
    tisk();

    return 0;
}
```

Program končí s chybou

![missing reference](./obrazky/prototypy/error_missing_reference.PNG)

Na řádku 7 se používá funkce, ale není nikde definovaná.

## Volání dvou funkcí navzájem
Prototypy funkcí také řešení situaci, kdy se dvě funkce volají navzájem.

```c
#include <stdio.h>

void tisk_vetsi(int cislo_k_tisku) {
    if (cislo_k_tisku >= 0) {
        printf("Tisknu vetsi\n");
    } else {
        tisk_mensi(cislo_k_tisku);
    }
}

void tisk_mensi(int cislo_k_tisku) {
    if (cislo_k_tisku <= 0) {
        printf("Tisknu mensi\n");
    } else {
        tisk_vetsi(cislo_k_tisku);
    }
}

int main()
{
    tisk_vetsi(-5);

    return 0;
}
```

Opět zde máme problém, že voláme funkci `tisk_mensi` předtím, než ji definujeme. Zde si však nepomůžeme, když prohodíme definice funkcí `tisk_mensi` a `tisk_vetsi`.

Situaci vyřešíme použitím prototypů

```c
#include <stdio.h>

void tisk_vetsi(int cislo_k_tisku);
void tisk_mensi(int cislo_k_tisku);

void tisk_vetsi(int cislo_k_tisku) {
    if (cislo_k_tisku >= 0) {
        printf("Tisknu vetsi\n");
    } else {
        tisk_mensi(cislo_k_tisku);
    }
}

void tisk_mensi(int cislo_k_tisku) {
    if (cislo_k_tisku <= 0) {
        printf("Tisknu mensi\n");
    } else {
        tisk_vetsi(cislo_k_tisku);
    }
}

int main()
{
    tisk_vetsi(-5);

    return 0;
}
```

Nyní už program funguje správně.