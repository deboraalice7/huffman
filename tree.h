/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tree.h
 * Author: MAceio
 *
 * Created on 4 de Novembro de 2017, 07:24
 */

#ifndef TREE_H
#define TREE_H
#include "hashtable.h"

#ifdef __cplusplus
extern "C" {
#endif

void print_pre_order(Node *tree);
void* build_tree(Node *list, short int *q_node, int *freq, int *item);

void set_tree(FILE *out, Node *tree);

void* rebuild_huffman_tree(FILE *in, short int *tree_size,  void *freq);

void* TraverseTree(Node *HEAD, short int *tree_size, unsigned char *prefix, int position, Hashtable *ht);
#ifdef __cplusplus
}
#endif

#endif /* TREE_H */

