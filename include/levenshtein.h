// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 08/08/2020.

#ifndef AUTOCORRECT_LEVENSHTEIN_LEVENSHTEIN_H
#define AUTOCORRECT_LEVENSHTEIN_LEVENSHTEIN_H

#include <string.h>

#include "utils.h"

/**
 * @param a
 * @param b
 * @return Minimum entre a et b
 */
uint min(uint a, uint b);

/**
 * @param a
 * @param b
 * @param c
 * @return Minimum entre a, b et c
 */
uint min3(uint a, uint b, uint c);

/**
 * Distance de Levenshtein entre deux chaines de caractères
 *
 * @param word Chaine 1
 * @param dictWord Chaine 2
 *
 * @return Distance entre ces deux chaines
 *
 * @see https://en.wikipedia.org/wiki/Levenshtein_distance
 */
uint levenshteinDistance(const char* word, const char* dictWord);

#endif //AUTOCORRECT_LEVENSHTEIN_LEVENSHTEIN_H
