---
title: Priorita operátorů
---

Stejně jako v matematice platí priorita operátorů. Například pokud máme

```
4 + 5 * 3 = 19
```

Tak se nejdříve provede násobení, protože má vyšší prioritu. Následně se provede sčítání. Tzv. se provede

```
4 + (5 * 3) = 19
```

V programování to platí také. Proto můžeme napsat

```c
if (5 + 3 > 4)
```

A jelikož má sčítání vyšší prioritu než porovnání, takže se provede nejdříve sčítání a až následně porovnání. Tzv. se provede

```c
if ((5 + 3) > 4)
```


Seznam priorit naleznete například [zde](https://devdocs.io/c/language/operator_precedence).


## Odkazy
[Následující kapitola: Struktura Switch](./volitelne-switch.md)

[GitHub diskuze k této kapitole](https://github.com/tomasbruckner/c_lectures/discussions/35)

[Zpátky na přehled](./index.md)

[Předchozí kapitola: Operátor podmínky](./volitelne-operator-podminky.md)
