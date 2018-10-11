#ifndef PRIORITY_H
#define PRIORITY_H

#include "../inc/node.h"
#include <stdlib.h>
typedef struct PQ pq;

/* creates the queue */
pq* create_queue();

/* Verifies if the queue is empty*/
int is_empty(pq *pq);

/* Enqueues the node of the queue*/
void enqueue(pq *pq, node* new_node);

/* Dequeues the node of the queue*/
node* dequeue(pq *queue);

/* Returns the queue's size */
int get_pq_size(pq* queue);

/* Returns the queue's head*/
node* get_pq_head(pq* queue);

#endif