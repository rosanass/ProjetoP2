#include "../inc/node.h"
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    void* item;
    long long int priority;
    node* next;
    node* left;
    node* right;
};

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

node* merge_node(node* node_1, node* node_2)
{
    unsigned char* item_of_node = (unsigned char*) malloc(sizeof(unsigned char));
    *item_of_node = '*';
    node* merged = create_node(item_of_node, node_1->priority + node_2->priority);
    merged->left = node_1;
    merged->right = node_2;
    return merged;
}

void set_node_left(node* new_node, node* left)
{
    new_node->left = left;
}

void set_node_right(node* new_node, node* right)
{
    new_node->right = right;
}

void set_node_next(node* new_node, node* next)
{
    new_node->next = next;
}

void* get_node_item(node* new_node)
{
    return new_node->item;
}

long long int get_node_priority(node* new_node)
{
    return new_node->priority;
}

node* get_node_next(node* new_node)
{
    return new_node->next;
}

node* get_node_left(node* new_node)
{
    return new_node->left;
}

node* get_node_right(node* new_node)
{
    return new_node->right;
}


