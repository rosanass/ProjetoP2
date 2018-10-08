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
    int pos=0;
    set_tree_node(huff_tree, remake_huff_tree(pre_order, &pos, tree_size));
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
    byte = byte >> 5;
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


node* remake_huff_tree(unsigned char *pre_order, int* pos, int tree_size)
{
    if(*pos >= tree_size)
    {
        return NULL;
    }
    unsigned char c = pre_order[*pos];
    node* new_node;
    if(c  == '*')
    {
        new_node = create_node('*', 0);
        *pos = *pos+1;
        set_node_left(new_node, remake_huff_tree(pre_order, *pos, tree_size));
        set_node_right(new_node, remake_huff_tree(pre_order, *pos, tree_size));
        return new_node;
    }
    else
    {
        if (c == '\\')
        {
            *pos = *pos+1;
            c = pre_order[*pos];
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