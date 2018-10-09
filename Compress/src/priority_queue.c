#include "../inc/priority_queue.h"
#include "../inc/node.h"
#include <stdlib.h>
#include <stdio.h>

struct PQ
{
    node* head;
    int size;
};

pq* create_queue()
{
    pq *new_queue = (pq*) malloc(sizeof(pq));
    new_queue->head = NULL;
    new_queue->size = 0;
    return new_queue;
}

int is_empty(pq *pq)
{
    if (pq->size == 0) return 1;
    else return 0;
}

void enqueue(pq *pq, node* new_node)
{
    if ((is_empty(pq))  || (get_node_priority(new_node) < get_node_priority(pq->head)))
    {
        set_node_next(new_node, pq->head);
        pq->head = new_node;
        pq->size++;
    }
    else
    {
        node *current = pq->head; //aqui embaixo era: current->next->priority < new_node->priority
        while ((get_node_next(current) != NULL) && (get_node_priority(get_node_next(current)) < get_node_priority(new_node)))
        {
            current = get_node_next(current);
        }
        set_node_next(new_node, get_node_next(current));
        set_node_next(current, new_node);
        pq->size++;
    }
}

node* dequeue(pq *queue)
{
    if (queue->head == NULL) return NULL;
    node* aux = queue->head;
    queue->head = get_node_next(queue->head);
    queue->size = queue->size-1;
    return aux;
}

int get_pq_size(pq* queue)
{
    return queue->size;
}

node* get_pq_head(pq* queue)
{
    return queue->head;
}