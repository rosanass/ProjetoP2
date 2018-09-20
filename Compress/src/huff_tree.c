#include <stdio.h>
#include "../inc/huff_tree.h"

struct BT
{
    int size;
    node* root;
};

bt* create_empty_bt()
{
    bt* new_bt = (bt*) malloc(sizeof(bt));
    new_bt->size = 0;
    new_bt->root = NULL;
    return new_bt;
}

node* merge_node(node* node_1, node* node_2)
{
    node* merged = create_node((void*)'*', get_node_priority(node_1)+get_node_priority(node_2));
    set_node_left(merged, node_1);
    set_node_right(merged, node_2);
    return merged;
}

bt* make_huff_tree(pq* priority_q)
{
    node* node_1 = dequeue(priority_q);
    node* node_2 = dequeue(priority_q);
    node* new_node = merge_node(node_1, node_2);
    enqueue(priority_q, new_node);
    printf("oi");
}