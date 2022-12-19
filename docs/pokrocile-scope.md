---
title: Scope
---

V předchozích kapitolách jsme si ukázali, že nelze definovat v jedné funkci dvě proměnné se stejným názvem. Jednalo se však o zjednodušení a nebylo to přesné. Ve skutečnosti platí, že nesmí být dvě stejně pojmenované proměnné ve stejném `bloku` kódu.

Blok je určen složenými závorkami. Tzv. funkce je jeden blok kódu. If je další blok kódu.

Následující program je naprosto validní

```c
#include <stdio.h>

int main()
{
    int x = 3;

    if (x > 5) {
        int x = 2;
    }

    return 0;
}
```

Zde vidíme, že jsme v jedné funkci definovali dvakrát proměnnou `x`. To nevadí, protože každý je v jiném bloku kódu.

První blok je
```c
{
    int x = 3;

    if (x > 5) {
        int x = 2;
    }

    return 0;
}
```

Druhý (vnořený) blok je 
```c
if (x > 5) {
    int x = 2;
}
```

Každý blok má svoji vlastní proměnnou + může používat proměnné z vnějších bloků (kam aktuální blok patří).
```c
#include <stdio.h>

int main()
{
    int x = 3;
    int y = 2;

    if (x < 5) {
        int x = 2;
        printf("x je %i, y je %i\n", x, y);
        x = 5;
        y = 5;
        printf("x je %i, y je %i\n", x, y);
    }

    printf("x je %i, y je %i\n", x, y);

    return 0;
}
```

Program tiskne 

```
x je 2, y je 2
x je 5, y je 5
x je 3, y je 5
```

Jak se program vykoná
1. Vytvoří se proměnná `x` datového typu `int` a nastaví se na 3 - první blok
1. Vytvoří se proměnná `y` datového typu `int` a nastaví se na 2  - první blok
1. Zkontroluje se podmínka v IF, `x` (3) je menší než 5 - ano je
1. Vytvoří se proměnná `x` datového typu `int` a nastaví se na 2 - druhý blok
1. Vytiskne se `x je 2, y je 2`
    - `x` proměnná se hledá v aktuálním bloku (druhý blok - IF) - v tomto bloku je proměnná `x` definována, použije se tato hodnota
    - `y` proměnná se hledá v aktuálním bloku (druhý blok - IF) - v tomto bloku není proměnná `y` definována, hledá se ve vnějším bloku (funkce `main`), zde je proměnná `y` definována, použije se tato hodnota
1. `x` proměnná se hledá v aktuálním bloku (druhý blok - IF) - v tomto bloku je `x` definována, použije se tato proměnná a nastaví se na 5
1. `y` proměnná se hledá v aktuálním bloku (druhý blok - IF) - v tomto bloku není definována, hledá se ve vnějším bloku (první blok - funkce `main`), zde je definována použije se tato proměnná a nastaví se na 5
1. Vytiskne se `x je 5, y je 5`
    - `x` proměnná se hledá v aktuálním bloku (druhý blok - IF) - v tomto bloku je `x` definována, použije se tato hodnota
    - `y` proměnná se hledá v aktuálním bloku (druhý blok - IF) - v tomto bloku není `y` definována, hledá se ve vnějším bloku (funkce `main`), zde je `y` definována, použije se tato hodnota
1. Vytiskne se `x je 3, y je 5`
    - `x` proměnná se hledá v aktuálním bloku (první blok - funkce `main`) - v tomto bloku je `x` definována, použije se tato hodnota
    - `y` proměnná se hledá v aktuálním bloku (první blok - funkce `main`) - v tomto bloku je `y` definována, použije se tato hodnota
1. `return 0` ukončuje program


Pokud bychom měli program
```c
#include <stdio.h>

int main()
{
    int x = 3;

    if (x < 5) {
        int z = 2;
    }

    if (x < 7) {
        printf("z je %i\n", z);
    }

    return 0;
}
```

Tak dostáváme chybu `'z' undeclared (first use in this function)`, `z` není definováno.

Máme zde tři bloky
1. funkce `main`
1. první if (x < 5)
1. druhý if (x < 7)

Proč ve třetím bloku je proměnná `z` nedefinována? Postup hledání proměnné je, že pokud nenajdu proměnnou v aktuálním bloku, tak se dívám do vnějších bloků, kam aktuální blok patří. Třetí blok patří do bloku prvního, ale nepatří do bloku druhého. Aby kód fungoval, musel by třetí blok být uvnitř druhého bloku. Např.
```c
#include <stdio.h>

int main()
{
    int x = 3;

    if (x < 5) {
        int z = 2;

        if (x < 7) {
            printf("z je %i\n", z);
        }
    }

    return 0;
}
```
Nyní už chybu nedostáváme a vše funguje správně.

