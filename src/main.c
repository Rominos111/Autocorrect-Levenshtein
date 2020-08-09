// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/07/2020.

#include "main.h"

void getArgs(int argc, const char** argv, char** dictPath, char** keyboardLayout) {
    *dictPath = NULL;
    *keyboardLayout = NULL;

    // Pour chaque option (-d, -k, ...) on sauvegarde l'élément suivant (-d path, -k layout, ...), d'où argc-1
    for (int i=1; i<argc-1; i++) {
        if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--dict") == 0) {
            *dictPath = (char*) argv[i+1];
        }
        else if (strcmp(argv[i], "-k") == 0 || strcmp(argv[i], "--keyboard") == 0) {
            *keyboardLayout = (char*) argv[i+1];
        }
    }

    if (*dictPath == NULL) {
        fprintf(stderr, "Path to dict missing\n");
        exit(EXIT_NO_DICT_PATH);
    }

    if (*keyboardLayout == NULL) {
        fprintf(stderr, "Keyboard layout missing\n");
        exit(EXIT_NO_KEYBOARD_LAYOUT);
    }
}

int main(int argc, char** argv) {
    char* dictPath = NULL;
    char* keyboardLayout = NULL;

    getArgs(argc, (const char **) argv, &dictPath, &keyboardLayout);
    toUpper(&keyboardLayout);

    char** input = NULL;
    int nbWords;

    retrieveStdin(&input, &nbWords);
    applyDictionary(input, nbWords, dictPath);

    for (int i=0; i<nbWords; i++) {
        free(input[i]);
    }

    free(input);

    return EXIT_SUCCESS;
}
