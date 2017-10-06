#include <stdio.h>
#include <stdlib.h>
#define MAX 256

typedef struct node{
	char item;
	int freq;
	struct node *next;
	struct node *left;
	struct node *right;
}Node;

Node *HEAD;
Node *dequeued;

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

void print_pre_order(Node *tree)
{
	if(tree != NULL)
	{
		printf("%c %d\n", tree->item, tree->freq);
		print_pre_order(tree->left);
		print_pre_order(tree->right);
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


int main()
{
	HEAD = NULL;
	FILE *in, *out;
	char c;
	int freq[MAX] = {0}, i, q_node = 0;

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

    	printll(HEAD);//imprimi a lista ordenada
    
	build_tree(&q_node);

	print_pre_order(HEAD);
	
	return 0;
}
