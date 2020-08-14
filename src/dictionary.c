// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 01/08/2020.

#include "dictionary.h"

void retrieveStdin(char*** input, int* nbWords) {
    Queue allQ = createQueue();
    Queue wordQ = createQueue();

    char ch;
    while (read(STDIN_FILENO, &ch, 1) > 0) {
        if (ch == ' ' || ch == '\n') {
            enqueue(wordQ, allQ);
            wordQ = createQueue();
        }
        else if (ch != '\r') {
            char* otherCh = malloc(sizeof(char*));
            *otherCh = ch;
            enqueue((void*) otherCh, wordQ);
        }
    }

    *input = malloc(sizeof(char*) * getSize(allQ));

    int n = 0;
    while (!isEmpty(allQ)) {
        wordQ = dequeue(allQ);
        (*input)[n] = queueToString(wordQ);
        deleteQueue(wordQ);

        n++;
    }

    *nbWords = n;
}

void applyDictionary(char** input, int nbWords, char* dictPath) {
    FILE* file = fopen(dictPath, "r");

    if (file == NULL) {
        fprintf(stderr, "File does not exists: %s\n", dictPath);
        exit(EXIT_FILE_DOES_NOT_EXISTS);
    }

    // setlocale(LC_ALL, "");
    // freopen(NULL, "w", stdout);

    int c;
    int oldC = 0;
    Queue wordQ = createQueue();

    while ((c = fgetc(file)) != EOF) {
        if (c == '\r') {
            continue;
        }
        else if (c == '\n') {
            oldC = 0;

            char* word = queueToString(wordQ);
            deleteQueue(wordQ);
        }
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            oldC = 0;

            char* otherCh = malloc(sizeof(char*));
            *otherCh = (char) c;
            enqueue((void*) otherCh, wordQ);
        }
        else {
            if (oldC == 0) {
                oldC = c;
            }
            else {
                char unicode[] = {(char) oldC, (char) c};
                oldC = 0;
            }
        }

        if (c == '\n') {
            printf("\n");
        }
    }

}

char convertUnicodeToAscii(char* c) {
    if (strcmp(c, "à") == 0) return 'a';
    if (strcmp(c, "â") == 0) return 'a';

    if (strcmp(c, "é") == 0) return 'e';
    if (strcmp(c, "è") == 0) return 'e';
    if (strcmp(c, "ê") == 0) return 'e';
    if (strcmp(c, "ë") == 0) return 'e';
    if (strcmp(c, "œ") == 0) return 'e';

    if (strcmp(c, "î") == 0) return 'i';
    if (strcmp(c, "ï") == 0) return 'i';

    if (strcmp(c, "ô") == 0) return 'o';
    if (strcmp(c, "ö") == 0) return 'o';

    if (strcmp(c, "û") == 0) return 'u';
    if (strcmp(c, "ù") == 0) return 'u';
    if (strcmp(c, "ü") == 0) return 'u';

    if (strcmp(c, "ÿ") == 0) return 'y';

    return 0;
}
