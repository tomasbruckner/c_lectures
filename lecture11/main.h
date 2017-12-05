
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include "struct.h"
#include "array.h"


/**
 * @brief   Projekt:    Kostra 9. cviceni IZP 2015
 * @author  Autor:      Marek Zak <izakmarek@fit.vutbr.cz>, upravil Tomas Bruckner <ibruckner@fit.vutbr.cz>
 * @date    Datum:      28. 11. 2015, upraveno 27.11.2017
 * @defgroup test_struct Testy operaci nad strukturou Struct
 * @addtogroup test_struct
 * @{
 */


/**
 * Testuje modul struct.c.
 */
void test_struct();

/**
 * Testuje inicializaci objektu.
 */
void test_init_object();

/**
 * Testuje vymenu objektu.
 */
void test_swap_objects();

/**
 * Testuje kopirovani objektu.
 */
void test_copy_object();

/// @}


/**
 * @brief   Projekt:    Kostra 9. cviceni IZP 2015
 * @author  Autor:      Marek Zak <izakmarek@fit.vutbr.cz>, upravil Tomas Bruckner <ibruckner@fit.vutbr.cz>
 * @date    Datum:      28. 11. 2015, upraveno 27.11.2017
 * @defgroup test_array Testy operaci nad strukturou Array
 * @addtogroup test_array
 * @{
 */


/**
 * Testuje modul array.c.
 */
void test_array();

/**
 * Testuje inicialiazci struktury Array.
 */
void test_init_array();

/**
 * Testuje zmenseni pole.
 */
void test_resize_array_smaller();

/**
 * Testuje zvetseni pole.
 */
void test_resize_array_bigger();

/**
 * Testuje nalezeni objektu se zadanym id.
 */
void test_find_id();

/**
 * Testuje nalezeni objektu se zadanym jmenem.
 */
void test_find_name();

/**
 * Testuje vlozeni objektu do pole.
 */
void test_insert_item();

/**
 * Testuje nalezeni objektu s nejmensim identifikatorem.
 */
void test_find_min();

/**
 * Testuje serazeni pole.
 */
void test_sort_array();

/// @}

#endif // MAIN_H
