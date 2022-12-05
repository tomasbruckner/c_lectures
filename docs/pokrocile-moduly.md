---
title: Moduly
---

Ve větších programech chceme rozdělit program do více souborů. Pokud bychom měli všechno v jednom souboru, tak jakmile program naroste na tisíce nebo klidně desítky tisíc řádků kódu, tak už by se v něm nikdo nevyznal. K rozdělování na více souborů nám pomáhají moduly.

Každý jeden soubor je samostatný modul. Nebo přesněji ke každému modulu existují dva soubory

1. Hlavičkový soubor (header file), který obsahuje prototypy funkcí (a případně další věci) - soubor s příponou `.h`
2. Soubor obsahující samotnou implementaci - soubour s příponou `.c`


Vytvořme si náš první modul.

Klikneme vlevo nahoře na `New file` a pak vybereme `File...`

![add](./obrazky/moduly/new_file.PNG)

Vybereme `C/C++ source`

![add](./obrazky/moduly/prvni_modul.PNG)

Můžeme dát `Next` a zakliknout `Skip this page next time`

![add](./obrazky/moduly/skip.PNG)


Vybereme jazyk C a klikneme `Next`

![add](./obrazky/moduly/c.PNG)


U `Filename` klikneme napravo na tři tečky a nějak ho pojmenujeme. Například `prvni_modul.c` a klikneme na `Save`

![add](./obrazky/moduly/prvni_module_name.PNG)

A zaklikneme `Debug` i `Release`. Můžeme kliknout `Finish`

![add](./obrazky/moduly/config.PNG)

Objeví se nám obrazovka, zda chceme přidat soubor do projektu. Ano, chceme. Klikneme na `Yes`.

![add](./obrazky/moduly/add_to_project.PNG)


Úplně stejně postupujeme při přidání hlavičkového souboru. Akorát při výběru typu souboru dáme `C/C++ header`

![add](./obrazky/moduly/prvni_header.PNG)

A soubor pojmenujeme stejně jako předchozí soubor, akorát s koncovkou `.h`. V našem případě tedy `prvni_modul.h`. Vybereme opět `Debug` a `Release` a klikneme `Finish`

![add](./obrazky/moduly/config_header.PNG)


V levém menu se nám objeví novou modrá složka `Headers`. Když si náš hlavičkový soubor otevřeme, tak vidíme už předgenerovaný kód.


![add](./obrazky/moduly/codeblocks.PNG)






## Implementace
Do souboru `prvni_modul.c` souboru vložíme naši novou funkci, kterou použijeme k otestování, zda modul funguje správně. Obsah souboru bude vypadat takto

```c
#include <stdio.h>

void tiskni_z_modulu(int cislo_k_tisku) {
    printf("Funkce z modulu ma cislo %i\n", cislo_k_tisku);
}
```


Do hlavičkového souboru `prvni_modul.h` dáme prototyp funkce z `prvni_modul.c`

```c
#ifndef PRVNI_MODUL_H_INCLUDED
#define PRVNI_MODUL_H_INCLUDED

void tiskni_z_modulu(int cislo_k_tisku);

#endif // PRVNI_MODUL_H_INCLUDED
```


Náš `main.c` soubor pak bude obsahovat volání funkce `tiskni_z_modulu`, kterou jsme si vytvořili v našem prvním modulu. Nesmíme zapomenout přidat `#include` našeho hlavičkového souboru
```c
#include "prvni_modul.h"

int main()
{
    tiskni_z_modulu(10);

    return 0;
}
```

Když nyní program pustíme, tak by mělo vše fungovat.

Rozdělování větších programů do menších celků vám může velmi zjednodušit život. Váš program se stane mnohem přehlednější.

Podle čeho poznat, jestli už máme vytvořit nový modul nebo funkci nechat ještě v hlavním souboru. Jestli mít jeden, dva nebo mnohem víc modulů. Jaké funkce dát kam. Vždy se snažte dávat funkce, které nějak logicky patří k sobě do jednoho modulu.

Například pokud bych měl naprogramovat kalkulačku, tak bych se mohl rozhodnout, že si udělám modul `operace`, kde budu mít funkce na sčítání, odečítání, násobení a dělení. Hodně záleží na konkrétním programu a se zkušenostmi. Čím více budete programovat, tím více budete mít cit pro to, kdy už by bylo dobré udělat nějaký nový modul nebo kam dát jakou funkci.
