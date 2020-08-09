// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 09/08/2020.

#include "utils.h"

void toUpper(char** mixed) {
    char* up = malloc(sizeof(char) * (strlen(*mixed)+1));

    int i = 0;

    while ((*mixed)[i] != '\0') {
        up[i] = (signed char) toupper((unsigned char) ((*mixed)[i]));
        i++;
    }

    up[i] = '\0';

    *mixed = up;

    free(up);
}
