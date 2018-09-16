#ifndef PRIORITY_H
#define PRIORITY_H
typedef struct NODE node;
typedef struct PQ pq;

pq* create_queue();
int is_empty(pq *pq);
void enqueue(pq *pq, void *j, long long int p);
node* dequeue(pq *queue);

#endif