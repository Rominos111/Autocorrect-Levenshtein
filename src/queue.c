// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 01/08/2020.

#include <stdio.h>

#include "queue.h"

Queue createQueue() {
    Queue queue = malloc(sizeof(struct _QueueStruct));
    return resetQueue(queue);
}

void deleteQueue(Queue queue) {
    free(queue);
}

Queue resetQueue(Queue queue) {
    queue->size = 0;
    queue->first = NULL;
    queue->last = NULL;

    return queue;
}

Queue enqueue(void* item, Queue queue) {
    struct _QueueElem* node = malloc(sizeof(struct _QueueElem));

    node->value = item;
    node->next = NULL;

    if (isEmpty(queue)) {
        queue->first = node;
    }
    else {
        queue->last->next = node;
    }

    queue->last = node;
    queue->size++;

    return queue;
}

void* dequeue(Queue queue) {
    void* elem = 0;

    if (isEmpty(queue)) {
        fprintf(stderr, "Dequeue on empty queue.");
        raise(SIGILL);
    }
    else {
        elem = queue->first->value;

        queue->first = queue->first->next;

        if (queue->first == NULL) {
            queue->last = NULL;
        }
    }

    queue->size --;

    return elem;
}

bool isEmpty(Queue queue) {
    return queue->size == 0;
}

unsigned int getSize(Queue queue) {
    return queue->size;
}

void printQueueAsInt(Queue queue) {
    struct _QueueElem* elem = queue->first;

    printf("->");

    while (elem != NULL) {
        printf(" %d >", (int) elem->value);
        elem = elem->next;
    }

    printf("-\n");
}

void printQueueAsChar(Queue queue) {
    struct _QueueElem* elem = queue->first;

    while (elem != NULL) {
        // Conversion de void* à char
        char c = *((char*) elem->value);

        if (c == '\r') {
            // Attention, les CR font revenir putchar à la ligne, écrasant ainsi les caractères précédents
            printf("\\r");
        }
        else if (c == '\n') {
            // Traitement facultatif des LF
            printf("\\n");
        }
        else {
            putchar(c);
        }

        elem = elem->next;
    }

    putchar('\n');
}

char* queueToString(Queue queue) {
    char* word = malloc(sizeof(char) * (getSize(queue)+1));

    int i = 0;
    while (!isEmpty(queue)) {
        char* c = (char*) dequeue(queue);
        word[i] = *c;
        free(c);
        i++;
    }
    word[i] = '\0';

    return word;
}
