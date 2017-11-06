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

/*
 * Estrutura do elemento da hash
 */
typedef struct element{
	void * key;
 	void *value;
}Element;

/*
 * Estrutura da hastable
 */
typedef struct  hashtable{
	Element *table[MAX];
}Hashtable;

/*
 * Função: criar hashtable
 * Recebe: ponteiro de hahstable
 * Retorna: endereço de hash alocada e vazia
 */
void* create_hashtable(Hashtable *ht);

/*
 * Função: adicionar elemento na hashtable
 * Recebe: hash, ponteiro da chave da hash e string com o valor
 * Retorna: hashtable
 */
void* put(Hashtable * ht,void *key,unsigned char *value);

#ifdef __cplusplus
}
#endif

#endif /* HASHTABLE_H */

