/*!
 * @brief   Projekt:    Kostra 9. cviceni IZP 2015
 * @author  Autor:      Marek Zak <izakmarek@fit.vutbr.cz>, upravil: Tomas Bruckner <ibruckner@fit.vutbr.cz>
 * @date    Datum:      28. 11. 2015, upraveno 27.11.2017
*/

#include "struct.h"

Object init_object(const int id, const char *name)
{
    Object o = {.id = id, .name = NULL};

    if (name != NULL)
    {
        o.name = malloc((strlen(name) + 1) * sizeof(char));
        if (o.name != NULL)
        {
            strcpy(o.name, name);
        }
    }

    return o;
}

void swap_objects(Object *o1, Object *o2)
{
    Object tmp = *o1;

    *o1 = *o2;
    *o2 = tmp;
}

Object *copy_object(Object *dst, const Object *src)
{
    *dst = init_object(src->id, src->name);

    return (dst->name != NULL) ? dst : NULL;
}

void clear_object(Object *o)
{
    free(o->name);
    o->name = NULL;
    o->id = 0;
}

void print_object(const Object *o)
{
    printf("ID: %d, NAME: %s\n", o->id, o->name);
}
