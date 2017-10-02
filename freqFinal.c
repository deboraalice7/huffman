#include <stdio.h>
#include <stdlib.h>
#define MAX 257

typedef struct node{
	char item;
	int freq;
	struct node *next;
	struct node *left;
	struct node *right;
}Node;

Node *HEAD;

void printll()
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

void add_node(char item, int freq)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->item = item;
	new_node->freq = freq;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->next = NULL;
	
	if(HEAD == NULL)
		HEAD = new_node;
	else
	{
		Node *aux = HEAD;
		
		if(aux->next == NULL && aux->freq > freq)
		{
			Node *a = aux;
			new_node->next = aux;
			aux = new_node;
			HEAD = aux;
		}
		else
		{
			while(aux->next != NULL && aux->freq < freq)
				aux = aux->next;	
			new_node->next = aux;
			aux = new_node;
			HEAD = aux;		
		}			
	}
}

int main()
{
	HEAD = NULL;
	FILE *in, *out;
	char c;
	int freq[MAX] = {0}, i;
	
	in = fopen("arquivo.txt", "rb");
	out = fopen("saida.txt", "wb");
	
	if(in == NULL)
	{
		printf("Arquivo vazio\n");
		return -1;
	}
	
	while(fread(&c,sizeof(char),1,in)!=0)
	{
		freq[c]++;	
	}
	for(i = 0; i < MAX; i++)
	{
		if(freq[i])
		{
			//printf("%d %c %d", i, i, freq[i]);
			add_node(i, freq[i]);	
		}
	}	
	printll();
	return 0;
}
