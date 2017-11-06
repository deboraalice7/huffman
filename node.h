/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   node.h
 * Author: MAceio
 *
 * Created on 4 de Novembro de 2017, 07:22
 */

#ifndef NODE_H
#define NODE_H
#define MAX 257

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Estrutura de nó
 */
typedef struct node{
	void *item;
	void  *freq;
	struct node *next;
	struct node *left;
	struct node *right;
}Node;
	
/*
 * Função: colocar frequência de cada caracter em um array
 * Recebe: arquivo de entrada e ponteiro de array 
 */
void frequency(FILE *in, int (*freq)[]);

/*
 * Função: setar nó
 * Recebe: nó, ponteiros de item e de frequência
/* Retorna: endereço de nó
 */
void* set_node(Node *l, void* item, void *freq);

	
/*
 * Função: adicionar no na lista
 * Recebe: nó da cabeça da lista e o novo nó
 * Retorna: endereço do nó da cabeça da lista
 */
void* add_node(Node *HEAD, Node *new_node);
	
/*
 * Função: retornar o endereço do nó da cabeça da lista
 */
void* dequeue(Node *HEAD);
	
#ifdef __cplusplus
}
#endif

#endif /* NODE_H */

