/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   descompress.h
 * Author: MAceio
 *
 * Created on 4 de Novembro de 2017, 07:21
 */

#ifndef DESCOMPRESS_H
#define DESCOMPRESS_H
#include "node.h"
#include "tree.h"
#include "hashtable.h"

#ifdef __cplusplus
extern "C" {
#endif
    

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

