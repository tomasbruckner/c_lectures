---
title: Proměnné pro pokročilé
---


V této kapitole si ukážeme různé speciální vlastnosti a klíčová slova spojená s proměnnými.

## Statické proměnné
První z nich je `static`. Chování je podobné globálním proměnným.

```c
#include <stdio.h>

void pricti_a_vytiskni() {
    static int x = 10;
    printf("Hodnota x je %i\n", x);

    x = x + 1;
}

int main()
{
    pricti_a_vytiskni();
    pricti_a_vytiskni();
    pricti_a_vytiskni();

    return 0;
}
```
Nám dává
```
Hodnota x je 10
Hodnota x je 11
Hodnota x je 12
```
Je to proto, že vytvoření statické proměnné se provede pouze jednou při spuštění programu. Proto si můžeme představit náš kód pomocí globální proměnné takto
```c
#include <stdio.h>

int x = 10;

void pricti_a_vytiskni() {
    printf("Hodnota x je %i\n", x);

    x = x + 1;
}

int main()
{
    pricti_a_vytiskni();
    pricti_a_vytiskni();
    pricti_a_vytiskni();

    return 0;
}
```
Rozdíl oproti globálním proměnným je ten, že se statickou proměnnou můžeme pracovat jenom tam, kde jsme ji definovali. Kdybychom zkusili použít statickou proměnnou `x` ve funkci `main`, tak dostáváme chybu.
```c
#include <stdio.h>

void pricti_a_vytiskni() {
    static int x = 10;
    printf("Hodnota x je %i\n", x);

    x = x + 1;
}

int main()
{
    pricti_a_vytiskni();
    pricti_a_vytiskni();
    pricti_a_vytiskni();
    printf("x je %i\n", x);

    return 0;
}
```

## Konstantní proměnné
V jazyku C můžeme definovat, že je nějaká proměnná konstantní pomocí klíčového slova `const`.

```c
const int konstanta = 10;
```

Pokud se pokusíme upravit proměnnou definovanou jako `const`
```c
#include <stdio.h>

int main()
{
    const int konstanta = 10;
    konstanta = 11;

    printf("Konstanta je %i\n", konstanta);

    return 0;
}
```

Tak dostáváme chybu
```
assignment of read-only variable 'konstanta'
```

Klíčové slovo `const` můžeme použít i v definici parametrů funkce.
```c
#include <stdio.h>

void uprav_ukazatel(const int * ukazatel) {
    *ukazatel = 15;
}

int main()
{
    int x = 5;
    uprav_ukazatel(&x);

    printf("x je %i\n", x);

    return 0;
}
```

Dostáváme opět chybu, jelikož se snažíme ve funkci `uprav_ukazatel` upravit `const` ukazatel.

Je dobré se držet pravidla, že pokud definujete funkci, která přijímá parametrem nějaký ukazatel, a ten se ve funkci nemodifikuje, tak byste tento parametr měli definovat jako `const`. Tím dávám jasně najevo všem, kdo funkci budou používat, že se jim ukazatel nebude ve funkci modifikovat.

Demonstrujme si to na programu
```c
#include <stdio.h>

void tisk(const int * ukazatel) {
    printf("x je %i\n", *ukazatel);
}

int main()
{
    int x = 5;
    tisk(&x);

    return 0;
}
```

Zde vidíme, že funkce `tisk` nemodifikuje ukazatel, který dostane jako parametr do funkce (pouze vytiskne jeho hodnotu). Proto jsme tento parametr definovali jako `const`.

## Neinicializovaná hodnota
Je potřeba myslet na to, že pokud pracujeme s lokální proměnnou a nenastavíme ji žádnou hodnotu, tak její hodnota je náhodná.
```c
#include <stdio.h>

int main()
{
    int x;  // je nahodna hodnota
    printf("x je %i\n", x);

    return 0;
}
```

Proto je důležité vždy hodnotu nastavit.

Pokud se však bavíme o statických nebo globálních proměnných, tak tam víme, že je jejich hodnota vždy nastavená na hodnotu 0.
```c
#include <stdio.h>

int globalni;

void tisk() {
    static int staticka;

    printf("globalni je %i, staticka je %i\n", globalni, staticka);
}

int main()
{
    tisk();

    return 0;
}
```

V tomto případě dostáváme vždy výstup

```
globalni je 0, staticka je 0
```

Je to kvůli tomu, že se různé typy proměnných se ukládají na různé místo v paměti viz kapitola [Paměť](./expert-pamet.md).


## Odkazy
[Následující kapitola: Dekompozice programu](./pokrocile-dekompozice.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/26)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Cykly pro pokročilé](./pokrocile-cykly.md)
