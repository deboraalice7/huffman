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
		//printll(HEAD);		
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

void build_tree()
{
	if(HEAD != NULL)
	{
		dequeue();
		if(tree->left == NULL)
		{
			tree->freq = dequeued->freq;
			tree->left = dequeued;
//			printf("L %c\n", dequeued->item);
		}
		else
		{
			tree->freq += dequeued->freq;
			tree->right = dequeued;
			add_node(tree->item, tree->freq, tree->left, tree->right);	
		//	printll(HEAD);
	     	printll(HEAD);
			//print_pre_order(HEAD);
			HEAD = HEAD->next;
			if(HEAD != NULL)
			{
				Node *l = tree;
				create_tree();
				tree->left = l;
				tree->freq = l->freq;
			}
//			printf("R %c\n", dequeued->item);
			
		}
		
		build_tree();	
	}
}


int main()
{
	HEAD = NULL;
	tree = NULL;
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
		freq[c]++;

	for(i = 0; i < MAX; i++)
		if(freq[i]) add_node(i, freq[i], NULL, NULL);

    printll(HEAD);
	create_tree();
	build_tree();

	printf("F\n");
//	print_pre_order(tree);
	
	return 0;
}
