/*!
 * @brief   Projekt:    Kostra 9. cviceni IZP 2015
 * @author  Autor:      Marek Zak <izakmarek@fit.vutbr.cz>, upravil: Tomas Bruckner <ibruckner@fit.vutbr.cz>
 * @date    Datum:      28. 11. 2015, upraveno 27.11.2017
*/

#include "struct.h"

void print_object(const Object *o)
{
    printf("ID: %d, NAME: %s\n", o->id, o->name);
}
