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
    const void* value;

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
 * Réinitialise une Queue en la modifiant
 *
 * @param queue Queue
 *
 * @return Queue réinitialisée
 */
Queue resetQueue(Queue queue);

/**
 * Ajoute un élément à la Queue
 *
 * @param item Item à ajouter
 * @param queue Queue, sera modifiée
 *
 * @return Queue modifiée
 */
Queue enqueue(void* item, Queue queue);

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
void printQueueAsInt(Queue queue);

/**
 * Affiche une Queue en considérant ses éléments comme des char
 *
 * @param queue Queue
 */
void printQueueAsChar(Queue queue);

/**
 * Transforme une Queue de char en string
 *
 * @param queue Queue de char
 * @return Mot construit par cette Queue, se terminant par un <code>\0</code>
 */
char* queueToString(Queue queue);

#endif //AUTOCORRECT_LEVENSHTEIN_QUEUE_H
