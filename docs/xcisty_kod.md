# Čistý kód
Čistý kód je označení pro dobře napsaný kód, ve kterém se vyznají i jiní lidi, než vy.

![wtf](./obrazky/cisty_kod/wtf.jpeg)


Jak psát dobrý a kvalitní kód? To není až tak jednoznačná věc. V některých komunitách se píše kód způsobem A a způsob B je kompletně špatně. Pak ale můžete zjistit, že v jiné komunitě to je naprosto naopak. Způsob A je naprosto špatně a musíte ho psát způsobem B. Každý má jiné preference, které většinou vychází z toho s jakým způsobem psaní se setkal v posledních x letech.

Existuje však několik pouček, které jsou univerzálně brány pozitivně. Můžeme se na některé vybrané podívat. Je jich samozřejmě spousta a jak psát dobře kód vychází také hodně ze zkušenosti. Když po nějaké době přijdete ke svému kódu a nerozumíte, co se tam děje, tak je to skvělá vazba pro vás, že jste to měli napsat lépe.


## Naformátovaný kód
Kód by měl být vždy dobře naformátovaný. Ukázka špatného kódu

```c
int   moje_funkce ( int cislo_k_tisku)  

{
        int z=32;
  int    q =   4;

                printf("abc\n"); return 0;


   }
```

Existuje více způsobů odsazení. Můžete používat taby/mezery. Můžete používat různé velikosti odsazení (2/4/8 mezer na jedno odsazení). Tohle není důležité a je jedno, co si vyberete.

Lépe naformátovaný kód je
```c
int moje_funkce(int cislo_k_tisku)  
{
    int z = 32;
    int q = 4;
    printf("abc\n");

    return 0;
}
```

Takový kód se lépe čte a působí profesionálněji.


## Princip DRY - Don't Repeat Yourself
Když máte dvě funkce, které dělají téměř to samé

```c
int funkce_return_1(int cislo_k_tisku)  
{
    int z = 32;
    int q = 4;
    int vysledek = cislo_k_tisk + z + q;
    printf("Tisk %i\n", vysledek);

    return 1;
}

int funkce_return_0(int cislo_k_tisku)  
{
    int z = 32;
    int q = 4;
    int vysledek = cislo_k_tisk + z + q;
    printf("Tisk %i\n", vysledek);

    return 0;
}
```

Tak může společný kód vyextrahovat do pomocné funkce


```c
void tisk(int cislo_k_tisku) {
    int z = 32;
    int q = 4;
    int vysledek = cislo_k_tisk + z + q;
    printf("Tisk %i\n", vysledek);
}

int funkce_return_1(int cislo_k_tisku)  
{
    tisk();

    return 1;
}

int funkce_return_0(int cislo_k_tisku)  
{
    tisk();

    return 0;
}
```
To nám zaručí, že když pak budeme chtít udělat změnu ve společném kódu, tak nám stačí upravit jenom jedno místo a nemůže se nám stát, že na jedno z míst zapomeneme.

> Tady je potřeba dát pozor na to, jestli spolu funkce souvisí. Může se stát, že spolu logicky nesouvisí a když změnu uděláme, tak jsme nechtěli, ať se to projeví na více místech. To už je ale taková pokročilá technika. Zatím bych se více soustředil, ať se mi zbytečně neduplikuje kód.

## Zakomentovaný kód
Další špatná praktika při psaní kódu je komentovat kód a pak ho takhle uložit a sdílet s členy týmu. Pro malé soukromé projekty to může dávat smysl, ale jakmile už s někým začnete spolupracovat, tak už to začíná být problém.


```c
void tisk(int cislo_k_tisku) {
    int z = 32;
    int q = 4;
    int vysledek = cislo_k_tisk + z + q;
    printf("Tisk %i\n", vysledek);
    // moje_funkce(q, z);
    // tiskni_prvocislo(vysledek);
}
```
S trochou štěstí si budete pamatovat, proč jste to zakomentovali. Po roce už pravděpodobně taky ne. A člověk, který k tomu kódu přijde, tak ten už vůbec nebude vědět. Vede to pak k tomu, že takové komentáře nikdy nikdo nesmaže, protože neví, jestli to je potřeba nebo není a proč to tam je.

