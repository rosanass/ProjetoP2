#ifndef HUFF_TREE_H
#define HUFF_TREE_H
#include "priority_queue.h"
#include <stdlib.h>
typedef struct BT bt;

bt* make_huff_tree(pq* priority_q);
#endif