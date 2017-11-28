/**
Projekt:    Kostra 9. cviceni IZP 2015
Autor:      Marek Zak <izakmarek@fit.vutbr.cz>
Datum:      28. 11. 2015
Upravil:    Tomas Bruckner <ibruckner@fit.vutbr.cz>, 27.11.2017
*/

#include "main.h"


int main() {
    test_struct();
    // test_array();

    return 0;
}

void test_struct() {
    printf("========== STRUCT CHECK ==========\n");

    test_init_object();
    // test_swap_objects();
    // test_copy_object();
}

void test_init_object() {
    printf("INICIALIZACE OBJEKTU\n");

    char object_name[] = "Objekt 1";
    Object o1 = init_object(1, object_name);
    Object o2 = init_object(2, "Objekt 2");
    object_name[7] = '?';

    print_object(&o1);
    print_object(&o2);

    clear_object(&o1);
    clear_object(&o2);
}

void test_swap_objects() {
    printf("\nVYMENA OBJEKTU\n");

    Object o1 = init_object(1, "Objekt 1");
    Object o2 = init_object(2, "Objekt 2");

    swap_objects(&o1, &o2);

    print_object(&o1);
    print_object(&o2);

    clear_object(&o1);
    clear_object(&o2);
}

void test_copy_object() {
    printf("\nZKOPIROVANI OBJEKTU\n");

    Object original = init_object(1, "Objekt 1");
    Object copy;
    print_object(copy_object(&copy, &original));

    clear_object(&copy);
    clear_object(&original);
}

void test_array() {
    printf("\n========== ARRAY CHECK ==========\n");

    test_init_array();
    test_resize_array_smaller();
    test_resize_array_bigger();
    test_find_id();
    test_find_name();
    test_insert_item();
    test_find_min();
    test_sort_array();
}

void test_init_array() {
    printf("INIT ARRAY\n");

    Array arr = init_array(ARRAY_SIZE);
    print_n_array(&arr, ARRAY_SIZE);

	clear_array(&arr);
}

void test_resize_array_smaller() {
    printf("\nSMALLER ARRAY\n");

    Array arr = init_array(ARRAY_SIZE);
    
    resize_array(&arr, SMALLER_ARRAY_SIZE);

    if (arr.size == SMALLER_ARRAY_SIZE) {
        print_n_array(&arr, SMALLER_ARRAY_SIZE);
    } else {
        fprintf(stderr, "ERROR: Array does not contains %d Object(s).\n", SMALLER_ARRAY_SIZE);
    }

    clear_array(&arr);
}

void test_resize_array_bigger() {
    printf("\nBIGGER ARRAY\n");

    Array arr = init_array(ARRAY_SIZE);

    resize_array(&arr, BIGGER_ARRAY_SIZE);

    if (arr.size == BIGGER_ARRAY_SIZE) {
        print_n_array(&arr, BIGGER_ARRAY_SIZE);
    } else {
        fprintf(stderr, "ERROR: Array does not contains %d Object(s).\n", BIGGER_ARRAY_SIZE);
    }

    clear_array(&arr);
}

void test_find_id() {
    printf("\nSEARCH ARRAY ID\n");

    Array arr = init_array(ARRAY_SIZE);

    arr.items[SEARCH_ARR_ID_POS].id = SEARCH_ARR_ID;
    int index = find_id(&arr, SEARCH_ARR_ID);
    printf("ID POSITION: %d, SHOULD BE %d\n", index, SEARCH_ARR_ID_POS);

    clear_array(&arr);
}

void test_find_name() {
    printf("\nSEARCH ARRAY NAME\n");

    Array arr = init_array(ARRAY_SIZE);

    arr.items[SEARCH_ARR_NAME_POS].name = malloc(strlen(SEARCH_ARR_NAME) + 1);
    strcpy(arr.items[SEARCH_ARR_NAME_POS].name, SEARCH_ARR_NAME);

    print_object(&arr.items[SEARCH_ARR_NAME_POS]);

    int index = find_name(&arr, SEARCH_ARR_NAME);
    printf("NAME POSITION: %d, SHOULD BE %d\n", index, SEARCH_ARR_NAME_POS);

    clear_array(&arr);
}

void test_insert_item() {
    printf("\nADD TO ARRAY ON POSITION\n");

    Array arr = init_array(BIGGER_ARRAY_SIZE);

    char name[] = "Object  ";
    for (int i = 1; i < 6; i++) {
        name[7] = 6 - i + '0';
        Object o = init_object(6-i, name);
        insert_item(&arr, &o, 1);
    }

    for(int i = 6; i < 10; i++) {
        name[7] = i + '0';
        Object o = init_object(i, name);
        insert_item(&arr, &o, i);
    }

    print_array(&arr);

	clear_array(&arr);
}

void test_find_min() {
    printf("\nMININUM ITEM POSITION\n");

    Array arr = init_array(BIGGER_ARRAY_SIZE);

    for (unsigned int i = 0; i < arr.size; i++) {
        arr.items[i].id = (i * 5 + 7) % BIGGER_ARRAY_SIZE;
    }

    print_array(&arr);
    printf("MINIMUM: %d\n", find_min(&arr,0));

	clear_array(&arr);
}

void test_sort_array() {
    printf("\nSORT ARRAY ITEMS\n");

    Array arr = init_array(ARRAY_SIZE);

    Object o1 = init_object(4, "Objekt 4");
    insert_item(&arr, &o1, 0);
    Object o2 = init_object(5, "Objekt 5");
    insert_item(&arr, &o2, 1);
    Object o3 = init_object(2, "Objekt 2");
    insert_item(&arr, &o3, 2);

    sort_array(&arr);
    print_array(&arr);

	clear_array(&arr);
}
