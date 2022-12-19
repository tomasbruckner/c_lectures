---
title: Práce se soubory
---

V našich programech bychom chtěli pracovat i se soubory. Pro otevření souboru používáme funkci `fopen` z knihovny `stdio.h`. Té předáme dva argumenty. První je cesta k souboru a druhý je mód, v jakém daný soubor chceme otevřít. Módy máme následující


| Mód | Vysvětlení | Pokud soubor existuje | Pokud soubor neexistuje |
|---|---|---|---|
| r | otevře soubor ke čtení (read) | začne ho číst od začátku | chyba |
| r+ | otevře soubor ke čtení (read) | začne ho číst od začátku | chyba |
| w | otevře soubor k zápisu (write) | smaže obsah | vytvoří nový soubor |
| w+ | otevře soubor ke čtení a zápisu (write) | smaže obsah | vytvoří nový soubor |
| a | otevře soubor k zápisu na konec (append) | zapíše na konec | vytvoří nový soubor |
| a+ | otevře soubor ke čtení a zápisu na konec (append) | zapíše na konec | vytvoří nový soubor |

Po otevření souboru nám funkce `fopen` vrátí buď NULL, pokud se nepodařilo soubor otevřít (například soubor neexistuje). Nebo vrátí ukazatel na soubor (říkáme `deskriptor souboru`).

Těchto otevřených deskriptorů souborů může být otevřených najednou pouze omezené množství (liší se dle operačního systému, na Windows zhruba 512 v jednom programu, ale limity se dají navýšit). Proto je potřeba soubor uzavřít, jakmile se souborem už nepotřebujeme pracovat. Pokud byste soubor zapomněli zavřít, tak se automaticky uzavře po skončení programu. Pokud jste soubor ale otevřeli pro zápis a nezavřeli ho před skončením programu, tak se může stát, že ztratíte data, které jste do souboru zapsali.

Mějme program, který otevře soubor `C:\Users\tomas\test.txt` ke čtení a přečte z něj každý znak a každý znak vytiskne.

```c
#include <stdio.h>

int main() {
    FILE * soubor = fopen("C:\\Users\\tomas\\test_cteni.txt", "r");

    if (soubor == NULL) {
        printf("Soubor se nepodarilo otevrit\n");
        return 1;
    }

    char c = getc(soubor);

    while(c != EOF) {
        printf("%c ", c);
        c = getc(soubor);
    }
 
    fclose(soubor);

    return 0;
}
```

Setkáváme se zde s novou funkcí a konstantou. Funkce `getc` nám vrátí jeden znak z otevřeného souboru a posune deskriptor o jeden znak dále. To znamená, že jakmile zavoláme funkci poprvé, tak se nám vrátí první znak soubor. Jakmile ji zavoláme podruhé, tak se vrátí už druhý znak atd. Pokud jsme dočetli soubor až na konec, tak funkce vrátí konstantu `EOF`.

Všimněme si, že pokud je soubor `NULL`, tak ukončujeme program s `return 1` místo klasického `return 0`. Obecně v programech platí, že pokud program skončí úspěšně, tak by měl vrátit hodnotu `0`. Pokud dojde k chybě, tak by měl vrátit cokoliv jiného, než je `0`. V našem případě tedy `1`.

Různé hodnoty můžou znamenat různé chybové kódy. Například
* 1 - nepodařilo se načíst soubor (`return 1`)
* 2 - soubor je prázdný (`return 2`)
* 3 - neznámá chyba (`return 3`)

Díky těmto chybovým kódům dokážeme dát uživateli extra informaci, proč náš program nefunguje tak, jak by uživatel chtěl.


## Zápis do souboru
Pokud bychom chtěli zapisovat do soubor, tak nám stačí soubor otevřít k zápisu. K samotnému zápisu můžeme použít funkci `putc` z knihovny `stdio.h`. Ta vrací znak, který jsme zapsali a v případě chyby vrací `EOF`. První parametr je znak, který chceme zapsat a druhý parametr je deskriptor souboru.

