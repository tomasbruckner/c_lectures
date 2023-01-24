---
title: Datový typ Enum
---
Enum je speciální datový typ, který lze využít pro lepší přehlednost zdrojového kódu. Definujeme ho jako
```c
enum muj_prvni_enum { JEDNA, DVA, TRI };
```
V programu ho lze použít následovně
```c
#include <stdio.h>

enum rgb_barvy { RED, GREEN, BLUE };

int main() {
    enum rgb_barvy x = GREEN;

    if (x == GREEN) {
        printf("Barva je zelena\n");
    }

    return 0;
}
```

Pokud bychom si vytiskli hodnoty
```c
#include <stdio.h>

enum rgb_barvy { RED, GREEN, BLUE };

int main() {
    printf("RED je %i\n", RED);
    printf("GREEN je %i\n", GREEN);
    printf("BLUE je %i\n", BLUE);

    return 0;
}
```
Tak dostáváme

```
RED je 0
GREEN je 1
BLUE je 2
```

Lze to ale i přemapovat na jiné hodnoty

```c
enum rgb_barvy { RED = 10, GREEN = 25, BLUE = 156 };
```

Případně lze definovat hodnotu jenom u některých hodnot `enumu`

```c
enum rgb_barvy { RED, GREEN = 25, BLUE };
```

Pak při vytisknutí dostáváme
```
RED je 0
GREEN je 25
BLUE je 26
```

Dle pravidla, že první prvek má hodnotu 0 (pokud není definovaná nějaká hodnota viz příklad s `RED = 20`). Všechny další prvky mají hodnotu buď definovanou nebo se použije hodnota o jedničku větší, než měla předchozí hodnota.

Pro `GREEN` jsme definovali hodnotu 25. Proto má `BLUE` hodnotu 26 (o jedna více, než je předchozí hodnota).

Enum můžeme použít i například ve struktuře `Switch`.

```c
#include <stdio.h>

enum rgb_barvy { RED, GREEN, BLUE };

int main() {
    enum rgb_barvy x = GREEN;

    switch (x) {
        case RED:
            printf("RED je %i\n", RED);
            break;
        case GREEN:
            printf("GREEN je %i\n", GREEN);
            break;
        case BLUE:
            printf("BLUE je %i\n", BLUE);
            break;
    }

    return 0;
}
```

Enum můžete použít v případech, kdy máte výčet několika hodnot, které spolu souvisí. Například

```c
enum svetove_strany { SEVER, JIH, VYCHOD, ZAPAD };
```

nebo pokud děláte kalkulačku, tak můžete použít například

```c
enum operace { SCITANI, ODECITANI, NASOBENI, DELENI };
```


## Odkazy
[Následující kapitola: Kompilace](./expert-kompilace.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/48)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Datový typ Union](./volitelne-union.md)
