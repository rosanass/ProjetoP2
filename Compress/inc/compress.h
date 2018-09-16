#ifndef COMPRESS_H
#define COMPRESS_H
#include <stdio.h>
#include <stdlib.h>
#include ""

void start_compression(FILE *source, FILE *dest);
long long int* count_frequency(FILE *source);

#endif

