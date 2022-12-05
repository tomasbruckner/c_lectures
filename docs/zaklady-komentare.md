---
title: Komentáře
---


Komentář je část zdrojového kódu, který nemá žádný vliv na výsledný program. Při zpracování programu se komentáře ignorují. K čemu tedy slouží? Jejich smysl je vysvětlit lidem, co se v programu děje. V jazyku C máme dva typy komentářů:
1. Řádkový
1. Blokový

Komentářů může být libovolný počet ve zdrojovém kódu (ať řádkových, blokových nebo kombinace).

## Řádkový komentář
Řádkový komentář začíná dvěma lomítkama a od těchto dvou znaků až do konce řádku je vše komentář.

```c
#include <stdio.h>

// komentar u main
int main()
{
    printf("Hello world!\n"); // toto je komentar
    return 0;  // toto je take komentar
}
```
Tento program je ekvivalentní následujícímu, jelikož se komentáře ignorují.
```c
#include <stdio.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
```

Je však velký rozdíl mezi programem
```c
#include <stdio.h>

int main()
{
    int x = 5; // toto je komentar
    printf("Hodnota: %i\n", x);
    return 0;
}
```
a programem

```c
#include <stdio.h>

int main()
{
    // int x = 5; toto je komentar
    printf("Hodnota: %i\n", x);
    return 0;
}
```

V prvním příkladě vše funguje v pořádku, ale v druhém jsme zakomentovali definici proměnné, což způsobí chybu a program se nespustí.


## Blokový komentář
Druhým typem komentářů je tzv. blokový komentář. ten začíná znaky **/\*** a končí znaky **\*/**. Vše mezi těmito znaky je bráno jako komentář.

```c
#include <stdio.h>

/*
 Zde je muj prvni
 blokovy komentar
 na vice radku.
*/

int main()
{
    printf("Hello world!\n");
    /* Zde je muj druhy komentar na 
     vice
    radku */
    return 0; /* blokovy komentar lze mit i i na jednom radku */
}
```

Blokový komentář lze použít i na nestandardních místech. Např.

```c
#include <stdio.h>

int main()
{
    printf /* komentar */ ("Hello world!\n" /* komentar */);
    return  /* komentar */ 0;
}
```

Jelikož se komentáře ignorují, tak je tento program ekvivalentní následujícímu

```c
#include <stdio.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
```
Zde bych upozornil, že i když něco lze udělat, tak je dobré se zamyslet, jestli by se to mělo udělat. To že můžeme dát komentář na libovolné místo, tak to neznamená, že bychom to měli dělat.

## Kde a jak použít komentáře?
Komentář byste měli zatím používat jako poznámku pro sebe. Pokud je nějaký kus kódu složitý, tak si můžete napsat poznámku, která daný kus kódu pomůže vysvětlit. To se může hodit, když se vrátíte po měsíci k rozpracovanému programu. Nebudete se pak (tolik) divit, co se v programu děje.

Také je potřeba dávat pozor na zbytečné komentáře. Někteří lidé to s komentáři přehánějí a píšou ho na každý řádek zdrojového kódu. To se může hodit pro úplné začátečníky, ale jak se stanete lepším a lepším programátorem, tak zbytečně moc komentářů můžou udělat zdrojový kód naopak méně přehledným.

Ukázka špatného komentáře může být např.

```c
#include <stdio.h>  // zde pridavam knihovnu na printf

