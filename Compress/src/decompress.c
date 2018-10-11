#include "../inc/decompress.h"
#include "../inc/huff_tree.h"
#include "../inc/node.h"
#include "../inc/binary.h"
#include <string.h>
#include <math.h>

void start_decompression(FILE* archive, FILE* new_archive)
{
    int trash_size = get_header_trash_size(archive);
    int tree_size = get_header_tree_size(archive);
    unsigned char* pre_order = get_header_pre_order(archive, tree_size);
    ht* huff_tree = create_empty_ht();
    int pos = 0;
    set_tree_node(huff_tree, remake_huff_tree(pre_order, &pos, tree_size));
    make_decompressed_file(archive, new_archive, huff_tree, trash_size);
}

int get_header_trash_size(FILE* archive)
{
    unsigned char byte;
    fread(&byte, 1, 1, archive);
    int i, trash_size=0;
    byte = byte >> 5;
    for(i = 2; i >= 0; --i)
    {
        if(is_bit_i_set(byte, i))
        {
            trash_size += pow(2, i);
        }
    }
    rewind(archive);
    return trash_size;
}

int get_header_tree_size(FILE* archive)
{
    unsigned char byte;
    fread(&byte, 1, 1, archive);
    int i, tree_size=0;
    byte = byte << 3;
    byte = byte >> 3;
    for (i = 4; i >= 0; --i)
    {
        if (is_bit_i_set(byte, i))
        {
            tree_size += pow(2, i + 8);
        }
    }
    fread(&byte, 1, 1, archive);
    for (i = 7; i >= 0; --i)
    {
        if (is_bit_i_set(byte, i))
        {
            tree_size +=  pow(2, i);
        }
    }
    return tree_size;
}

unsigned char* get_header_pre_order(FILE* archive, int tree_size)
{
    unsigned char *pre_order = (unsigned char*) malloc(sizeof(unsigned char) * tree_size);
    int i;
    for(i=0; i < tree_size; i++)
    {
        fread(&(pre_order[i]), 1, 1, archive);
    }
    return pre_order;
}


node* remake_huff_tree(unsigned char *pre_order, int * pos, int tree_size)
{
    if(*pos >= tree_size)
    {
        return NULL;
    }
    unsigned char * c =  (unsigned char *)malloc(sizeof(unsigned char));
    *c= pre_order[*pos];
    node* new_node;
    if(*c  == '*')
    {
        new_node = create_node(c, 0);
        *pos = *pos+1;
        set_node_left(new_node, remake_huff_tree(pre_order, pos, tree_size));
        set_node_right(new_node, remake_huff_tree(pre_order, pos, tree_size));
        return new_node;
    }
    else
    {
        if (*c == '\\')
        {
            *pos = *pos+1;
            *c = pre_order[*pos];
            new_node = create_node(c, 0);
            *pos = *pos+1;
        }
        else
        {
            new_node = create_node(c, 0);
            *pos = *pos+1;
        }
    }
    return new_node;
}

void make_decompressed_file(FILE* source, FILE* dest, ht* huff_tree, int trash_size)
{
    long long int curr = ftell(source);
    fseek(source,0, SEEK_END);
    long long int end = ftell(source);
    fseek(source, curr,0);
    unsigned char byte;
    node* aux = get_tree_node(huff_tree);
    while(fread(&byte, 1, 1, source) == 1)
    {
        int i, pos_read = 7;

        if (ftell(source) == end)
        {
            for (i = 7; i >= (8 - trash_size); i--)
            {
                if(is_bit_i_set(byte, i) != 0)
                {
                    aux = get_node_right(aux);
                }
                else
                {
                    aux = get_node_left(aux);
                }

                if(get_node_left(aux) == NULL && get_node_right(aux) == NULL)
                {
                    fwrite(get_node_item(aux), 1, sizeof(unsigned char), dest);
                    aux = get_tree_node(huff_tree);
                }

            }
        }
        else
        {
            for (i = 7; i >= 0; i--)
            {
                if(is_bit_i_set(byte, i) !=0)
                {
                    aux = get_node_right(aux);
                }
                else
                {
                    aux = get_node_left(aux);
                }

                if(get_node_left(aux) == NULL && get_node_right(aux) == NULL)
                {
                    fwrite(get_node_item(aux), 1, sizeof(unsigned char), dest);
                    aux = get_tree_node(huff_tree);
                }

            }
        }
    }
}