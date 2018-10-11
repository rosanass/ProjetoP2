#ifndef HUFF_TREE_H
#define HUFF_TREE_H

#include "priority_queue.h"
#include "node.h"
#include <stdlib.h>
typedef struct HT ht;

/* Create an empty tree*/
ht* create_empty_ht();

/* Merge the nodes with the lowest frequency and sets the item of node as '*' */
node* merge_node(node* node_1, node* node_2);

/* Creates huffman tree */
ht* make_huff_tree(pq* priority_q);

/* Returns the root */
node* get_tree_node(ht* huff_tree);

/* Returns the size of the tree */
int get_tree_size(ht* huff_tree);

/* Sets the tree node*/
void set_tree_node(ht* huff_tree, node* new);

/* Calculates the tree of the size*/
int how_many_nodes(node* root);
#endif