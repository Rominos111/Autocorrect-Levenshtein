// SPDX-License-Identifier: GPL-3.0-or-later
// Created by Romain on 01/08/2020.

#ifndef AUTOCORRECT_LEVENSHTEIN_QUEUE_H
#define AUTOCORRECT_LEVENSHTEIN_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>

/**
 * ÉLément Queue
 */
struct _QueueElem {
    /**
     * Valeur de l'élément
     */
    void* value;

    /**
     * Élément suivant
     */
    struct _QueueElem* next;
};

/**
 * Struct Queue
 */
struct _QueueStruct {
    /**
     * Premier élément ajouté, premier à sortir
     */
    struct _QueueElem* first;

    /**
     * Dernier élément ajouté
     */
    struct _QueueElem* last;

    /**
     * Taille de la file
     */
    unsigned int size;
};

/**
 * Queue, aka file
 */
typedef struct _QueueStruct* Queue;

/**
 * Crée une Queue
 *
 * @return Queue
 */
Queue createQueue();

/**
 * Supprime une Queue
 *
 * @param queue Queue
 */
void deleteQueue(Queue queue);

/**
 * Ajoute un élément à la Queue
 *
 * @param queue Queue, sera modifiée
 * @param item Item à ajouter
 *
 * @return Queue modifiée
 */
Queue enqueue(Queue queue, void* item);

/**
 * Retire un élément
 *
 * @param queue Queue où retirer un élément
 *
 * @throws SIGILL Si la Queue est vide
 *
 * @return Élément retiré
 */
void* dequeue(Queue queue);

/**
 * Teste si une Queue est vide ou non
 *
 * @param queue Queue
 *
 * @return Queue vide ou non
 */
bool isEmpty(Queue queue);

/**
 * Retourne la taille d'une Queue
 *
 * @param queue Queue
 *
 * @return Taille
 */
unsigned int getSize(Queue queue);

/**
 * Affiche une Queue en considérant ses éléments comme des entiers
 *
 * @param queue Queue
 */
void __attribute_deprecated__ printQueue(Queue queue);

#endif //AUTOCORRECT_LEVENSHTEIN_QUEUE_H
