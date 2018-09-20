#ifndef COMPRESS_H
#define COMPRESS_H
#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "huff_tree.h"

void start_compression(FILE *source, FILE *dest);
long long int* count_frequency(FILE *source);
pq* make_queue(long long int *freq);

#endif

