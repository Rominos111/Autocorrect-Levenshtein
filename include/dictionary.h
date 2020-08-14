// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 09/08/2020.

#ifndef AUTOCORRECT_LEVENSHTEIN_DICTIONARY_H
#define AUTOCORRECT_LEVENSHTEIN_DICTIONARY_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "queue.h"
#include "utils.h"

/**
 * Récupère le flot d'entrée pour le transformer en liste de string en coupant entre chaque mot
 *
 * @param input Adresse du tableau 2D
 * @param nbWords Nombre de mots
 */
void retrieveStdin(char*** input, int* nbWords);

/**
 * Applique le dictionnaire
 *
 * @param input Entrée stdin traitée
 * @param nbWords Nombre de mots
 * @param dictPath Chemin du dictionnaire
 */
void applyDictionary(char** input, int nbWords, char* dictPath);

/**
 * Transforme un caractère Unicode en caractère Ascii
 *
 * @param c Caractère Unicode, string car Unicode est sur plusieurs bytes
 * @return Caractère associé
 */
char convertUnicodeToAscii(char* c);

#endif //AUTOCORRECT_LEVENSHTEIN_DICTIONARY_H
