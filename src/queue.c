// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 01/08/2020.

#include <stdio.h>
#include "queue.h"

Queue createQueue() {
    Queue queue = malloc(sizeof(struct _QueueStruct));

    queue->size = 0;
    queue->first = NULL;
    queue->last = NULL;

    return queue;
}

void deleteQueue(Queue queue) {
    free(queue);
}

Queue enqueue(Queue queue, void* value) {
    struct _QueueElem* node = malloc(sizeof(struct _QueueElem));

    node->value = value;
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

void printQueue(Queue queue) {
    struct _QueueElem* elem = queue->first;

    printf("->");

    while (elem != NULL) {
        printf(" %d >", (int) elem->value);
        elem = elem->next;
    }

    printf("-\n");
}
