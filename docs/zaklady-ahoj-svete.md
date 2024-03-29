---
title: První program - Ahoj světe!
---

Začněme s naším prvním programem. Následující zdrojový kód (= kód programu) je velmi známý a má dokonce své vlastní jméno. Nazývá se `Hello world!` (česky Ahoj světe!). Kód vypadá následovně

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
```

Co tento program dělá? Vytiskne na obrazovku **Hello world!** a ukončí se. Zkusme si tento program vytvořit a úspěšně spustit v CodeBlocks. Tím ověříme, že se vše nainstalovalo v pořádku.

Jak na to v CodeBlocks? 

1. Klikneme na modrý text "Create a new project" uprostřed obrazovky pod logem Code::Blocks
![vytvoření projektu](./obrazky/ahoj_svete/create_project.PNG)

2. Vybereme "Console application" a klikneme Go
![template](./obrazky/ahoj_svete/template.PNG)

3. Dále klikneme na Next (a můžeme zaškrtnout Skip this page next time)
![skip](./obrazky/ahoj_svete/skip.PNG)

4. Vybereme C
![c](./obrazky/ahoj_svete/c.PNG)

5. Vyplníme Project title libovolným názvem. Já jsem si vybral název `hello`. Vybereme složku, kam se má projekt uložit. Já jsem si vybral cestu "C:\Users\tomas\codeblocks\". Doporučuji si vybrat složku někde ve složce vašeho Windows uživatele (v mém případě C:\Users\tomas\\). Vyhnete se tím problémům s právami ve Windows. Klikneme Next.
![hello](./obrazky/ahoj_svete/hello.PNG)
 
6. Necháme vše zaškrtnuto a klikneme Finish.
![configuration](./obrazky/ahoj_svete/configuration.PNG)

7. Měli bychom vidět náš první program. Pokud ne, tak si ve stromové struktuře nalevo rozklikneme hello -> Sources -> main.c (dvojklik na main.c)
![first program](./obrazky/ahoj_svete/first_program.PNG)

8. Nyní nezbývá než kliknout na ozubené kolečko se zelenou šipkou v horní liště. Tím se náš program spustí. Pozor, nechceme klikat ani na samostatné ozubené kolečko, ani na samostatnou zelenou šipku, ale chceme kliknout na tlačítko, které má oba tyto znaky a vypadá takto ![compile and run](./obrazky/ahoj_svete/compile_and_run.PNG)

9. Pokud vše proběhlo v pořádku, tak vidíme na obrazovce
![program running](./obrazky/ahoj_svete/program_running.PNG)

10. Nyní můžeme kliknout na libovolnou klávesu a tím terminálové okno zmizí. Právě jsme si spustili náš první program!

> Pozor, je vždy potřeba terminálové okno vypnout. Někdy se stane, že se programátor jenom překlikne zpátky do CodeBlocks. To způsobuje problém v tom, že pokud bych teď udělal v programu změny a chtěl ho znovu spustit, tak tlačítko pro spuštění programu (ozubené kolečko se zelenou šipkou) bude zašedlé a nepůjde spustit. Vyřešíte to tak, že se překliknete ve Windows zpátky do terminálového okna (ve spodní liště Windows) a ukončíte svůj program (kliknete libovolnou klávesu nebo na křížek v pravém horním rohu). Ve spodní liště to vypadá nějak takto
![troubleshoot](./obrazky/ahoj_svete/troubleshoot.PNG). Další řešení je kliknout na červené tlačítko s křížkem (Abort), které je nyní aktivní ![abort](./obrazky/ahoj_svete/abort.PNG)



## Anatomie programu Ahoj světe
S trochou štěstí nám vše funguje a nyní jsme oficiálně programátoři začátečníci! Teď je potřeba si rozebrat jednotlivé části programu, co která znamená.

### Tisk textu
Následující řádek zdrojového kódu
```c
printf("Hello world!\n");
```

slouží pro vypsání textu na obrazovku. K vypsání textu se používá funkce `printf`. Co je to funkce? Funkce je předem připravený kus kódu, který provede nějaký úkol. Pokud chceme použít nějakou funkci, tak říkáme, že **voláme funkci**. V naší ukázce bychom řekli, že **voláme funkci printf**. Volání funkce obsahuje vždy několik částí. Název funkce, závorky, parametr a středník.

![funkce](./obrazky/ahoj_svete/function.png)

Závorky a středník jsou povinné. Název funkce zde funguje jako unikátní identifikátor. Podle názvu vždy poznáme o jakou funkci se jedná a jaké má chování. Dokonce si můžeme i vytvářet své vlastní funkce (viz kapitola [Definujeme vlastní funkce](./zaklady-funkce.md)).

Velmi důležitý je parametr funkce. Ten se může lišit pro různé funkce (některé funkce ani nemají žádný parametr). Naše funkce `printf` přijímá parametr typu `string` (v češtině *řetězec*). Ten vždy začíná a končí dvojitými uvozovkami `"`.

