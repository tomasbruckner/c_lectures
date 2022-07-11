# Práce s argumenty programu


```c
#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("Pocet argumentu: %i\n", argc);

    for(int i = 0; i < argc; i = i +1) {
        printf("%s\n", argv[i]);
    }

    return 0;
}
```




