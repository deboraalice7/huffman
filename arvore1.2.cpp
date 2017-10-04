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
Node *tree;
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
		if(aux->next == NULL && aux->freq > freq)
		{
			Node *a = aux;
			new_node->next = aux;
			aux = new_node;
			HEAD = aux;
		}
		else if(freq > aux->freq)
		{
			while(aux->next != NULL && aux->freq < freq)
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
		Node *aux = HEAD;
		HEAD = aux->next;
		aux = NULL;
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

void create_tree()
{
    tree = (Node*)malloc(sizeof(Node));
	tree->item = '*';
	tree->freq = 0;
	tree->left = NULL;
	tree->right = NULL;
	tree->next = NULL;
}

void build_tree(int *q_node)
{
	if(*q_node >= 1)
	{
		dequeue();
		if(dequeued->item == '*')dequeue();
		if(tree->left == NULL)
		{
			tree->freq = dequeued->freq;
			tree->left = dequeued;
			*q_node -=1;
		}
		else
		{
			tree->freq += dequeued->freq;
			tree->right = dequeued;
		    *q_node -=1;
			add_node(tree->item, tree->freq, tree->left, tree->right);	
		
			if( *q_node > 0)
			{
				Node *l = tree;
				create_tree();
				tree->left = l;
				tree->freq = l->freq;
			}		
		}
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
    
	create_tree();
	build_tree(&q_node);

	print_pre_order(tree);
	
	return 0;
}
