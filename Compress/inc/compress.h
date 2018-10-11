#ifndef COMPRESS_H
#define COMPRESS_H

#include "priority_queue.h"
#include "huff_tree.h"
#include <stdio.h>
#include <stdlib.h>
/* All the functions necessary to compress is here*/
void start_compression(FILE *source, FILE *dest);

/* Counts the frequency of each character */
long long int* count_frequency(FILE *source);

/* Creates the priority queue with all the itens and their frequencies */
pq* make_queue(long long int *freq);

/* Creates a matrix to save all the new codification */
char** make_path(ht* tree);

/* Creates the new codification of each item */
void make_codification(char *path, char **code, node* curr, int pos);

/* Calculates the trash size */
int trash_size(long long int *freq, char **code);

/* Creates the header with trash size, tree size and pre order of the tree*/
void make_header(long long int *freq, char **code, ht* tree, FILE* dest);

/* Prints the pre order in the final file*/
void print_pre_order(FILE* archive, node* curr);

/* Prints the entire codification in the final file*/
void make_final_file(FILE* dest, FILE* source, char **code);

#endif

