#include "../inc/compress.h"
#include "../inc/priority_queue.h"
#include "../inc/huff_tree.h"
#include <string.h>

void start_compression(FILE *source, FILE *dest)
{
   // int file_size;
    //fseek(source, 0, SEEK_END);
    //file_size = ftell(source);
    int i;
    long long int *freq;
    freq = count_frequency(source);
    pq* priority_q = make_queue(freq);
    ht* huff_tree = make_huff_tree(priority_q);
    char **code = make_path(huff_tree);


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
    //printf("ola");
    return queue;
}


char** make_path(ht* tree)
{
    char code[256][256];
    char path[256];
    node* curr = get_tree_node(tree);
    make_codification(path, code, curr, 0);
    return code;
}

void make_codification(char *path, char **code, node* curr, int pos)
{
    if(get_node_left(curr) == NULL && get_node_right(curr) == NULL)
    {
        path[pos] = '\0';
        strcpy(code[(unsigned char)get_node_item(curr)], path);
    }
    else
    {
        path[pos] = '0';
        make_codification(path, code, get_node_left(curr), pos+1);
        path[pos] = '1';
        make_codification(path, code, get_node_right(curr), pos+1);
    }
}

// conta frequencias e salva num array[256] OK
// coloca numa fila de prioridade em ordem crescente OK
// faz a árvore a partir da fila OK
// caminho pra cada folha
// fazer cabeçalho
// criar novo arquivo
