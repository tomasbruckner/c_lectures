---
title: Práce se soubory
---


V našem programu můžeme pracovat i se soubory. Pro otevření používáme funkci `fopen` z knihovny `stdio.h`. Té předáme dva argumenty. První je cesta k souboru a druhý je mód, v jakém daný soubor chceme otevřít. Módy máme následující


| Mód | Vysvětlení | Pokud soubor existuje | Pokud soubor neexistuje |
|---|---|---|---|
| r | otevře soubor ke čtení | začne ho číst od začátku | chyba |
| r+ | otevře soubor ke čtení | začne ho číst od začátku | chyba |
| w | otevře soubor k zápisu | smaže obsah | vytvoří nový soubor |
| w+ | otevře soubor ke čtení a zápisu | smaže obsah | vytvoří nový soubor |
| a | otevře soubor k zápisu na konec (append) | zapíše na konec | vytvoří nový soubor |
| a+ | otevře soubor k zápisu na konec (append) | apíše na konec | vytvoří nový soubor |

Po otevření souboru nám funkce `fopen` vrátí buď NULL, pokud se nepodařilo soubor otevřít (například soubor neexistuje). Nebo vrátí ukazatel na soubor. Říkáme `deskriptor souboru`.

Těchto otevřených deskriptorů souborů může být otevřené najednou jenom omezené množství (liší se dle operačního systému, na Windows zhruba 512 v jednom programu, ale limity se dají navýšit). Proto je potřeba soubor uzavřít, jakmile s ním už nepotřebujeme pracovat. Pokud byste soubor zapomněli zavřít, tak se automaticky uzavře po skončení programu. Pokud jste soubor ale otevřeli pro zápis a nezavřeli ho před skončením programu, tak se může stát, že ztratíte data.

Mějme program, který otevře soubor `C:\Users\tomas\test.txt` ke čtení a přečte z něj každý znak a znova ho vytiskne.

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


## Zápis do souboru
Pokud bychom chtěli zapisovat do soubor, tak nám ho stačí otevřít k zápisu. K samotnému zápisu můžeme použít funkci `putc` z knihovny `stdio.h`. Ta vrací znak, který jsme zapsali a v případě chyby vrací `EOF`. První parametr je znak, který chceme zapsat a druhý parametr je deskriptor souboru.

```c
#include <stdio.h>

int main() {
    FILE * soubor = fopen("C:\\Users\\tomas\\test_zapis.txt", "w");

    if (soubor == NULL) {
        printf("Soubor se nepodarilo otevrit\n");
        return 1;
    }

    char * text = "Mame radi jazyk C\n";

    for (int i = 0; text[i] != '\0' ; i++) {
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

Když ukládáme do souboru, tak je dobré uložit jako poslední znak řádku znak `\n` (nový řádek). Ničemu to asi extra nevadí, když to tak není, ale některé nástroje pro zpracování textu lépe fungují.

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
V programování se bavíme o dvou typech souborů. Binární a textové. Na úrovni uložení dat jsou to pořád jedničky a nuly. Jediný rozdíl je jenom v tom, že kdybyste si soubory otevřeli v textovém editoru, tak binární soubor nedokážete přečíst, ale textový soubor je čitelný.

Je to takové rozdělení spíše pro lidi. Počítačům to je jedno. Má to ale vliv na drobné rozdíly v konce řádků viz níže.


## CRLF vs LF
Konce řádku (anglicky line endings) nejsou stejné na všech operačních systémech. Pro Linux se používá znak `\n` (v ASCII tabulce znak 10 - LF - Line Feed). Starý Mac OS měl pro označení konce řádku znak `\r` (v ASCII tabulce znak 13 - CR - Carriage Return). Windows dokonce používá pro označení konce řádků dva znaky `\r\n`.

Jedná se o věc, která vznikla z historického hlediska, kdy jsme ještě psali na psacích strojích. Tam Line Feed znamenal posuň psací stroj o jeden řádek dolů a Carriage Return znamenal vrať kurzor doleva na začátek papíru.

Dnešní operační systémy jsou už chytřejší a snaží se pracovat s oběma (samotný `\r` už se dnes nepoužívá) typama konce řádků. Proto i když my jsme ukládali do souboru pouze `\n`, tak se ve skutečnosti uložilo `\r\n`, protože C ví, že je na Windows.

Pokud bychom chtěli zapsat na Windows jenom znak `\n` bez automatického `\r`, tak bychom museli otevřít soubor jako binární. To se dělá tak, že k módu přidáme ještě `b`, tzv. pro zápis bychom napsali `"wb"`. Poté když uložíme znak `\n`, tak se uloží opravdu jen tento znak.

