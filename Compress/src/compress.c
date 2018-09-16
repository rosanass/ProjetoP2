#include "../inc/compress.h"
#include "../inc/priority_queue.h"
#include <string.h>

void start_compression(FILE *source, FILE *dest)
{
    long long int *freq;
    freq = count_frequency(source);

}

long long int* count_frequency(FILE *source)
{
    unsigned char curr;
    long long int freq[256];
    memset(freq, 0, sizeof(long long int)*256);
    while(fread(&curr, 1, 1, source) == 1)
    {
        freq[curr]++;
    }
    return freq;
}

pq* make_queue(long long int *freq)
{
    int i;
    pq* queue = create_queue();
    for (i = 0; i < 256; ++i)
    {

    }
}


// conta frequencias e salva num array[256] OK
// coloca numa fila de prioridade em ordem crescente
// faz a árvore a partir da fila
// tabela de conversão
// fazer cabeçalho
// criar novo arquivo
