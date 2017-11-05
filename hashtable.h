/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hashtable.h
 * Author: MAceio
 *
 * Created on 4 de Novembro de 2017, 07:26
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H
#define MAX 257
#ifdef __cplusplus
extern "C" {
#endif

typedef struct element{
	void * key;
 	void *value;
}Element;

typedef struct  hashtable{
	Element *table[MAX];
}Hashtable;


unsigned char *Concat(unsigned char *prefix,unsigned char letter);

void* create_hashtable(Hashtable *ht);

void* put(Hashtable * ht,void *key,unsigned char *value);

#ifdef __cplusplus
}
#endif

#endif /* HASHTABLE_H */

