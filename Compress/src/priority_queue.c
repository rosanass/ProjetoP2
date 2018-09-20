#include "../inc/priority_queue.h"
#include <stdlib.h>
#include <stdio.h>
struct NODE
{
    void* item;
    long long int priority;
    node* next;
    node* left;
    node* right;
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

node* create_node(void* element, long long int p)
{
    node *new_node = (node*) malloc(sizeof(node));
    new_node->item = element;
    new_node->priority = p;
    new_node->next = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void enqueue(pq *pq, node* new_node)
{
    if ((is_empty(pq))  || (new_node->priority < pq->head->priority))
    {
        new_node->next = pq->head;
        pq->head = new_node;
        pq->size++;
    }
    else
    {
        node *current = pq->head;
        while ((current->next != NULL) && (current->next->priority < new_node->priority))
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

void set_node_left(node* new_node, node* left)
{
    new_node->left = left;
}

void set_node_right(node* new_node, node* right)
{
    new_node->right = right;
}

long long int get_node_priority(node* new_node)
{
    return new_node->priority;
}