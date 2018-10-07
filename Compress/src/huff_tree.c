#include <stdio.h>
#include "../inc/huff_tree.h"
#include "../inc/node.h"

struct HT
{
    //todo descobrir pra que size serve
    int size;
    node* root;
};

ht* create_empty_ht() 
{
    ht* new_ht = (ht*) malloc(sizeof(ht));
    new_ht->size = 0;
    new_ht->root = NULL;
    return new_ht;
}

ht* make_huff_tree(pq* priority_q)
{
    //printf("fazendo tree\n");
    while(get_pq_size(priority_q) > 1)
    {
        node* node_1 = dequeue(priority_q);
        node* node_2 = dequeue(priority_q);
        node* new_node = merge_node(node_1, node_2);
        enqueue(priority_q, new_node);
    }

    ht* new_tree = create_empty_ht();
    new_tree->root = dequeue(priority_q);
    new_tree->size = how_many_nodes(get_tree_node(new_tree));
    //printf("finaldafunção\n");
    return new_tree;
}

int how_many_nodes(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(get_node_left(root) == NULL && get_node_right(root) == NULL)
    {
        unsigned char c = *((unsigned char*)get_node_item(root));
        if(c == '\\' ^ c == '*')
        {
            return 2;
        }
        return 1;
    }
    else
    {
        return 1+ how_many_nodes(get_node_left(root)) + how_many_nodes(get_node_right(root));
    }
}

node* get_tree_node(ht* huff_tree)
{
    return huff_tree->root;
}

int get_tree_size(ht* huff_tree)
{
    return huff_tree->size;
}