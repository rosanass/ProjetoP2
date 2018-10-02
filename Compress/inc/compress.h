#ifndef COMPRESS_H
#define COMPRESS_H

#include "priority_queue.h"
#include "huff_tree.h"
#include <stdio.h>
#include <stdlib.h>

void start_compression(FILE *source, FILE *dest);
long long int* count_frequency(FILE *source);
pq* make_queue(long long int *freq);
char** make_path(ht* tree);
void make_codification(char *path, char **code, node* curr, int pos);

#endif

