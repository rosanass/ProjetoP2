#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
typedef struct NODE node;

/* Creates a node*/
node* create_node(void* element, long long int p);

/* Sets the left of the node*/
void set_node_left(node* new_node, node* left);

/* Sets the right of the node*/
void set_node_right(node* new_node, node* right);

/* Sets the next of the node*/
void set_node_next(node* new_node, node* next);

/* Returns the item of the node*/
void* get_node_item(node* new_node);

/* Returns the priority of the node*/
long long int get_node_priority(node* new_node);

/* Returns the next of the node*/
node* get_node_next(node* new_node);

/* Returns the left of the node*/
node* get_node_left(node* new_node);

/* Returns the right of the node*/
node* get_node_right(node* new_node);

#endif