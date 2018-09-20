#include "../inc/compress.h"
#include "../inc/priority_queue.h"
#include "../inc/huff_tree.h"
#include <string.h>

void start_compression(FILE *source, FILE *dest)
{
    long long int *freq;
    freq = count_frequency(source);
    pq* priority_q = make_queue(freq);
    bt* huff_tree = make_huff_tree(priority_q);


}

long long int* count_frequency(FILE *source)
{
    unsigned char curr;
    //long long int freq[256]; se fosse variavel local seria apagada ao fim da função
    long long int *freq = (long long int*) malloc(sizeof(long long int) * 256);
    memset(freq, 0, sizeof(long long int)*256);
    // todo ler de x em x
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
        node* new_node = create_node((void*)i, freq[i]);
        enqueue(queue, new_node);
    }
    printf("oi");
    return queue;
}



// conta frequencias e salva num array[256] OK
// coloca numa fila de prioridade em ordem crescente OK
// faz a árvore a partir da fila
// tabela de conversão
// fazer cabeçalho
// criar novo arquivo
