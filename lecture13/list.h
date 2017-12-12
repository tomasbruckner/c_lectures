/**
Projekt:    Kostra 10. cviceni IZP 2015
Autor:      Marek Zak <izakmarek@fit.vutbr.cz>, upravil Tomas Bruckner <ibruckner@fit.vutbr.cz>
Datum:      28. 11. 2015, upraveno 11. 12. 2017
*/

#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "struct.h"

#define LIST_ITEM_ID 1
#define LIST_ITEM_NAME "List Item 1"
#define LIST_ITEM_2_ID 2
#define LIST_ITEM_2_NAME "List Item 2"
#define LIST_FIND_NAME_ID 100
#define LIST_FIND_NAME "IZP"

typedef struct item
{
    Object data;
    struct item *next;
} Item;

typedef struct
{
    Item *first;
} List;

/**
 * Inicializace seznamu. Vytvori prazdny seznam.
 * 
 * @return Vraci prazdny seznam.
 */
List init_list();

/**
 * Inicializace prvku seznamu. Z objektu vytvori prvek bez naslednika.
 * 
 * @param data Data, ktera se ulozi do noveho prvku.
 * @return Nove inicializovany prvek.
 */
Item init_item(const Object data);


/**
 * Vlozi prvek na zacatek seznamu.
 * 
 * @param list Seznam, do ktereho se bude prvek vkladat.
 * @param i Prvek, ktery se vlozi na zacatek seznamu.
 */
void list_insert_first(List *list, Item *i);

/**
 * Vrati pocet prvku seznamu.
 * 
 * @param list Seznam, ve kterem se bude zjistovat pocet prvku.
 * @return Pocet prvku v seznamu.
 */
unsigned list_count(const List *list);

/**
 * Vrati true, pokud je seznam prazdny.
 * 
 * @param list Seznam, ktery se bude kontrolovat.
 * @return True, pokud je seznam prazdny, jinak false.
 */
bool list_empty(const List *list);

/**
 * Najde polozku seznamu s nejmensim identifikatorem. 
 * 
 * @param list Seznam, ve kterem se bude hledat.
 * @return Nalezeny prvek. Pokud je seznam prazdny, vraci se NULL.
 */
Item *list_find_minid(const List *list);

/**
 * Najde polozku seznamu s odpovidajicim jmenem objektu.
 * 
 * @param list Seznam, ve kterem se bude jmeno objektu hledat.
 * @param name Jmeno, ktere se bude v seznamu hledat.
 * @return Nalezeny prvek. Pokud neexistuje, vraci se NULL.
 */
Item *list_find_name(const List *list, const char *name);

/**
 * Vytiske polozky seznamu.
 * 
 * @param l Seznam, jehoz polozky budou vytisknuty.
 */
void print_plist(const List *l);

#endif // _LIST_H
