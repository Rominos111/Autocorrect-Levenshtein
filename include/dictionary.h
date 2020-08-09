// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 09/08/2020.

#ifndef AUTOCORRECT_LEVENSHTEIN_DICTIONARY_H
#define AUTOCORRECT_LEVENSHTEIN_DICTIONARY_H

#include <unistd.h>
#include <stdio.h>

#include "queue.h"

/**
 * Récupère le flot d'entrée pour le transformer en liste de string en coupant entre chaque mot
 *
 * @param input Adresse du tableau 2D
 * @param size Nombre de mots
 */
void retrieveStdin(char*** input, int* size);

#endif //AUTOCORRECT_LEVENSHTEIN_DICTIONARY_H
