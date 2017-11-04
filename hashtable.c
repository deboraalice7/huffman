/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void print_table(Hashtable *ht)
{
    int i;
    for(i = 0; i < MAX; i++)
        if(ht->table[i] != NULL)	
            printf("%c -> %s\n", i, (char *)ht->table[i]->value);
}

unsigned char *Concat(unsigned char *prefix, unsigned char letter)
{
    unsigned char *result = (unsigned char *)malloc(strlen(prefix));
    sprintf(result, "%s%c", prefix, letter);
    return result;
}

void* put(Hashtable * ht,void *key, void *value)
{
    Element *new_element = (Element*)malloc(sizeof(Element));
    new_element->key = key;
    new_element->value = (unsigned char *)malloc(sizeof(unsigned char));
    strcpy(new_element->value, value);
    
    int *chave = key;
    ht->table[*chave] = new_element;

    return ht;
}

void* create_hashtable(Hashtable *ht)
{
    ht = (Hashtable*)malloc(sizeof(Hashtable));
    int i;
    for(i = 0; i < MAX; i++)
	ht->table[i] = NULL;
    return ht;
}
