#include "../inc/binary.h"
#include <stdio.h>
#include <stdlib.h>

char *convert_to_binary(long long int number, int bits)
{
    int i;
    int remainder;
    char *converted = (char*) malloc((bits+1) * sizeof(char));
    converted[bits] = '\0';
    for(i = bits-1; i >= 0; i--)
    {
        remainder = number % 2;
        if(remainder == 0)
        {
            converted[i] = '0';
        }
        else
        {
            converted[i] = '1';
        }
        number = number/2;
    }
    return converted;
}

int is_bit_i_set(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask & c;
}

unsigned char set_bit(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask | c;
}
