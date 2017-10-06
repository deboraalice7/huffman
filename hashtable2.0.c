#include <stdio.h>
#include <stdlib.h>
#include "encode.h"
#include <string.h>
#define MAX 257
Hashtable* ht;

int main()
{
	HEAD = NULL;
	FILE *in, *out;
	char c;
	int freq[MAX] = {0}, i, q_node = 0, tam_tree = 0, tam = 0;

	in = fopen("arquivo.txt", "rb");
	out = fopen("saida.txt", "wb");

	if(in == NULL)
	{
		printf("Arquivo vazio\n");
		return -1;
	}

	while(fread(&c,sizeof(char),1,in)!=0)
		freq[c]++;

	for(i = 0; i < MAX; i++)
		if(freq[i])
		{
			q_node++;
			add_node(i, freq[i], NULL, NULL);
		 } 
	tam = q_node;
    printll(HEAD);//imprimi a lista ordenada
	build_tree(&q_node);
	print_pre_order(HEAD, &tam_tree);
	//ajeitar : tam_tree atraves de outra funcao 
	 
	printf("TAM_tree %d Letras %d\n", tam_tree, tam);
	BuildTable(freq);	
	print_table();	
	return 0;
}

char *Concat(char *prefix, char letter)
{
    char *result = (char *)malloc(strlen(prefix));
    sprintf(result, "%s%c", prefix, letter);
	return result;
}

void put(char key, char *value)
{
	Element *new_element = (Element*)malloc(sizeof(Element));
	new_element->key = key;
	strcpy(new_element->value, value);
	ht->table[key] = new_element;
	//uma hash de tam 256 é eficiente?
}

void TraverseTree(Node *HEAD, Hashtable *ht, char *prefix)
{
    if(HEAD != NULL)
    {
    	if(HEAD->item != '*') put(HEAD->item, prefix);
        TraverseTree(HEAD->left,ht, Concat(prefix, '0'));
        TraverseTree(HEAD->right, ht, Concat(prefix, '1'));
        free(prefix);
    }
}

void create_hashtable()
{
	ht = (Hashtable*)malloc(sizeof(Hashtable));
	int i;
	for(i = 0; i < MAX; i++)
		ht->table[i] = NULL;
}

void BuildTable(int *frequencies)
{
    create_hashtable();
    char *prefix = (char *)calloc(1, sizeof(char));
    TraverseTree(HEAD, ht, prefix);
}

void print_table()
{
	int i;
	for(i = 0; i < MAX; i++)
	   if(ht->table[i] != NULL)	printf("%c -> %s\n", i, ht->table[i]->value);
}

void printll(Node *HEAD)
{
	Node *p;
	p=HEAD;
	printf("\n\n");
 	while(p!=NULL)
 	{
   		printf("[%c|%d]=>",p->item,p->freq);
   		p=p->next;
 	}
 		printf("\n\n");
}

void add_node(char item, int freq, Node *left, Node *right)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->item = item;
	new_node->freq = freq;
	new_node->left = left;
	new_node->right = right;
	new_node->next = NULL;

	if(HEAD == NULL)
		HEAD = new_node;
	else
	{
		Node *aux = HEAD;
		if(freq > aux->freq)
		{
			while(aux->next != NULL && aux->next->freq < freq)
				aux = aux->next;

			new_node->next = aux->next;					
			aux->next = new_node;
		}
		else
		{
			new_node->next = HEAD;
			HEAD = new_node;
		}
	}
}
void dequeue()
{
	if(HEAD == NULL)
		dequeued = NULL;
	else{
		dequeued = HEAD;	
		HEAD = HEAD->next;
		dequeued->next = NULL;		
	}
}

void print_pre_order(Node *tree, int *tam_tree)
{
	if(tree != NULL)
	{
		printf("%c %d\n", tree->item, tree->freq);
		*tam_tree += 1;
		print_pre_order(tree->left, tam_tree);
		print_pre_order(tree->right, tam_tree);
	}
}

void build_tree(int *q_node)
{
	if(*q_node > 1)
	{
		Node *tree = (Node*)malloc(sizeof(Node));
		tree->item = '*';
		tree->next = NULL;
		tree->freq = 0;
		
		dequeue();
		tree->freq = dequeued->freq;
		tree->left = dequeued;
		*q_node -=1;
		
		dequeue();
		tree->freq += dequeued->freq;
		tree->right = dequeued;
		*q_node -=1;
		
		add_node(tree->item, tree->freq, tree->left, tree->right);
		*q_node +=1;
		
		build_tree(q_node);	
	}
}
