/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
void frequency(FILE *in, int (*freq)[])
{
    unsigned char c;
    while(fread(&c,sizeof(char),1,in)!=0)
		(*freq)[c]++;
}

void printll(Node *list)
{
	int *a,*b;
	printf("\n\n");
 	while(list!=NULL)
 	{
 		a = list->item;
 		b = list->freq;
   		printf("[%c|%d]=>", (char)*a, (int)*b);
   	    list=list->next;
 	}
 	printf("\n\n");
}

void* set_node(Node *l, void* item, void *freq)
{
    l = (Node *)malloc(sizeof(Node));
    l->item = item;
    l->freq = freq;
    l->left =NULL;
    l->right = NULL;
    l->next = NULL;

    return l;
}

void* add_node(Node *HEAD, Node *new_node)
{
    int *freq, *freq_head;
    freq = new_node->freq;	
    freq_head = new_node->freq;
		
    if(HEAD != NULL)
	freq_head = HEAD->freq;
	
    if(HEAD == NULL || (int)*freq_head >= (int)*freq)
    {
        new_node->next = HEAD;
        HEAD = new_node;
    }
    else
    {
    	Node *aux = HEAD;
    	if(aux->next != NULL)
        {
            if(aux->next->freq != NULL)
                freq_head = aux->next->freq;
        }
    	while(aux->next != NULL && (int)*freq_head < (int)*freq)
    	{
            aux = aux->next;
            if(aux->next != NULL)
            {
                if(aux->next->freq != NULL)
                    freq_head = aux->next->freq;
            }
            else break;
	}
    	new_node->next = aux->next;
    	aux->next = new_node;
    }
    return HEAD;
}

void* dequeue(Node *HEAD)
{
    if(HEAD != NULL)
    {
	Node *aux = HEAD;
	return aux;
    }
    return NULL;
}
