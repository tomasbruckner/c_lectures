#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief struktura Object
 */
typedef struct
{
    int id;     /**< identifikator objektu */
    char *name; /**< nazev objektu */
} Object;

/**
 * @brief   Projekt:    Kostra 9. cviceni IZP 2015
 * @author  Autor:      Marek Zak <izakmarek@fit.vutbr.cz>, upravil Tomas Bruckner <ibruckner@fit.vutbr.cz>
 * @date    Datum:      28. 11. 2015, upraveno 27.11.2017
 * @defgroup struct Struct operations
 * @addtogroup struct
 * @{
 */

/**
 * Inicializuje strukturu Object. Nazev objektu se zkopiruje (nestaci ulozit referenci).
 * V pripade nepodarene alokace pameti se nazev objektu nastavi na NULL.
 * 
 * @param id identifikator noveho objektu
 * @param name nazev noveho objektu
 * @return nove vytvoreny objekt
 */
Object init_object(const int id, const char *name);

/**
 * Vymeni data mezi dvema objekty.
 * 
 * @param o1 ukazatel na prvni objekt
 * @param o2 ukazatel na druhy objekt
 * 
 * @pre o1 != NULL, o2 != NULL
 * @post o1 = puvodni o2, o2 = puvodni o1
 */
void swap_objects(Object *o1, Object *o2);

/**
 * Zkopiruje hodnoty z objektu src do objektu dst. Nazev se zkopiruje (nestaci ulozit referenci).
 * 
 * @param dst cilovy (destination) objekt, do ktereho se ulozi hodnoty ze src
 * @param src zdrojovy (source) objekt, ze ktereho se hodnoty ulozi do objektu dst
 * @return pokud se alokace pameti povede, vraci objekt dst, jinak NULL
 */
Object *copy_object(Object *dst, const Object *src);

/**
 * Uvolni pamet, ktera byla alokovana pro nazev objektu, a nastavi nazev na NULL.
 * Id nastavi na 0.
 * 
 * @param o objekt, kteremu bude uvolnena pamet pro nazev
 * @post  o = {id = 0, name = NULL}
 */
void clear_object(Object *o);

/**
 * Vytiske hodnoty daneho objektu.
 * 
 * @param o objekt, jeho hodnoty budou vytisknuty
 */
void print_object(const Object *o);

/// @}

#endif // STRUCT_H
