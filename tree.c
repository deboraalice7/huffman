/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "hashtable.h"
void* TraverseTree(Node *HEAD, short int *tree_size, unsigned char *prefix, int position, Hashtable *ht)
{
    if(HEAD != NULL)
    {
   	if(HEAD->left == NULL && HEAD->right == NULL)
        {     
            prefix[position] = '\0';
            printf("AAA %s\n", prefix);
            *tree_size +=1;  
            ht = (Hashtable *)put(ht, HEAD->item, prefix);    
            return ht;
        }
        
        *tree_size +=1;  
        if(HEAD->left != NULL)
        {
            
            prefix[position] = '0';
            TraverseTree(HEAD->left, tree_size, prefix, position +1, ht);
        }
        if(HEAD->right)
        {
            prefix[position] = '1';
            TraverseTree(HEAD->right, tree_size , prefix, position +1, ht);
        }
        
        printf("bbbb\n");
       // prefix[0] = 0;
    }
    return ht;
}

void print_pre_order(Node *tree)
{
    if(tree->item!= NULL)
    {
	int *item = (int *)malloc(sizeof(int)); 
        int *freq = (int *)malloc(sizeof(int)); ;
	item = tree->item;
	freq = tree->freq;
        printf("%c %d\n", *item, *freq);
	if(tree->left != NULL)
            print_pre_order(tree->left);
	if(tree->right != NULL)
            print_pre_order(tree->right);
    }
}

void* build_tree(Node *list, short int *q_node, int *freq, int *item)
{
    if(*q_node >= 1)
    {
	int *freq_d = 0, *freq_e = 0, f;
	Node *tree = (Node *)malloc(sizeof(Node));
	Node *aux;
		
        //pai
	*item = '*';
        tree->item = item;
	tree->next = NULL;
        
        //filho da esquerda 
        aux =  (Node *)dequeue(list);
        list = list->next;		
	tree->left = aux;
	freq_e = aux->freq;
	*q_node -=1;
        
        //filho da direita
	aux = (Node *)dequeue(list);
	tree->right = aux;
	list = list->next;
	if(tree->right != NULL)
	{
            *q_node -=1;
            freq_d = aux->freq;
	}
        //frequencia do pai
	*freq++;
	*freq = (int)*freq_e + (int)*freq_d;
        tree->freq = freq;
        
	list = (Node *)add_node(list, tree);
	*freq++;
		 
	if(*q_node > 0)
            *q_node +=1;
	
        build_tree(list, q_node, freq, item);
    }
    else
	return list;
}

void set_tree(FILE *out, Node *tree)
{
  if(tree != NULL)
  {
  	int *item = (int *)malloc(sizeof(int));
	item = tree->item;
  	if(*item != '*')
	  fprintf(out,"%c", *item);
  	else if(tree->left == NULL && tree->right == NULL)
  		fprintf(out,"%s", "\\*");
  	else fprintf(out,"%c", '*');

  	set_tree(out, tree->left);
  	set_tree(out, tree->right);
  }
}

void* rebuild_huffman_tree(FILE *in, short int *tree_size,  void *freq)
{
    if(*tree_size > 0)
    {
	unsigned char *c= (unsigned char *)malloc(sizeof(unsigned char));
	short int condition = 1;    
	fscanf(in, "%c",  c);
	
	if(*c != '*')
            condition = 0;		
		
	if(*c == '\\' )
	{
            fscanf(in, "%c", c);
            if(*c != '*')
            {
        	fprintf(in,"%c", *c);
		*c = '\\';
            }
	}
		
	Node *tree = (Node *)set_node(tree, c, freq);
       	*tree_size -=1;
	*c++;	

	if(condition)
	{
            tree->left = (Node *)rebuild_huffman_tree(in,tree_size, freq);
            tree->right = (Node *)rebuild_huffman_tree(in,tree_size, freq);
	}
	return tree;	
    }
}
