/**
Projekt:    Kostra 10. cviceni IZP 2015
Autor:      Marek Zak <izakmarek@fit.vutbr.cz>, upravil Tomas Bruckner <ibruckner@fit.vutbr.cz>
Datum:      28. 11. 2015, upraveno 11. 12. 2017
*/

#include "list.h"


List init_list()
{
    /** TODO: */
}

Item init_item(const Object data)
{
    /** TODO: */
}

void list_insert_first(List *list, Item *i)
{
    /** TODO: */
}

unsigned list_count(const List *list)
{
    /** TODO: */
}

bool list_empty(const List *list)
{
    /** TODO: */
}

Item *list_find_minid(const List *list)
{
    /** TODO: */
}

Item *list_find_name(const List *list, const char *name)
{
    /** TODO: */
}

void print_plist(const List *l)
{
    Item *tmp = l->first;
    int i = 0;
    while (tmp != NULL) {
        printf("#%d\t", i++);
        print_object(&tmp->data);
        tmp = tmp->next;
    }
}
