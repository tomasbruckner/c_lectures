---
title: Datový typ union
---

Union je speciální datový typ, který je velmi podobný datovému typu struktura (viz kapitola [Struktury](./zaklady-struktury.md)).

```c
#include <stdio.h>

union test { int cislo; char znak; char * retezec; };

int main() {
    union test muj_union;

    muj_union.cislo = 10;
    printf("Cislo je %i\n", muj_union.cislo);

    muj_union.znak = 'q';
    printf("Znak je %c\n", muj_union.znak);

    muj_union.retezec = "Muj prvni union\n";
    printf("Retezec je %s\n", muj_union.retezec);

    return 0;
}
```

Nám dává
```
Cislo je 10
Znak je q
Retezec je Muj prvni union
```

Rozdíl oproti datovému typu struktura je v tom, že datový typ `union` umožňuje pracovat vždy pouze s tím fieldem, do kterého jsme poslední uložili hodnotu. Je to kvůli tomu, že velikost datového typu `union` je taková, jaká je největší velikost fieldu daného `union`. Tzv. všechny hodnoty jsou uložené na stejném místě v paměti. **Jakmile uložím hodnotu do jednoho fieldu, tak tím efektivně přemažu hodnotu všech ostatních fieldů**. Je nutné tedy vždy pracovat jenom s jednou hodnotou.

Mějme program

```c
#include <stdio.h>

union test { int cislo; char znak; char * retezec; };

int main() {
    union test muj_union;

    muj_union.cislo = 10;
    muj_union.znak = 'q';
    printf("Cislo je %i\n", muj_union.cislo);

    return 0;
}
```

Tak dostáváme
```
Cislo je 113
```

Proč ne 10? Protože uložením hodnoty `q` do `union` jsme přemazali hodnotu 10. Když se podíváme do ASCII tabulky, tak zjistíme, že hodnota `q` má hodnotu 113.


`Union` není datový typ, který byste běžně používali, ale je dobré vědět, že existuje. Možná se někdy setkáte se specializovaným případem, kdy se vám bude hodit.

## Odkazy
[Následující kapitola: Kompilace](./expert-kompilace.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/48)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Operátor čárka](./volitelne-carka.md)
