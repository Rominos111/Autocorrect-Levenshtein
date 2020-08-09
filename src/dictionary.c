// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 01/08/2020.

#include "dictionary.h"

void retrieveStdin(char*** input, int* size) {
    Queue allQ = createQueue();
    Queue wordQ = createQueue();

    char ch;
    while (read(STDIN_FILENO, &ch, 1) > 0) {
        if (ch == ' ' || ch == '\n') {
            enqueue(wordQ, allQ);
            wordQ = createQueue();
        }
        else if (ch != '\r') {
            char* otherCh = malloc(sizeof(void*));
            *otherCh = ch;
            enqueue((void*) otherCh, wordQ);
        }
    }

    *input = malloc(sizeof(char*) * getSize(allQ));

    int n = 0;
    while (!isEmpty(allQ)) {
        wordQ = dequeue(allQ);

        char* wordC = malloc(sizeof(char) * (getSize(wordQ)+1));

        int i = 0;
        while (!isEmpty(wordQ)) {
            char* c = (char*) dequeue(wordQ);
            wordC[i] = *c;
            free(c);
            i++;
        }
        wordC[i] = '\0';
        (*input)[n] = wordC;

        deleteQueue(wordQ);

        n++;
    }

    *size = n;

    for (int i=0; i<*size; i++) {
        printf("%s\n", (*input)[i]);
    }
}