- První blok může hledat jenom v sobě samém.
- Druhý blok hledá v sobě a ve funkci main.
- Třetí blok hledá v sobě, v druhém bloku a v prvním bloku

Podobně bychom měli chybu v tomto případě
```c
#include <stdio.h>

int main()
{
    int x = 3;

    if (x < 5) {
        if (x < 7) {
            int z = 2;
        }

        printf("z je %i\n", z);
    }

    return 0;
}
```

Proměnná `z` je sice definovaná, ale ve vnitřním bloku. Druhý blok tedy proměnnou nedokáže použít (říkáme, že na ni nevidí).

Dále je potřeba si dát pozor na následující případ
```c
#include <stdio.h>

int main()
{
    int x = 3;

    if (x < 5) {
        x = 5;
        int x = 2;
        x = 10;
    }

    printf("x je %i\n", x);

    return 0;
}
```
Program tiskne
```
x je 5
```

Proč? Protože v době, kdy se provede `x = 5` ještě není proměnná v bloku IF definovaná. Použije se tedy proměnná z vnějšího bloku. Přiřazení `x = 10` se již provede pro proměnnou uvnitř bloku IF. 


Totožná logika platí i pro `Switch` (a libovolné další bloky).


## Blok cyklu
Obdobně to platí i pro cykly. U cyklu for je potřeba si dát pozor, že i proměnná definovaná v inicializační části se bere jako součást bloku cyklu. V následujícím případě je tedy proměnná `i` nedefinovaná.
```c
#include <stdio.h>

int main()
{
    for (int i = 0; i < 2; i = i + 1) {
    }

    printf("i je %i\n", i);

    return 0;
}
```

## Obecný blok
V jazyku C je možné definovat obecný blok. Slouží k izolaci proměnných dle logiky výše. Ten se definuje slouženými závorkami. V následujícím programu máme blok uvnitř funkce `main`, ve kterém definujeme `int x = 5;`. Poslední příkaz bloku je tisk `printf("x uvnitr bloku je %i\n", x);`

```c
#include <stdio.h>

int main()
{
    int x = 3;

    {
        int x = 5;
        x = 10;
        printf("x uvnitr bloku je %i\n", x);
    }

    printf("x je %i\n", x);

    return 0;
}
```

Program tiskne
```
x uvnitr bloku je 10
x je 3
```

Obecně se s obecným blokem v programování asi moc často nepotkáte. Je zde jenom pro ilustraci, že něco takového existuje.


## Globální proměnná
V našem progamu máme ještě jeden blok, který obsahuje všechny ostatní bloky. A to je program samotný. V něm se také dají definovat takzvané `globální` proměnné.

```c
#include <stdio.h>

int x = 3;

int main()
{
    printf("x je %i\n", x);

    return 0;
}
```
Zde jsme definovali globální proměnnou `x`. Můžeme k ní přistoupit z libovolné funkce.
```c
#include <stdio.h>

int x = 3;

void zmen_globalni_hodnotu() {
    x = 10;
}

int main()
{
    printf("x je %i\n", x);
    zmen_globalni_hodnotu();
    printf("x je %i\n", x);

    return 0;
}
```

Vytiskne
```
x je 3
x je 10
```

Platí zde klasické pravidlo proměnných a bloků.

```c
#include <stdio.h>

int x = 3;

void zmen_globalni_hodnotu() {
    int x = 5;
    x = 10;
}

int main()
{
    printf("x je %i\n", x);
    zmen_globalni_hodnotu();
    printf("x je %i\n", x);

    return 0;
}
```

Tiskne

```
x je 3
x je 3
```

Protože ve funkci `zmen_globalni_hodnotu` jsme pracovali s lokální proměnnou bloku funkce (ne s globální).

Obecně byste se měli snažit globální proměnné nepoužívat. V hodně případech jsou známka špatného kódu. Proč? Protože když budete používat nějaké funkce a ony budou pracovat a případně měnit globální proměnné, tak vám můžou ve větších programech vznikat chyby, které bude těžké zjistit, odkud vznikají. A může to být jenom proto, že jednou se zavolala nějaká funkce, která změnila něco globálního a podruhé ne.

U globálních proměnných je ve větších programech problém, že nevíte, které funkce s ní pracují a které ji modifikují.

## Odkazy
[Následující kapitola: Moduly](./pokrocile-moduly.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/28)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Dekompozice programu](./pokrocile-dekompozice.md)
