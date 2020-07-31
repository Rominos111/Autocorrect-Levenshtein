// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 31/07/2020.

#include "main.h"

void getArgs(int argc, char** argv, char** dictPath, char** keyboardLayout) {
    if (argc == 5) {
        // Pour chaque option (-d, -k, ...) on sauvegarde l'élément suivant (-d path, -k layout, ...), d'où argc-1
        for (int i=1; i<argc-1; i++) {
            if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--dict") == 0) {
                *dictPath = argv[i+1];
            }
            else if (strcmp(argv[i], "-k") == 0 || strcmp(argv[i], "--keyboard") == 0) {
                *keyboardLayout = argv[i+1];
            }
        }
    }
}

int main(int argc, char** argv) {
    char* dictPath = NULL;
    char* keyboardLayout = NULL;

    getArgs(argc, argv, &dictPath, &keyboardLayout);

    if (dictPath != NULL && keyboardLayout != NULL) {

    }
    else {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