Pokud bychom chtěli v našem programu  vytisknout něco jiného (například `Ahoj svete!`), tak bychom upravili volání funkce na

```c
printf("Ahoj svete!\n");
```

Celý program by vypadal následovně
```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Ahoj svete!\n");
    return 0;
}
```

Po spuštění programu (ozubené kolečko se zelenou šipkou) se nám zobrazí nový text.

> Pozor na práci s diakritikou. Ta je trošku komplexnější a zatím ji nebudeme používat.


Velmi podezřele může působit `\n`. Co to znamená a proč se v programu nachází? Jedná se o něco, čemu se říká `Escape sekvence`. Pro náše účely je nutné si zapamatovat, že pokud vytisknu `\n`, tak se mi nevytiskne `\n`, ale vytiskne se nový řádek (tzv. jako kdybych zmáčknul na klávesnici klávesu Enter).

Tuto escape sekvenci můžeme dát kdekoliv do textu. Pokud bychom upravili parametr funkce `printf` na
```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello\nworld!\n");
    return 0;
}
```
tak se nám vytiskne
```
Hello
world!
```

Do svého programu můžeme dát kolik chceme escape sekvencí. Můžeme jich dát i více za sebou. Např.

```c
printf("Hello\n\n\nworld!\n");
```
vytiskne
```
Hello


world!
```
Proč se to takto vytiskne? Mezi `Hello` a `world` jsem dat třikrát escape sekvencí pro nový řádek. Tzv. se vytiskne výstup jako kdybychom po Hello zmáčknuli třikrát Enter klávesu.


Co kdybychom ale chtěli vytisknout opravdu znaky `\n`? K tomu slouží jiná escape sekvence `\\\\`. Pokud dáme do kódu dvě zpětná lomítka za sebou a pak n, tak se dvě lomítka nahradí za vytisknutí jednoho lomítka.

Např. ukázka:
```c
printf("Hello \\n world!\n");
```
vytiskne
```
Hello \n world!
```


### include knihoven
Nyní si probereme následující řádky programu
```c
#include <stdio.h>
#include <stdlib.h>
```

Tento kus kódu nám umožňuje používat kusy kódu (funkce), které už za nás napsali jiní programátoři. Tím si můžeme ušetřit spoustu práce, protože použijeme už něco hotového místo toho, abychom si to museli programovat sami.

Bylo by velmi obtížné, kdyby si každý musel vše naprogramovat úplně od začátku. Například chceme v našem programu spočítat odmocninu nebo sinus, ale kdybychom si to měli programovat kompletně sami, tak bychom asi ani nevěděli, jak to udělat. Naštěstí si funkce na výpočet odmocniny a sinus psát sami nemusíme, protože někdo před námi už tyto funkce naprogramoval za nás a my je můžeme použít. Stačí si přidat do našeho programu odpovídající knihovnu, která obsahuje danou funkci. Knihovna není nic jiného, než balíček několika funkcí zabalených do jednoho celku.

Stejně tak i funkce `printf` je jedna z funkcí, kterou někdo naprogramoval před námi. Abychom funkci `printf` mohli použít, tak do našeho programu musíme přidat knihovnu `stdio` (v knihovně `stdio` se nachází funkce `printf`). Knihovnu `stdio` přidáme do našeho programu tak, že na začátek programu vložíme řádek 
```c
#include <stdio.h>
```

