#include <stdio.h>
#include "../inc/huff_tree.h"
#include "../inc/node.h"

struct HT
{
    int size;
    node* root;
};

ht* create_empty_ht() 
{
    ht* new_ht = (ht*) malloc(sizeof(ht));
    new_ht->size = 0;
    new_ht->root = NULL;
    return new_ht;
}

ht* make_huff_tree(pq* priority_q)
{
    unsigned char node_item;
    if(get_pq_size(priority_q) == 1)
    {

    }
    while(get_pq_size(priority_q) > 1)
    {
        node* node_1 = dequeue(priority_q);
        node* node_2 = dequeue(priority_q);
        node* new_node = merge_node(node_1, node_2);
        enqueue(priority_q, new_node);
    }
    //printf("oi");
    ht* new_tree = create_empty_ht();
    new_tree->root = new_node;
    return new_tree;
}