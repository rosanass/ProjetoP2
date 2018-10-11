#ifndef BINARY_H
#define BINARY_H

#include "huff_tree.h"
#include <stdio.h>
#include <stdlib.h>
/*Convert a number to binary */
char *convert_to_binary(long long int number, int bits);

/* Verify if the bit is set*/
int is_bit_i_set(unsigned char c, int i);

/* Set the bit */
unsigned char set_bit(unsigned char c, int i);

#endif