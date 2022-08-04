---
title: Datový typ char
---


Další datový typ, který si tady představíme je char, tzv. jeden znak. Můžeme definovat a uložit hodnotu následovně

```c
int main() {
    char x = 'a';

    return 0;
}
```

Všimněme si, že se zde používají jednoduché uvozovky. Pokud bychom použili dvojité.

```c
int main() {
    char x = "a";

    return 0;
}
```
Tak dostáváme následující chybu
```
initialization of 'char' from 'char *' makes integer from pointer without a cast
```

Snažíme se uložit řetězec (datový typ `char *`) do proměnné, která čeká znak (datový typ `char`).

Také je potřeba si dát pozor na to, abychom do jednoduchých uvozovek nedali dva znaky. Pokud jich tam dáme více, tak už se nejedná o char ale o int.

```c
int main() {
    char x = 'aa';

    return 0;
}
```
Vypíše chybu
```
overflow in conversion from 'int' to 'char' changes value from '24929' to '97'
```

Pokud bychom chtěli hodnotu vytisknout, tak používáme %c

```c
#include <stdio.h>

int main() {
    char x = 'a';
    printf("Znak je %c\n", x);

    return 0;
}
```
Dostáváme
```
Znak je a
```



## ASCII tabulka
Jelikož počítač umí pracovat jenom s číslama (jedničkama a nulama), tak i char není nic jiného, než číslo. V minulosti se lidi domluvili, který znak bude odpovídat jakému číslu. To je definováno v ASCII tabulce (American Standard Code for Information Interchange).

Tu nalezneme například [zde](https://cs.wikipedia.org/wiki/ASCII).

Když se do ní podíváme, tak vidíme, že 'a' má hodnotu v ASCII tabulce 97 v desítkové soustavě. To si můžeme ověřit.

```c
#include <stdio.h>

int main() {
    char x = 'a';
    printf("Znak je %i\n", x);

    return 0;
}
```
Dostáváme
```
Znak je 97
```


```c
#include <stdio.h>

int main() {
    char x = 'a';

    if (x == 'a') {
        printf("Prvni porovnani\n");
    }

    if (x == 97) {
        printf("Druhe porovnani\n");
    }

    return 0;
}
```

Nám vytiskne 
```
Prvni porovnani
Druhe porovnani
```

K charu se můžeme chovat jako v libovolnému číslu. Pokud bychom chtěli zjistit, zda je znak malé písmeno abecedy

```c
#include <stdio.h>

int main() {
    char x = 'd';

    if (x >= 'a' && x <= 'z') {
        printf("Mala abeceda\n");
    }

    return 0;
}
```

Program tiskne 

```
Mala abeceda
```

Písmeno 'd' má hodnotu 100 v ASCII tabulce a písmeno 'a' má 97 a písmeno 'z' má 122. Proto platí

```c
100 >= 97 && 100 <= 122
```

Velikost datového typu char je 1 byte. To si můžeme ověřit
```c
#include <stdio.h>

int main() {
    int velikost = sizeof(char);
    printf("Velikost %i\n", velikost);

    return 0;
}
```

## Znaménkový a neznaménkový char

Podobně jako int, tak char je znaménkový. Existuje `signed char` a `unsigned char`. Samotný `char` může být ve výchozím nastavení buď signed nebo unsigned. Záleží na stroji. Na vašem počítači bude signed, na ARM pravděpodobně unsigned.

Jelikož je 1 byte, tzv. je reprezentován na 8 bitech. Což obsahuje 256 hodnot (2^8 = 256).
Pro signed platí, že nejmenší hodnota je -128 a největší 127.