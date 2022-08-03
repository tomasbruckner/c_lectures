# Funkce pro pokročilé
V jedné z prvních kapitol jsme se seznámili s funkcí `printf`, která byla speciální v tom, že měla předem nedefinovaný počet parametrů. Mohli jsme tam poslat jeden nebo tři hodnoty a vše fungovalo. Jak je to možné?

Jazyk C má koncept tzv. variadických funkcí (variadic functions), který právě toto umožňuje. Slouží k tomu knihovna `stdarg`. Ta obsahuje následující

* **va_list** - struktura, která obsahuje obsahuje informace o argumentech

A následující funkce (ve skutečnosti makra)
```c
// inicializuje strukturu va_list
void va_start(va_list ap, parmN);

// slouží ke kopírování argumentů
T va_arg(va_list ap, T);

// slouží ke kopírování argumentů
void va_copy(va_list dest, va_list src);

// ukončí prochází argumentů
void va_end(va_list ap);
```

Mějme ukázku kódu
```c
#include <stdio.h>
#include <stdarg.h>

void muj_tisk(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    char c = format[0];

    for (int i = 1; c != '\0'; i += 1) {
        if (c == 'i') {
            int cislo_k_tisku = va_arg(args, int);
            printf("%i\n", cislo_k_tisku);
        } else if (c == 'c') {
            int znak_k_tisku = va_arg(args, int);
            printf("%c\n", znak_k_tisku);
        } else if (c == 'f') {
            double desetinne_k_tisku = va_arg(args, double);
            printf("%f\n", desetinne_k_tisku);
        }

        c = format[i];
    }

    va_end(args);
}

int main()
{
    muj_tisk("icff", 3, 'a', 1.999, 42.5);
}
```

Funguje to tak, že funkce `va_arg` má svůj vnitřní stav. Pokud ji zavoláme poprvé, tak nám vrátí první argument. Pokud ji zavoláme podruhé, tak nám už vrací druhý argument.



Velký pozor musíme dát na sekci s charem
```c
} else if (c == 'c') {
    int znak_k_tisku = va_arg(args, int);
    printf("%c\n", znak_k_tisku);
```

To není chyba, ale omezení jazyka C, který automatický konvertuje v tomto případě char na int.