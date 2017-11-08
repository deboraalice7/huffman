#ifndef DESCOMPRESS_H
#define DESCOMPRESS_H
#include "node.h"
#include "tree.h"
typedef unsigned char BYTE;

#ifdef __cplusplus
extern "C" {
#endif
    
/*
 * Função: verification
 * *nome_ in: string com node de entrada
 * 
 * Retorna: 1 se estiver compactado e 0 caso contrário
 */
int verification(unsigned char *nome_in);


int is_bit_i_set(unsigned char c, int j);

/* 
 *  Função: descompress
 * 
 * Retorna: nada
 */

void descompress();
#ifdef __cplusplus
}
#endif

#endif /* DESCOMPRESS_H */

