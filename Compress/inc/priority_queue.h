#ifndef PRIORITY_H
#define PRIORITY_H
typedef struct NODE node;
typedef struct PQ pq;

pq* create_queue();
int is_empty(pq *pq);
node* create_node(void* element, long long int p);
void enqueue(pq *pq, node* new_node);
node* dequeue(pq *queue);
void set_node_left(node* new_node, node* left);
void set_node_right(node* new_node, node* right);
long long int get_node_priority(node* new_node);

#endif