#include "../inc/priority_queue.h"
#include <stdlib.h>
#include <stdio.h>
struct NODE
{
    void* item;
    long long int priority;
    node* next;
};

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

void enqueue(pq *pq, void *j, long long int p)
{
    node *new_node = (node*) malloc(sizeof(node));
    new_node->item = j;
    new_node->priority = p;
    if ((is_empty(pq))  || (p < pq->head->priority))
    {
        new_node->next = pq->head;
        pq->head = new_node;
        pq->size++;
    }
    else
    {
        node *current = pq->head;
        while ((current->next != NULL) && (current->next->priority < p))
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        pq->size++;
    }
}

node* dequeue(pq *queue)
{
    if (queue->head == NULL) return NULL;
    node* aux = queue->head;
    queue->head = queue->head->next;
    return aux;
}