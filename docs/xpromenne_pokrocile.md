# Proměnné pro pokročilé
V této kapitole si ukážeme nějaké speciální vlastnosti a klíčová slova spojená s proměnnými.

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

Pokud se pokusíme upravit `const` proměnnou
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

Lze to použít i v definici parametrů funkce.
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

Dostáváme opět chybu.

Pokud ve funkci nemodifikuji ukazatel, tak je bezpečnější nastavit daný parametr jako `const`. Tím dávám jasně najevo všem, kdo funkci budou používat, že se jim ukazatel nebude ve funkci modifikovat.


## Neinicializovaná hodnota
Je potřeba myslet na to, že pokud pracuji s lokální proměnnou a nenastavím ji hodnotu, tak její hodnota je náhodná.
```c
#include <stdio.h>

int main()
{
    int x;  // je nahodna hodnota
    printf("x je %i\n", x);

    return 0;
}
```

Pokud se bavíme o statických nebo globálních proměnných, tak tam víme, že je vždy nastavená hodnota na 0.
```c
#include <stdio.h>

void foo() {
    int q;
    int y;

    printf("q je %i, y je %i\n", y, q);
}

int main()
{
    int x;
    printf("x je %i\n", x);
    foo();

    return 0;
}
```

Je to kvůli tomu, že se různé typy ukládají na různé místo v paměti viz kapitola XXX.
