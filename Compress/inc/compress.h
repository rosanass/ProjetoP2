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
int trash_size(long long int *freq, char **code);
void make_header(long long int *freq, char **code, ht* tree, FILE* dest);
void print_pre_order(FILE* archive, node* curr);
void make_final_file(FILE* dest, FILE* source, char **code);

#endif

