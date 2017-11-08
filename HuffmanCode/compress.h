#ifndef COMPRESS_H
#define COMPRESS_H
#include "node.h"

#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

#ifdef __cplusplus
extern "C"{
#endif

/*
 * Função: add_bit
 * 
 * c_saida: receber um caracter
 * pos: recebe a posição
 * 
 * Retorna: caracter
 */
unsigned char add_bit(unsigned char c_saida, short int pos);

/*
 * Função: write_compress
 * 
 * FILE *in: recebe o arquivo de entrada
 * FILE *out: recebe o arquivo de saída
 * tree_size: recebe o tamanho da árvore
 * table[][200]: recebe uma tabela vazia
 * Node* tree = recebe o atual nó da árvore
 * 
 * 
 * Retorna: nada
 */

void write_compress(FILE *in, FILE *out, short int tree_size, unsigned char table[][200], Node* tree);

/*
  * Função: executar compressão
  * 
  * Retorna: nada
 */

void compress();
#ifdef __cplusplus
}
#endif

#endif /* COMPRESS_H */

