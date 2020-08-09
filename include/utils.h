// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 09/08/2020.

#ifndef AUTOCORRECT_LEVENSHTEIN_UTILS_H
#define AUTOCORRECT_LEVENSHTEIN_UTILS_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EXIT_NO_KEYBOARD_LAYOUT 100
#define EXIT_NO_DICT_PATH 101

#define EXIT_FILE_DOES_NOT_EXISTS 201

/**
 * Facilité d'écriture de unsigned int
 */
typedef unsigned int uint;

/**
 * Transforme une chaine avec une casse mixte en chaine majuscule
 *
 * @param mixed Chaine à transformer
 */
void toUpper(char** mixed);


#endif //AUTOCORRECT_LEVENSHTEIN_UTILS_H
