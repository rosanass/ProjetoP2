#ifndef HUFF_TREE_H
#define HUFF_TREE_H

#include "priority_queue.h"
#include "node.h"
#include <stdlib.h>
typedef struct HT ht;

node* merge_node(node* node_1, node* node_2);
ht* make_huff_tree(pq* priority_q);
#endif