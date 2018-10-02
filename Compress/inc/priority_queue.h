#ifndef PRIORITY_H
#define PRIORITY_H

#include "../inc/node.h"
#include <stdlib.h>
typedef struct PQ pq;

pq* create_queue();
int is_empty(pq *pq);
void enqueue(pq *pq, node* new_node);
node* dequeue(pq *queue);
int get_pq_size(pq* queue);
node* get_pq_head(pq* queue);

#endif