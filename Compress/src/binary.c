#include "../inc/binary.h"
#include <stdio.h>
#include <stdlib.h>

//lixo max: 7 > 3 bits
// tam arvore: X > 13 bits
// 3 + 5, 8 > unsigned char

char *convert_to_binary(long long int number, int bits)
{
    int i;
    int remainder;
    char *converted = (char*) malloc((bits+1) * sizeof(char));
    //char converted[bits+1];
    converted[bits] = '\0'; //na ultima posição
    for(i = bits-1; i >= 0; i--)
    {
        remainder = number % 2; //resto da divisao
        if(remainder == 0)
        {
            converted[i] = '0';
        }
        else
        {
            converted[i] = '1';
        }
        number = number/2; //quociente
        // 6/2 = 3, 0, pos2
        // 3/2 = 1, 0, pos1
        // 1/2 = 0, 1, pos0
        // 100
    }
    return converted; //todo tava dando erro
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
