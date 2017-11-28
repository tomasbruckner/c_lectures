/**
Projekt:    Kostra 9. cviceni IZP 2015
Autor:      Marek Zak <izakmarek@fit.vutbr.cz>
Datum:      28. 11. 2015
Upravil:    Tomas Bruckner <ibruckner@fit.vutbr.cz>, 27.11.2017
*/

#include "array.h"

void print_array(const Array *arr)
{
    for (unsigned int i = 0; i < arr->size; i++)
    {
        printf("#%d\t", i);
        print_object(&arr->items[i]);
    }
    printf("\n");
}