```c
#include <stdio.h>

int main() {
    FILE * soubor = fopen("C:\\Users\\tomas\\test_zapis.txt", "w");

    if (soubor == NULL) {
        printf("Soubor se nepodarilo otevrit\n");
        return 1;
    }

    char * text = "Mame radi jazyk C\n";

    for (int i = 0; text[i] != '\0' ; i = i + 1) {
        char vysledek = putc(text[i], soubor);
        if (vysledek == EOF) {
            printf("Nepodarilo se ulozit znak\n");
            fclose(soubor);
            return 1;
        }
    }
 
    fclose(soubor);

    return 0;
}
```

Když ukládáme data do souboru, tak je dobré uložit jako poslední znak `\n` (nový řádek). Ničemu to asi extra nevadí, když to tak neuděláme, ale některé nástroje pro zpracování textu pak lépe fungují.

Pokud bychom nechtěli zapisovat po jednom znaku, tak můžeme použít funkci `fprintf`. Ta vrátí počet zapsaných znaků nebo záporné číslo, pokud došlo k chybě.

```c
#include <stdio.h>

int main() {
    FILE * soubor = fopen("C:\\Users\\tomas\\test_zapis.txt", "w");

    if (soubor == NULL) {
        printf("Soubor se nepodarilo otevrit\n");
        return 1;
    }

    int vysledek = fprintf(soubor, "Mame radi jazyk C\n");
    fclose(soubor);

    if (vysledek < 0) {
        printf("Nepodarilo se ulozit text\n");
        return 1;
    }

    return 0;
}
```

## Binární a textové soubory
V programování se bavíme o dvou typech souborů. `Binární` a `textové`. Na úrovni uložení dat jsou to pořád jedničky a nuly. Jediný rozdíl je jenom v tom, že kdybyste si soubory otevřeli v textovém editoru, tak binární soubor nedokážete přečíst, ale textový soubor je čitelný.

Je to rozdělení spíše pro lidi. Počítačům je to jedno, jestli pracují s binárním nebo textovým souborem. V jazyku C to však má vliv na konce řádků viz níže.


## CRLF vs LF
Konce řádku (anglicky line endings) nejsou stejné na všech operačních systémech. Pro Linux se používá znak `\n` (v ASCII tabulce znak 10 - LF - Line Feed). Starý Mac OS měl pro označení konce řádku znak `\r` (v ASCII tabulce znak 13 - CR - Carriage Return). Windows dokonce používá pro označení konce řádků dva znaky `\r\n`.

Jedná se o věc, která vznikla z historického hlediska, kdy jsme ještě psali na psacích strojích. Tam Line Feed (LF) znamenal posuň psací stroj o jeden řádek dolů a Carriage Return (CR) znamenal vrať kurzor doleva na začátek papíru.

Dnešní operační systémy jsou už chytřejší a snaží se pracovat s oběma typama konce řádků, tzv. s CRLF i LF. Samotný `\r` (jak to měl starý Mac OS) se dnes již nepoužívá.

Když uložíme do souboru `\n` na Windows, tak se ve skutečnosti uloží `\r\n`, protože C ví, že je na Windows.

Pokud bychom chtěli zapsat na Windows jenom znak `\n` bez automatického `\r`, tak bychom museli otevřít soubor jako binární. To se dělá tak, že k módu přidáme ještě znak `b`, tzv. pro zápis bychom napsali `"wb"` místo `"w"`. Poté když uložíme znak `\n`, tak se uloží opravdu jen tento znak i na Windows.



## Odkazy
[Zpátky na přehled](./index.md)

[Předchozí kapitola: Struktury](./zaklady-struktury.md)

[Následující kapitola: Práce s argumenty programu](./zaklady-argumenty.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/18)
