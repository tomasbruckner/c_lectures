/**
Projekt:    Kostra 10. cviceni IZP 2015
Autor:      Marek Zak <izakmarek@fit.vutbr.cz>, upravil Tomas Bruckner <ibruckner@fit.vutbr.cz>
Datum:      28. 11. 2015, upraveno 11. 12. 2017
*/

#include "main.h"

int main()
{
    printf("========== LIST TESTING ==========\n");

    test_init();
    // test_insert();
    // test_count();
    // test_empty();
    // test_findminid();
    // testfindname();

    return 0;
}

void test_init()
{
    printf("\nINIT ITEM\n");

    Object o1 = init_object(LIST_ITEM_ID, LIST_ITEM_NAME);
    Item i1 = init_item(o1);

    Object o2 = init_object(LIST_ITEM_2_ID, LIST_ITEM_2_NAME);
    Item i2 = init_item(o2);

    if (i1.data.id == LIST_ITEM_ID && strcmp(i1.data.name, LIST_ITEM_NAME) == 0 && i1.next == NULL &&
        i2.data.id == LIST_ITEM_2_ID && strcmp(i2.data.name, LIST_ITEM_2_NAME) == 0 && i2.next == NULL)
    {
        printf("OK: List item init OK.\n");
    }
    else
    {
        fprintf(stderr, "ERROR: List item init failed.\n");
    }
}

/*
void test_insert()
{
    printf("\nINSERT LIST ITEM\n");

    List l = init_list();

    Object o1 = init_object(LIST_ITEM_ID, LIST_ITEM_NAME);
    Item i1 = init_item(o1);

    Object o2 = init_object(LIST_ITEM_2_ID, LIST_ITEM_2_NAME);
    Item i2 = init_item(o2);

    list_insert_first(&l, &i1);

    if (l.first == &i1 && l.first->next == NULL)
    {
        list_insert_first(&l, &i2);

        if (l.first == &i2 && l.first->next == &i1 && l.first->next->next == NULL)
        {
            printf("OK: List item init OK.\n");
        }
        else
        {
            fprintf(stderr, "ERROR: List item init failed.\n");
        }
    }
    else
    {
        fprintf(stderr, "ERROR: List item init failed.\n");
    }

    Object o3 = init_object(LIST_ITEM_2_ID + 1, LIST_ITEM_NAME);
    Item i3 = init_item(o3);
    list_insert_first(&l, &i3);

    Object o4 = init_object(LIST_ITEM_2_ID + 2, LIST_ITEM_2_NAME);
    Item i4 = init_item(o4);
    list_insert_first(&l, &i4);

    print_plist(&l);
}

void test_count()
{
    printf("\nLIST ITEMS COUNT\n");

    List l = init_list();

    Object o1 = init_object(LIST_ITEM_ID, LIST_ITEM_NAME);
    Item i1 = init_item(o1);
    list_insert_first(&l, &i1);

    Object o2 = init_object(LIST_ITEM_2_ID, LIST_ITEM_2_NAME);
    Item i2 = init_item(o2);
    list_insert_first(&l, &i2);

    Object o3 = init_object(LIST_ITEM_2_ID + 1, LIST_ITEM_NAME);
    Item i3 = init_item(o3);
    list_insert_first(&l, &i3);

    Object o4 = init_object(LIST_ITEM_2_ID + 2, LIST_ITEM_2_NAME);
    Item i4 = init_item(o4);
    list_insert_first(&l, &i4);

    printf("List item count: %d, should be 4.\n", list_count(&l));
}

void test_empty()
{
    printf("\nEMPTY LIST\n");

    List l = init_list();

    Object o1 = init_object(LIST_ITEM_ID, LIST_ITEM_NAME);
    Item i1 = init_item(o1);
    list_insert_first(&l, &i1);

    List l2 = init_list();

    if (!list_empty(&l) && list_empty(&l2))
    {
        printf("OK: Empty list OK.\n");
    }
    else
    {
        fprintf(stderr, "ERROR: Empty list test failed.\n");
    }
}

void test_findminid()
{
    printf("\nFIND MIN ID\n");

    List l = init_list();

    Object o1 = init_object(LIST_ITEM_ID, LIST_ITEM_NAME);
    Item i1 = init_item(o1);
    list_insert_first(&l, &i1);

    Object o2 = init_object(LIST_ITEM_2_ID, LIST_ITEM_2_NAME);
    Item i2 = init_item(o2);
    list_insert_first(&l, &i2);

    Object o3 = init_object(LIST_ITEM_2_ID + 1, LIST_ITEM_NAME);
    Item i3 = init_item(o3);
    list_insert_first(&l, &i3);

    Object o4 = init_object(LIST_ITEM_2_ID + 2, LIST_ITEM_2_NAME);
    Item i4 = init_item(o4);
    list_insert_first(&l, &i4);

    l.first->next->data.id = -1;
    l.first->next->data.name = "Min";
    Item *imin = list_find_minid(&l);

    if (imin != NULL && imin->data.id == -1)
    {
        printf("OK: Min ID found.\n");
    }
    else
    {
        fprintf(stderr, "ERROR: Min ID not found.\n");
    }
}

void testfindname()
{
    printf("\nFIND MIN ID\n");

    List l = init_list();

    Object o1 = init_object(LIST_ITEM_ID, LIST_ITEM_NAME);
    Item i1 = init_item(o1);
    list_insert_first(&l, &i1);

    Object o2 = init_object(LIST_ITEM_2_ID, LIST_ITEM_2_NAME);
    Item i2 = init_item(o2);
    list_insert_first(&l, &i2);

    Object o3 = init_object(LIST_ITEM_2_ID + 1, LIST_ITEM_NAME);
    Item i3 = init_item(o3);
    list_insert_first(&l, &i3);

    Object o4 = init_object(LIST_ITEM_2_ID + 2, LIST_ITEM_2_NAME);
    Item i4 = init_item(o4);
    list_insert_first(&l, &i4);

    l.first->next->next->data.id = LIST_FIND_NAME_ID;
    l.first->next->next->data.name = LIST_FIND_NAME;

    Item *iname = list_find_name(&l, LIST_FIND_NAME);

    if (iname != NULL && iname->data.id == LIST_FIND_NAME_ID)
    {
        printf("OK: Find item with name %s OK.\n", LIST_FIND_NAME);
    }
    else
    {
        fprintf(stderr, "ERROR: Item with name %s not found.\n", LIST_FIND_NAME);
    }
}

*/
