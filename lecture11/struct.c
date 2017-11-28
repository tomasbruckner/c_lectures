/**
Projekt:    Kostra 9. cviceni IZP 2015
Autor:      Marek Zak <izakmarek@fit.vutbr.cz>
Datum:      28. 11. 2015
Upravil:    Tomas Bruckner <ibruckner@fit.vutbr.cz>, 27.11.2017
*/

#include "struct.h"

void print_object(const Object *o)
{
    printf("ID: %d, NAME: %s\n", o->id, o->name);
}
