#include "../inc/compress.h"
#include "../inc/priority_queue.h"
#include "../inc/huff_tree.h"
#include "../inc/binary.h"
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
    printf("depois da queue\n");
    ht* huff_tree = make_huff_tree(priority_q);
    printf("Huffman tree created \n");
    char **code = make_path(huff_tree);
    printf("Making header \n");
    make_header(freq, code, huff_tree, dest);
    printf("Finish reader\n");
    make_final_file(dest, source, code);
    printf("Final file done\n");
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
        if(freq[i]>0)
        {
            unsigned char* item_of_node = (unsigned char*) malloc(sizeof(unsigned char));
            *item_of_node = i;
            node* new_node = create_node(item_of_node, freq[i]);
            enqueue(queue, new_node);
        }
    }
    return queue;
}

char** make_path(ht* tree)
{
    //char code[256][256]; //mudei, antes era code[256][256]
    char **code = (char**) malloc(sizeof(char*) * 256);
    for (int i = 0; i < 256; ++i)
    {
        code[i] = (char*) malloc(sizeof(char));
    }
    char *path = (char*) malloc(sizeof(char) * 256);
    //char path[256];
    node* curr = get_tree_node(tree);
    printf("Making codification \n");
    make_codification(path, code, curr, 0);
    return code; //todo tem erro aqui
}

void make_codification(char *path, char **code, node* curr, int pos)
{
    if(get_node_left(curr) == NULL && get_node_right(curr) == NULL)
    {
        path[pos] = '\0';
        unsigned char index = *((unsigned char*)get_node_item(curr));
        //strcpy(code[(unsigned char)get_node_item(curr)], path);
        strcpy(code[index], path);
    }
    else
    {
        path[pos] = '0';
        make_codification(path, code, get_node_left(curr), pos+1);
        path[pos] = '1';
        make_codification(path, code, get_node_right(curr), pos+1);
    }
    printf("New codification is complete \n");
}

int trash_size(long long int *freq, char **code)
{
    int i, result;
    long long int sum=0;
    for(i = 0; i < 256; i++)
    {
        sum+= freq[i] * strlen(code[i]);
    }
    result = abs((8-sum) % 8);
    return result;
}

void make_header(long long int *freq, char **code, ht* tree, FILE* dest)
{
    printf("Size of the tree: %d\n", get_tree_size(tree));
    printf("size of trash: %d\n", trash_size(freq, code));
    char* trash = convert_to_binary(trash_size(freq, code), 3);
    char* tree_size = convert_to_binary(get_tree_size(tree), 13);
    strcat(trash, tree_size);
    int pos_write = 7, i = 0;
    unsigned char byte = '\0';
    for (i = 0; i < 16; i++)
    {
        if(trash[i] == '1')
        {
            byte = set_bit(byte, pos_write);
        }
        pos_write--;
        if(pos_write == -1) //reseta para escrever no prox byte
        {
            fwrite(&byte, 1, sizeof(unsigned char), dest);
            pos_write = 7;
            byte = '\0';
        }
    }
    printf("comecei a pre ordem\n");
    print_pre_order(dest, get_tree_node(tree));
    printf("acabei a pre ordem\n");
}


void print_pre_order(FILE* archive, node* curr)
{
    if(get_node_left(curr) == NULL && get_node_right(curr) == NULL)
    {
        if(*(unsigned char*)(get_node_item(curr)) == '*') //folha asterisco
        {
            fprintf(archive, "\\*");
        }
        else if(*(unsigned char*)(get_node_item(curr)) == '\\')
        {
            fprintf(archive, "\\\\");
        }
        else //folha normal
        {
            fprintf(archive, "%c", *((unsigned char*)(get_node_item(curr))));
        }
        //so printa mas se for * printa \*
    }
    else //so asterisco
    {
        fprintf(archive, "*");
        print_pre_order(archive, get_node_left(curr));
        print_pre_order(archive, get_node_right(curr));
        //printa a si memsmo, chama esquerda e depois direita
    }
}

void make_final_file(FILE* dest, FILE* source, char **code)
{
    rewind(source);
    unsigned char item_of_node;
    int pos_write = 7, i = 0;
    unsigned char byte = '\0';
    while( fread(&item_of_node, 1, sizeof(unsigned char), source) == 1) //retorna quanto foi lido
    {
        //printf("%c", item_of_node);
        i=0;
        while (code[item_of_node][i] != '\0')
        {
            if(code[item_of_node][i] == '1')
            {
                byte = set_bit(byte, pos_write);
            }
            pos_write--;
            if(pos_write == -1) //reseta para escrever no prox byte
            {
                fwrite(&byte, 1, sizeof(unsigned char), dest);
                pos_write = 7;
                byte = '\0';
            }
            i++;
        }
    }
    if(pos_write != 7) //byte incompleto
    {
        fwrite(&byte, 1, sizeof(unsigned char), dest);
    }

}

// conta frequencias e salva num array[256] OK
// coloca numa fila de prioridade em ordem crescente OK
// faz a árvore a partir da fila OK
// caminho pra cada folha OK
// fazer cabeçalho
    //3 bits pra tam lixo (valor total % 8) OK
    // somatorio das frequencias * tam do percurso OK
    //13 pra tam da arvore OK
    //arvore em pre ordem OK
// criar novo arquivo, printando os bits todos no arquivo
