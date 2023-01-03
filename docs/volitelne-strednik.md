---
title: Středník
---

Se středníkem jsme se setkali jak při ukončení příkazu

```c
int x = 10;
```

Tak v definici for cyklu

```c
for (int i = 0; i < 5; i = i + 1) {

}
```

Nyní si ukážeme velmi vzácně použivané použití středníku a to jako prázdný příkaz. Samotný středník slouží jako tzv. `noop` (no operation). Můžeme ho tedy dát libovolně do programu.

V následujícím programu máme středník jako první příkaz ve funkci main

```c
#include <stdio.h>

int main() {
    ;

    return 0;
}
```
Progam by fungoval stejně, i kdyby tam středník nebyl

```c
#include <stdio.h>

int main() {
    return 0;
}
```

Středník můžeme použít jako jediný příkaz IF struktury v kombinaci s variantou bez závorek (viz kapitola [Závorky](./volitelne-zavorky.md))

```c
#include <stdio.h>

int main() {
    int x = 3;

    if (x > 10)
        ;

    return 0;
}
```

Případně varianta

```c
#include <stdio.h>

int main() {
    int x = 3;

    if (x > 10);

    return 0;
}
```

Toto použití zde uvádím jenom pro úplnost kurzu, protože se můžete s podobným použitím středníku setkat v nějakém programu například v knížce nebo na internetu. Tak ať nejste zmatení, jaktože je najednou za IF podmínkou středník.

S největší pravděpodobností však středník jako `no operation` nebude nikdy potřebovat.

## Odkazy
[Následující kapitola: Opererátor přirazení hodnoty](./volitelne-prirazeni.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/45)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Závorky](./volitelne-zavorky.md)
