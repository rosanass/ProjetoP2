#ifndef DECOMPRESS_H
#define DECOMPRESS_H

#include "huff_tree.h"
#include <stdio.h>
#include <stdlib.h>

void start_decompression(FILE* archive, FILE* new_archive);
int get_header_trash_size(FILE* archive);
int get_header_tree_size(FILE* archive);
unsigned char* get_header_pre_order(FILE* archive, int tree_size);
node* remake_huff_tree(unsigned char *pre_order, int* pos, int tree_size);
#endif