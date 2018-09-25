#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
typedef struct NODE node;

node* create_node(void* element, long long int p);
void set_node_left(node* new_node, node* left);
void set_node_right(node* new_node, node* right);
void set_node_next(node* new_node, node* next);
long long int get_node_priority(node* new_node);
node* get_node_next(node* new_node);
node* get_node_left(node* new_node);
node* get_node_right(node* new_node);

#endif