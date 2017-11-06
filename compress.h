/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef COMPRESS_H
#define COMPRESS_H
#include "node.h"
#include "tree.h"
#include "hashtable.h"

#include <locale.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"{
#endif

/*
 * Função: adicionar bit
 * Recebe: caracter e posição
 * Retorna: caracter
 */
unsigned char add_bit(unsigned char c_saida, short int pos);
  
/*
 * Função: escrever no arquivo de saída a compressão
 * Recebe: arquivos de entrada e saída, tamanho da árvore e árvore 
 */
void write_compress(FILE *in, FILE *out, short int tree_size, Hashtable *ht, Node* tree);

 /*
  * Função: executar compressão
  */
void compress();
  
#ifdef __cplusplus
}
#endif

#endif /* COMPRESS_H */

