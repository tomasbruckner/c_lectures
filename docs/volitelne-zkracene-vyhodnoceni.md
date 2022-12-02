---
title: Zkrácené vyhodnocení
---

```c
#include <stdio.h>

int tiskni_nepravda() {
    printf("Jsem ve funkci\n");

    return 0;
}

int main()
{
    if (tiskni_nepravda() && tiskni_nepravda() && tiskni_nepravda()) {
        // nic
    }

    return 0;
}
```
Tento program nám dává
```
Jsem ve funkci
```

Jak je možné, že se nevytiskne `Jsem ve funkci` třikrát? Podívejme se na další příklad


```c
#include <stdio.h>

int tiskni_nepravda() {
    printf("Jsem ve funkci nepravda\n");

    return 0;
}

int tiskni_pravda() {
    printf("Jsem ve funkci pravda\n");

    return 1;
}

int main()
{
    if (tiskni_pravda() && tiskni_nepravda() && tiskni_nepravda()) {
        // nic
    }

    return 0;
}
```

```
Jsem ve funkci pravda
Jsem ve funkci nepravda
```

Opět se nám nevytisklo druhé `Jsem ve funkci nepravda`.

Je to proto, že se vyhodnocuje následovně:

Nejdříve začneme s 
```c
if (tiskni_pravda() && tiskni_nepravda() && tiskni_nepravda())
```

Pak se vyhodnotí první `tiskni_pravda`. Dostáváme
```c
if (1 && tiskni_nepravda() && tiskni_nepravda())
```

Dává smysl vyhodnocovat podmínku dále? Ano, dává. Pokud máme operátor `&&` a jedna strana je pravdivá, tak ji můžeme vynechat a pokračovat dál. Dostáváme

```c
if (tiskni_nepravda() && tiskni_nepravda())
```

Pokračuje se ve vyhodnocování, takže se vyhodnotí první `tiskni_nepravda` a dostáváme

```c
if (0 && tiskni_nepravda())
```

Pokud je jedna část `&&` operátoru nepravdivá, tak je celý výraz nepravdivý a tedy není důvod výraz dále vyhodnocovat. Výsledek je tedy

```c
if (0)
```

Obecně se tomu říká zkrácené vyhodnocování. Funguje to i s OR operátorem.

```c
#include <stdio.h>

int tiskni_pravda() {
    printf("Jsem ve funkci pravda\n");

    return 1;
}

int main()
{
    if (tiskni_pravda() || tiskni_pravda()) {
        // nic
    }

    return 0;
}
```

Dostáváme

```
Jsem ve funkci pravda
```

Opět došlo ke zkrácenému vyhodnocení. První funkce se vyhodnotí jako pravda a zbytek se zahodí, protože stačí, když je pravdivá jedna strana operátoru `||`. Dostáváme postupně

```c
if (1 || tiskni_pravda())
```

A následně je celý výraz pravdivý, není důvod vyhodnocovat dál

```c
if (1)
```



