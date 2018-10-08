#ifndef HUFF_TREE_H
#define HUFF_TREE_H

#include "priority_queue.h"
#include "node.h"
#include <stdlib.h>
typedef struct HT ht;

ht* create_empty_ht();
node* merge_node(node* node_1, node* node_2);
ht* make_huff_tree(pq* priority_q);
node* get_tree_node(ht* huff_tree);
int get_tree_size(ht* huff_tree);
void set_tree_node(ht* huff_tree, node* new);
int how_many_nodes(node* root);
#endif