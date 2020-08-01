// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/07/2020.

#ifndef AUTOCORRECT_LEVENSHTEIN_MAIN_H
#define AUTOCORRECT_LEVENSHTEIN_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Transforme une chaine avec une casse mixte en chaine majuscule
 *
 * @param mixed Chaine à transformer
 */
void toUpper(char** mixed);

/**
 * Transforme les paramètres de programme en variables
 *
 * @param argc Nombre d'arguments
 * @param argv Liste des arguments
 * @param dictPath Chemin vers le dictionnaire
 * @param keyboardLayout Disposition clavier (AZERTY, QWERTY, ...)
 */
void getArgs(int argc, const char** argv, char** dictPath, char** keyboardLayout);

/**
 * Main
 *
 * @param argc Nombre d'arguments
 * @param argv Arguments
 *
 * @return Code d'erreur
 */
int main(int argc, char** argv);

#endif //AUTOCORRECT_LEVENSHTEIN_MAIN_H
