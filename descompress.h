/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef DESCOMPRESS_H
#define DESCOMPRESS_H
#include "node.h"
#include "tree.h"
#include "hashtable.h"

#ifdef __cplusplus
extern "C" {
#endif
    
/*
 * Função: verificar se o arquivo tem extensão .huff
 * Recebe: string com node de entrada
 * Retorna: 1 se
 */
int verification(unsigned char *nome_in);
int is_bit_i_set(unsigned char c, int j);

/* 
 *  Função: fazer descompressão
 */
void descompress();
    
    
#ifdef __cplusplus
}
#endif

#endif /* DESCOMPRESS_H */

