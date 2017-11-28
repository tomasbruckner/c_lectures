/**
Projekt:    Kostra 9. cviceni IZP 2015
Autor:      Marek Zak <izakmarek@fit.vutbr.cz>
Datum:      28. 11. 2015
Upravil:    Tomas Bruckner <ibruckner@fit.vutbr.cz>, 27.11.2017
*/

#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

#define ARRAY_SIZE          5
#define SMALLER_ARRAY_SIZE  3
#define BIGGER_ARRAY_SIZE   13

#define SEARCH_ARR_ID       99
#define SEARCH_ARR_ID_POS   4

#define SEARCH_ARR_NAME_POS 3
#define SEARCH_ARR_NAME     "IZP 2017"

/**
 * @brief struktura Array
 * 
 * Reprezentuje pole struktur Object.
 */
typedef struct {
  unsigned int size;    /**< pocet prvku v poli */ 
  Object *items;        /**< prvky pole */ 
} Array;

/**
 * Inicializuje strukturu Array a vytvori v poli tolik objektu, kolik
 * je specifikovano parametrem size. Vytvorene objekty maji id nastaveno
 * na 0 a name nastaveno na NULL.
 * 
 * @param size pocet vytvorenych prazdnych objektu pri inicializaci struktury Array
 * @return nove vytvorene pole
 */
Array init_array(const unsigned size);

/**
 * Uvolni pamet alokovanou pro objekty v poli a pamet pro samotne pole.
 * 
 * @param arr struktura Array, ktere se uvolni pamet
 */
void clear_array(Array *arr);

/**
 * Zmena alokovane pameti pro pole struktury Array.
 * V pripade zmenseni pole se uvolni pamet objektum, ktere budou timto odstraneny
 * z pameti. V pripade zvetseni pole se vytvori nove prazdne objekty s id 0
 * a name rovno NULL.
 * 
 * @param arr struktura Array, u ktere se bude menit velikost pole
 * @param size nova velikost pole struktury Array
 * @return struktura Array s upravenou velikosti pole
 */
Array resize_array(Array *arr, const unsigned size);

/**
 * Najde index prvniho objektu v poli se zadanym id.
 * 
 * @param arr struktura Array, ve ktere se bude hledat objekt se zadanym id
 * @param id identifikator hledaneho objektu
 * @return index hledaneho objektu. Vrati -1 pokud se objekt v poli nenachazi.
 */
int find_id(const Array *arr, const int id);

/**
 * Najde index prvniho objektu v poli se zadanym jmenem name.
 * 
 * @param arr struktura Array, ve ktere se bude hledat objekt se zadanym jmenem name
 * @param name jmeno hledaneho objektu
 * @return index hledaneho objektu. Vrati -1 pokud se objekt v poli nenachazi.
 */
int find_name(const Array *arr, const char *name);

/**
 * Najde objekt s nejmensi hodnotou identifikatoru.
 * 
 * @param arr struktura Array, ve ktere se bude objekt hledat
 * @param start_index pozice, od ktere se zacne v poli hledat
 * @return index objektu s nejmensi hodnotou identifikatoru. -1 pokud je pole prazdne.
 */
int find_min(const Array *arr, const unsigned start_index);

/**
 * Vlozi objekt do pole na zadany index.
 * Pokud je na zadanem indexu prazdny objekt, nahradi ho zadanym objektem.
 * V opacnem pripade vlozi objekt na zadany index a posune existujici objekty.
 * 
 * @param arr struktura Array, do ktere se bude zadany objekt vkladat
 * @param item objekt, ktery bude vlozen do pole
 * @param index pozice v poli, kam se ma vlozit zadany objekt
 * @return index, kam byl vlozen objekt. Vraci -1 pokud se operace nezdari.
 */
int insert_item(Array *arr, const Object *item, const unsigned index);

/**
 * Seradi pole objektu podle hodnoty id od nejmensiho po nejvetsi.
 * 
 * @param arr struktura Array, ktera bude serazena
 */
void sort_array(Array *arr);

/**
 * Vytiskne pole objektu struktury Array.
 * 
 * @param arr struktura Array, jejichz pole se bude tisknout
 */
void print_array(const Array *arr);

/**
 * Vytiskne prvnich n prvku pole objektu struktury Array.
 * 
 * @param arr struktura Array, jejichz pole se bude tisknout
 * @param n pocet prvku, ktere se maji vytisknout
 */
void print_n_array(const Array *a, const unsigned n);

#endif // ARRAY_H
