# Priorita operátorů
Stejně jako v matematice platí priorita operátorů. Například

```
4 + 5 * 3 = 19
```

Nejdříve se provede násobení, protože má vyšší prioritu a až následně sčítání, tzv. lze napsat pomocí závorek

```
4 + (5 * 3) = 19
```

V programování to platí také. Proto můžeme napsat

```c
if (5 + 3 > 4)
```

A jelikož má sčítání vyšší prioritu, tak se výraz v podmínce provede jako

```c
if ((5 + 3) > 4)
```


Seznam priorit naleznete například [zde](https://devdocs.io/c/language/operator_precedence).