Obecně můžeme říct, že přidání knihovny do programu se skládá z několika částí

![include](./obrazky/ahoj_svete/include.png)

Co by se stalo, kdybychom z našeho programu oba řádky s `#include` smazali? Můžeme si to vyzkoušet. Náš program pak bude vypadat takto

```c
int main()
{
    printf("Hello world!\n");
    return 0;
}
```

Po stisknutí ozubeného kolečka se zelenou šipkou vidíme, že se program nespustil a editoru nám červeně označil 3. řádek. Tím nám editor dává najevo, že se na tomto řádku nachází chyba.

![error](./obrazky/ahoj_svete/error.PNG)

Zde je důležité si všimnout i spodní části editoru CodeBlocks. Zde je záložka `Build messages` kde vidíme informace, proč došlo k chybě.

![build messages](./obrazky/ahoj_svete/build_messages.PNG)

Umět se naučit číst chybové hlášky je naprosto zásadní v cestě stát se dobrým programátorem. Zde vidíme
`implicit declaration of function 'printf' [-Wimplicit-function-declaration]`. To znamená, že funkce `printf` není definovaná. To ve většině případů znamená, že nemáme přidanou správnou knihovnu pomocí `#include` nebo jsme nedefinovali nějakou vlastní funkci (o tom více v kapitole [Definujeme vlastní funkce](./zaklady-funkce.md)).

Dále se dozvídáme i řešení `include '<stdio.h>' or provide a declaration of 'printf'`. Přidáme tedy daný include

```c
#include <stdio.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
```

Pokud nyní program znovu spustíme, tak by vše mělo fungovat. Zde se můžete ptát, kam zmizel include knihovny `stdlib.h`. Ten pro náš program neni potřeba. CodeBlocks ho nám do programu automaticky přidal, protože knihovna `stdlib` obsahuje spoustu běžně potřebných funkcí a CodeBlocks neví, jaké všechny knihovny budeme v našem programu potřebovat. Proto tam přidal dvě nejpoužívanější (`stdio` a `stdlib`).

