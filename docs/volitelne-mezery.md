---
title: Mezery v jazyku C
---

Mezery (obecně prázdné znaky jako např. taby) v jazyku C jsou na většině míst volitelné.


Když máme následující program
```c
#include <stdio.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
```

Ten můžeme napsat i jako složené závorky na stejném řádku jako definice funkce
```c
#include <stdio.h>

int main(){
    printf("Hello world!\n");
    return 0;
}
```

Nebo může být i celá funkce na jednom řádku (ale zde pozor, že na konci řádku `#include` musí být nový řádek)
```c
#include <stdio.h>
int main(){printf("Hello world!\n");return 0;}
```

Pokud bychom ale udělali velkou mezeru například v řetězci

```c
#include <stdio.h>

int main()
{
    printf("Hello                       world!\n");
    return 0;
}
```

Tak se chování programu změní, protože se vytiskne něco jiného, než v původním programu.


I tento program je naprosto validní (i když velmi nečitelný)
```c
#include <stdio.h>

int           secti_cisla    (  int       x    ,     int      y)


{
    int             vysledek          =            x    +   y
    ;

             return         vysledek

             ;

}

int main()
{
    int vysledek = secti_cisla(    5    ,    5   )     ; printf    (  "Vysledek je %i\n"   ,   vysledek   )   ;




    return 0;
}

```

Stejně tak je možné posunovat hvězdičku u definice ukazatele. Všechny tři možnosti jsou validní

```c
int * ukazatel1;
int* ukazatel2;
int *ukazatel3;
```

Na volitelnost mezer jsem chtěl upozornit především proto, že někde můžete vidět cizí program, který používá mezery jinde, než jste je používáte vy (třeba složene závorky jsou na stejném/novém řádku, než jste zvyklí, někdo používá mezery mezi závorkou a parametrem atd.). Tak ať se zbytečně nevyděsíte, jak je možné, že to funguje.

Jak to všechno funguje si povíme možná někdy v budoucnosti na ukázce toho, jak si naprogramovat vlastní kompilátor. Konkrétně mezery se řeší ve fázi vytváření lexikálních tokenů.
