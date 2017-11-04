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
    
typedef struct node{
	void *item;
	void  *freq;
	struct node *next;
	struct node *left;
	struct node *right;
}Node;
void frequency(FILE *in, int (*freq)[]);

void* set_node(Node *l, void* item, void *freq);

void* add_node(Node *HEAD, Node *new_node);
void* dequeue(Node *HEAD);
#ifdef __cplusplus
}
#endif

#endif /* NODE_H */