/*
  Toto je muj prvni program, ktery vytiskne hodnotu 15
*/
int main()
{
    int x = 10; // zde se vytvori promenna x a nastavi se ji hodnota na 10
    x = 15; // zde se nastavi hodnota promenne x na hodnotu 15
    printf("Hodnota: %i\n", x); // zde se vytiskne hodnota 15

    // tento radek ukonci program
    return 0;
}
```

Proč se jedná o špatné komentáře? Pro návody to dává smysl. Čeká se, že ten kdo čte daný návod může být i naprostý začátečník.
Ve vašem programu ale píšete komentáře pro zkušenější programátory a ti určitě budou vědět, že řádek `int x = 10;` vytvoří proměnnou x a nastaví ji hodnotu na 10.

Jaký je správný počet komentářů ve zdrojovém kódu? Často nemusí dávat smysl mít ani jeden komentář. S komentáři platí pravidlo, že méně je často více.

Obecné pravidlo pro zkušenější programátory platí, že komentář by neměl popisovat **co** program dělá, ale měl by vysvětlovat **proč**. Co program dělá většinou není těžké zjistit. Když pojedete řádek po řádku, tak pochopíte, že tady se vytvoří tahle proměnná a tady se nastaví tato hodnota. Často však nemusí být jasné proč se programátor rozhodnul kód naprogramovat tak, jak to udělal. Například něco naprogramoval sám a nepoužil již hotovou funkci z toho důvodu, že je v již hotové funkci chyba a nedokáže ji sám opravit. Nebo ho nenapadlo lepší řešení.

Další velký problém s komentáři je ten, že můžou často zastarávat. To se týká především těch, které popisují **co** se děje a ne **proč**. Pokud bychom se v předchozím příkladě rozhodli, že můžu proměnnou x rovnou nastavit na 15, tak se mi může stát, že zapomenu opravit komentář. Pak dostanu program.

```c
int x = 15; // zde se vytvori promenna x a nastavi se ji hodnota na 10
```

A již zde dochází k problému, že komentář říká něco jiného, než co ukazuje kód. Jedná se samozřejmě o velmi zjednodušený příklad, ale za svoji programátorskou praxi jsem se setkal již s mnoha komentáři, které komentovaly kód, který již neexistuje a byl přepsán na jiný.

Samozřejmě někdy jsou nejaké části kódu složité a dává smysl i komentář, který vysvětluje, co se děje. V programování bohužel není nic černé nebo bílé a je potřeba si pro to vybudovat cit.


Obecně je dobré o komentářích vědět, ale **zatím bych se jima moc netrápil**. Jak psát dobře komentáře (a samozřejmě i kód) je něco, co přijde až s praxí. Jakmile něco naprogramujete a o něco později se k tomu vrátite, tak pokud si řeknete, že tahle část vám vůbec nedává smysl, tak je to pro vás zpětná vazba, že tady měl být asi vysvětlující komentář. Naopak pokud vám některé komentáře přijdou naprosto zbytečné, tak je asi nedávalo smysl vůbec psát.

## Úkoly na procvičení
### Úkol 1
Upravte následující program pomocí **řádkových komentářů**, aby se vytisklo
```
Hodnota je 2
```

```c
#include <stdio.h>

int main()
{
    int x = 1;
    int x = 2;
    printf("Hodnota je %i\n", x);
    int x = 3;
    return 0;
}
```

<details>
  <summary>Klikni pro zobrazení možného řešení</summary>

```c
#include <stdio.h>

int main()
{
    // int x = 1;
    int x = 2;
    printf("Hodnota je %i\n", x);
    // int x = 3;
    return 0;
}
```
</details>

### Úkol 2
Upravte následující program pomocí **blokových komentářů**, aby se vytisklo
```
Hodnota je 2
```

```c
#include <stdio.h>

int main()
{
    int x = 1;
    int x = 2;
    printf("Hodnota je %i\n", x);
    int x = 3;
    return 0;
}
```

<details>
  <summary>Klikni pro zobrazení možného řešení</summary>

```c
#include <stdio.h>

int main()
{
    /* int x = 1; */
    int x = 2;
    printf("Hodnota je %i\n", x);
    /* int x = 3; */
    return 0;
}
```
</details>

## Fun fact
Názvy knihoven *stdio* a *stdlib* nejsou jenom nějaké náhodne písmenka poskládány k sobě.

* **stdio** = standard input output (std i/o) - obsahuje funkce pro práci se vstupy (co uživatel píše na klávesnici) a výstupy (tisknutí textu na obrazovku)
* **stdlib** = standard library (std lib) - obsahuje nejčastěji používané funkce (řazení, práce s pamětí, generování náhodných čísel atd.)

Stejně tak ve funkci *printf* není to f náhodně. Print znamená v angličtině tisk a **f** je zkratka pro *formatted*. Funkce printf je tedy pro formátovaný tisk.
