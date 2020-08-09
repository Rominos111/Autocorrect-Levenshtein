// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 08/08/2020.

#include "levenshtein.h"

uint min(uint a, uint b) {
    return (a < b) ? a : b;
}

uint min3(uint a, uint b, uint c) {
    return min(min(a, b), c);
}

uint levenshteinDistance(const char* word, const char* dictWord) {
    const uint m = strlen(dictWord);
    const uint n = strlen(word);

    uint tab[m+1][n+1];

    for (uint i = 0; i < m+1; i++) {
        for (uint j = 0; j < n+1; j++) {
            if (j == 0) {
                // Colonne set à [0..m]
                tab[i][0] = i;
            }
            else if (i == 0) {
                // Ligne set à [0..n]
                tab[0][j] = j;
            }
            else {
                // Cases set à 0
                tab[i][j] = 0;
            }
        }
    }

    for (uint j = 1; j < n+1; j++) {
        for (uint i = 1; i < m+1; i++) {
            unsigned char cost = (word[i-1] == dictWord[j-1]) ? 0 : 1;

            tab[i][j] = min3(
                    tab[i-1][j] + 1, // Suppression
                    tab[i][j-1] + 1, // Insertion
                    tab[i-1][j-1] + cost // Substitution
                    );
        }
    }

    /*
    for (size_t i = 0; i < m+1; i++) {
        for (size_t j = 0; j < n+1; j++) {
            printf("%ld ", tab[i][j]);
        }
        printf("\n");
    }
     */

    return tab[m][n];
}