Jde nějak zjistit, jaké funkce jsou obsaženy v těchto knihovnách? Pro `stdio` knihovnu můžeme najít dokumentaci [zde](https://www.tutorialspoint.com/c_standard_library/stdio_h.htm). Knihovna stdlib má dokumentaci např. [zde](https://www.tutorialspoint.com/c_standard_library/stdlib_h.htm).

Pokud chcete být dobrým programátorem, tak je důležité mít přehled o tom, jaké knihovny existují a jaké funkce tyto knihovny obsahují. Tím si lze ulehčit spoustu práce a "neobjevovat kolo". Další vlastnost dobrého programátora je umět efektivně číst dokumentace knihoven. Ze začátku může dokumentace působit hrozivě a nebude vám spoustu věcí jasná, ale postupem času se budete v čtení dokumentace čím dál více zlepšovat a budete chápat, co se vám dokumentace snaží říct.

Počet volání funkcí v programu není nijak omezen. Můžeme tedy dát i několik volání pod sebe, např.
```c
#include <stdio.h>

int main()
{
    printf("Hello world!\n");
    printf("Ahoj svete!\n");
    printf("Ucime se C 2022.\n");
    return 0;
}
```

Pokud takový program spustíme, tak se zobrazí

```
Hello world!
Ahoj svete!
Ucime se C 2022.
```

### main funkce
Následující řádek
```c
int main()
```

je další funkce, se kterou se v našem malém programu setkáváme. Má název `main`. S funkcí `printf` jsme se setkali s konceptem tzv. **volání funkce**. Další koncept týkající se funkcí je tzv. **definování vlastních funkcí**. V tomto případě nepoužíváme funkce definované v nějaké knihovně (jako např. `stdio`), ale vytvoříme si vlastní funkci. Říkáme tedy, že jsme si definovali vlastní funkci `main`.

Funkce `main` má v jazyce C speciální význam. Je to počáteční bod, kde začíná každý náš program. Takovou funkci najdete v každém programu jazyka C.

Schéma definování vlastní funkce

![main function](./obrazky/ahoj_svete/main_function.png)

V této kapitole si nebudeme rozebírat, co jednotlivé části znamenají. Zatím berme jako fakt, že definujeme `int main` a budeme se pohybovat jenom v těle funkce.


### Návratová hodnota
Tento řádek zdrojového kódu (programu)
```c
return 0;
```

je poslední řádek těla funkce. Pro náš případ si to zjednodušíme tak, že tento příkaz ukončuje náš program (ukončuje funkci, v které se právě program nachází). Mějme příklad

```c
printf("1\n");
printf("2\n");
return 0;
printf("3\n");
```

Pokud toto tělo funkce doplnímne do funkce main, pak dostáváme
```c
#include <stdio.h>

int main()
{
    printf("1\n");
    printf("2\n");
    return 0;
    printf("3\n");
}
```

Po spuštění se vytiskne
```
1
2
```
Pokud bychom dali `return 0;` na konec, tzv.
```c
#include <stdio.h>

int main()
{
    printf("1\n");
    printf("2\n");
    printf("3\n");
    return 0;
}
```
tak dostáváme
```
1
2
3
```

Jak jsme si řekli, `return 0;` ukončuje náš program (zatím pouze zjednodušení). Proto se v prvním případě nevytiskne trojka.

> Zde je důležité si všimnout, že program se vykonává sekvenčně řádek po řádku od začátku funkce main až po return. V posledním ukázce se nejdříve vytiskne 1, pak 2, pak 3 a nakonec se program ukončí pomocí `return 0`. Nikdy se nemůže stát, že by se nejdříve vytiskla 3 a pak 2 a pak 1. Vykonávání programu je vždy stejné. Vždy zhora dolů.

### Složené závorky
```c
{
  ...
}
```
Povinné složené závorky. Označují začátek a konec funkce.


## Jak znovu otevřít projekt
Pokud CodeBlocks zavřeme a znovu ho otevřeme, tak již nevidíte náš program/projekt. Znovu ho se k programu dostaneme tak, že klikneme na `Open an existing project` uprostřed obrazovky

![reopen](./obrazky/ahoj_svete/open_existing.PNG)

Tam vybereme složku, kde jsme ukládali náš projekt a vybereme soubor s koncovkou `cbp` (code blocks project)


![cbp](./obrazky/ahoj_svete/cbp.PNG)

Klikneme na `Open`. Tím se nám projekt opět otevře.


## Úkoly na procvičení
### Úkol 1
Napište program, který vytiskne `Muj prvni program`.

<details>
  <summary>Klikni pro zobrazení možného řešení</summary>

```c
#include <stdio.h>

int main()
{
    printf("Muj prvni program\n");
    return 0;
}
```
</details>

### Úkol 2
Napište program, který vytiskne
```
A
B
C
D
```
Pomocí jednoho `printf`.

<details>
  <summary>Klikni pro zobrazení možného řešení</summary>

```c
#include <stdio.h>

int main()
{
    printf("A\nB\nC\nD\n");
    return 0;
}
```
</details>

### Úkol 3
Napište program, který vytiskne
```
A
B
C
D
```
Pomocí `šesti` `printf`.

<details>
  <summary>Klikni pro zobrazení možného řešení</summary>

```c
#include <stdio.h>

int main()
{
    printf("A\n");
    printf("B");
    printf("\n");
    printf("C\n");
    printf("D\n");
    printf("");
    return 0;
}
```
</details>

## Fun fact
*Hello world* je klasický program pro demonstrování syntaxe programovacího jazyku. Často se používá při výuce programování libovolného programovacího jazyku. Poprvé se veřejně objevil v roce 1978 v knize v nazvané `The C Programming Language` od Briana Kernighana a Dennise Ritchieho. Dennis Ritchie je mimo jiné také autorem samotného jazyka C.

Ještě dříve se však objevil v interním memorandu firmy Bell Labs už v roce 1974 (autorem byl Brian Kernighan).


## Odkazy
[Následující kapitola: Proměnné a datové typy](./zaklady-promenne-a-datove-typy.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/3)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Instalace CodeBlocks](./zaklady-instalace.md)
