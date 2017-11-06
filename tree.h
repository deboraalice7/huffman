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
  
/*
 * Função imprimir árvore em pré-ordem
 */
void print_pre_order(Node *tree);
  
  /*
   * Função: criar árvore
   * Recebe: node, quantidade de no,  ponteiro de frequência, ponteiro de item
   * Retorna: endereço da cabeça da árvore
   */
void* build_tree(Node *list, short int *q_node, int *freq, int *item);

  
  /*
   * Função: escrever árvore em pré-ordem no arquivo
   * Recebe: arquivo de saída e a cabeça da árvore
   */
void set_tree(FILE *out, Node *tree);

  /*
   * Função: Fazer árvore predefinida em arquivo
   * Recebe: arquivo de entrada, tamanho da árvore e ponteiro de freq
   * Retorna: cabeça da árvore
   */
void* rebuild_huffman_tree(FILE *in, short int *tree_size,  void *freq);

  /*
   * Função: inserir na hashtable os bits de cada caracter
   * Recebe: no, ponteiro do tamanho da árvore, 
   * observação: incrementa tamanho de árvore ao percorrê-la
   * 
   */
void* TraverseTree(Node *HEAD, short int *tree_size, unsigned char *prefix, int position, Hashtable *ht);
  
#ifdef __cplusplus
}
#endif

#endif /* TREE_H */

