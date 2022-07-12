# Rekurzivní funkce

Rekurzivní funkce je pojmenování pro funkce, které volají samy sebe. Je dobré o nich vědět, protože můžou někdy výrazně zjednodušit řešení problému.
Ukázka rekurzivní funkce je

```c
void rekurze() {
    rekurze();
}
```

Kdybychom takový program spustili, tak se nedočkáme úspěšného konce.

```c
#include <stdio.h>

void rekurze() {
    rekurze();
}

int main()
{
    rekurze();

    return 0;
}
```

Takový program poběží teoreticky nekonečně dlouho. Ve skutečnosti ale programu dojde paměť v počítači a program se ukončí s chybou `stack overflow`. Proto je důležité u každé rekurzivní funkce mít pravidlo, kdy program skončí.

Příkladem rekurzivní funkce může být výpočet faktoriálu. Pro zopakování faktoriálu např. [zde](https://www.matweb.cz/faktorial/).

Pro faktoriál platí
1. pokud n = 0, pak faktoriál se rovná 1
1. jinak platí, že n faktoriál se rovná n krát n - 1 faktoriál (n! = n*(n-1)!)


Pokud se to pokusíme naprogramovat, tak nejdříve si můžeme udělat první podmínku

```c
#include <stdio.h>

int faktorial(int n) {
    if (n == 0) {
        return 1;
    }

    return ...;
}

int main()
{
    int vysledek = faktorial(5);

    return 0;
}
```

To je náše podmínka, která nám zastaví nekonečnou rekurzi. V každé rekurzivní funkci musí být nějaká podmínka, která výpočet zastaví a již znova nezavolá danou funkci.

Nyní můžeme naprogramovat druhou podmínku. Pokud n není 0, tak se má vrátít n * (n - 1)!.

```c
#include <stdio.h>

int faktorial(int n) {
    if (n == 0) {
        return 1;
    }

    return n * faktorial(n - 1);
}

int main()
{
    int vysledek = faktorial(5);
    printf("Vysledek %i\n", vysledek);

    return 0;
}
```

Jak výpočet probíhá?

| Volání  |  Návratová hodnota  | Výsledek  |
|---|---|---|
| faktorial(5) | return 5 * faktorial(4)  | 120  | 
| faktorial(4) | return 4 * faktorial(3)  | 24  | 
| faktorial(3) | return 3 * faktorial(2)  | 6  | 
| faktorial(2) | return 2 * faktorial(1)  | 2  | 
| faktorial(1) | return 1 * faktorial(0)  | 1  | 
| faktorial(0) | return 1  | 1  | 

Obecně programy s rekurzí lze přepsat i jako programy bez rekurze. Tento program by šlo napsat bez použití rekurze například

```c
#include <stdio.h>

int faktorial(int n) {
    int vysledek = 1;

    while (n > 1) {
        vysledek = vysledek * n;
        n = n - 1;
    }

    return vysledek;
}

int main()
{
    int vysledek = faktorial(5);
    printf("Vysledek %i\n", vysledek);

    return 0;
}
```

Některé programy je však mnohem jednodušší napsat pomocí rekurze a bylo by mnohem náročnější je napsat bez rekurze.

Je nutné si dát pozor, že použití rekurze může mít negativní vliv na výkon programu. Velké rekurze si berou hodně zdrojů počítače.