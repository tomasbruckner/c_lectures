/*!
 * @brief   Projekt:    Kostra 9. cviceni IZP 2015
 * @author  Autor:      Marek Zak <izakmarek@fit.vutbr.cz>, upravil: Tomas Bruckner <ibruckner@fit.vutbr.cz>
 * @date    Datum:      28. 11. 2015, upraveno 27.11.2017
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
