#ifndef DECOMPRESS_H
#define DECOMPRESS_H

#include "huff_tree.h"
#include <stdio.h>
#include <stdlib.h>
/* All the functions to decompress is here*/
void start_decompression(FILE* archive, FILE* new_archive);

/* Retrieves trash size*/
int get_header_trash_size(FILE* archive);

/* Retrieves tree size*/
int get_header_tree_size(FILE* archive);

/* Retrieves pre order of the tree*/
unsigned char* get_header_pre_order(FILE* archive, int tree_size);

/* Recreate the huffman tree*/
node* remake_huff_tree(unsigned char *pre_order, int* pos, int tree_size);

/* Creates the final file*/
void make_decompressed_file(FILE* source, FILE* dest, ht* huff_tree, int trash_size);
#endif