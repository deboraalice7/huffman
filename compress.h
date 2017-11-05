/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   compress.h
 * Author: MAceio
 *
 * Created on 4 de Novembro de 2017, 07:17
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

void compress();
unsigned char add_bit(unsigned char c_saida, short int pos);
void write_compress(FILE *in, FILE *out, short int tree_size, Hashtable *ht, Node* tree);

#ifdef __cplusplus
}
#endif

#endif /* COMPRESS_H */

