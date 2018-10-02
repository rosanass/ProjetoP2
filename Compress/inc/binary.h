#ifndef BINARY_H
#define BINARY_H

#include "huff_tree.h"
#include <stdio.h>
#include <stdlib.h>

char *convert_to_binary(long long int number, int bits);
int is_bit_i_set(unsigned char c, int i);
unsigned char set_bit(unsigned char c, int i);

#endif