Správně by takový zakomentovaný kód vůbec neměl vzniknout a pokud nějaký kód nepotřebujete, tak ho rovnou smažte.

Tam pak vzniká otázka co v případě, že se k takovému kódu potřebuji vrátit. Na to obecně slouží verzovací systémy např. Git. O něm více v kapitole XXX.

## Dobře pojmenované proměnné a funkce
Snažíme se popisovat názvy parametrů funkce a i názvy funkce tak, aby případný programátor co nejlépe pochopil, co daná funkce dělá bez toho, aby musel studovat obsah funkce.

Mějme prototyp funkce

```c
void tisk(int cislo);
```

Pokud bychom se podívali jenom na název, tak vůbec nevíme, co se bude tisknout. Taky název proměnné není moc dobrý, protože my už z datového typu víme, že se jedná o číslo.

Když se podíváme na implementaci funkce.

```c
void tisk(int cislo)
{
    printf("Operace trvala %i sekund\n", cislo);
}
```

Až teď vidíme, co se opravdu ve funkci děje. Zkusíme funkci a parametry lépe pojmenovat
```c
void tisk_trvani_operace(int cas_v_sekundach);
```

Nyní bychom měli mít mnohem lepší představu o tom, co funkce dělá.


Podobně to může být i s názvy parametrů
```c
int x = 5;
int y = 7;
int z = 10;
int q = x * y * z;
```
Pokud bychom proměnné lépe pojmenovali
```c
int strana_a = 5;
int strana_b = 7;
int strana_c = 10;
int objem_kvadru = x * y * z;
```

## Preferujte pozitivní podmínky
Negativní podmínky se obecně hůře čtou a lidé v nich dělají častěji chyby. Vždy preferujte pozitivní porovnání nad negativním

```c
if (x != 3) {
    printf("ruzne od tri\n");
} else {
    printf("tri\n");
}
```

Radši preferujte pozitivní

```c
if (x == 3) {
    printf("tri\n");
} else {
    printf("ruzne od tri\n");
}
```

## Magické konstanty
Magické konstanty je označení pro hodnoty, které nemají pojmenování a používají se jako konstanty. Příkládem může být

```c
if (cas > 300) {
    printf("Chyba\n");
}
```
Opravíme to tak, že konstantu pojmenujeme pro lepší čitelnost

```c
#define MAXIMALNI_POCET_SEKUND 300

if (cas > MAXIMALNI_POCET_SEKUND) {
    printf("Chyba\n");
}
```

Obecně není potřeba pojmenovávat konstanty 0, 1 a -1, protože ty jsou často velmi zřejmé.


## Jazyk
Je silně nedoporučováno používat více jazyků ve vašem zdrojovém kódě. Například že část bude napsaná anglicky a čas česky (názvy identifikátorů, komentáře).

Také silně doporučuji používat angličtinu místo češtiny. Angličtina je jazyk programátorů. Ať půjdete pracovat do libovolné firmy, tak vždy bude pracovat v angličtině. Čím dříve se s ní naučíte pracovat tím lépe pro vaši kariéru.


## Příliš dlouhé funkce
Na co si dát pozor je, že byste všechno neměnili mít v jedné funkci. Maximální délka funkce se hodně liší podle toho, koho se zeptáte. Může to být například maximálně 30 řádků. Někdo říká 7 řádků. Obecně pokud má vaše funkce přes 100, tak už určitě víte, že je moc dlouhá.

Pokud máte moc dlouhou funkci, tak to většinou znamená, že se snažíte dělat příliš moc věcí v jedné funkci. Příliš dlouhou funkci byste měli rozbít na několik menších funkcí.

## Fun fact
Čistý kód je pojmenován podle stejnojmenné knížky [Clean Code](https://www.goodreads.com/book/show/3735293-clean-code).

Ta je zaměřená více na programování v Javě, ale určitě patří do každé knihovničky dobrého programátora.

