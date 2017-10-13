#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "binary_tree.h"
#define MAX 257

int main()
{
	FILE *in, *out;
	in = fopen("arquivo.txt", "rb");
	out = fopen("saida.txt", "wb");

	if(in == NULL)
	{
		printf("Arquivo vazio\n");
		return -1;
	}	
	encode(in, out);	
	return 0;
}
void set_tree(FILE *out, Node *tree)
{
  char t = tree->item;

  if(tree->left != NULL)
  {
  	fprintf(out,"%c", t);	
  	set_tree(out, tree->left);
  	set_tree(out, tree->right);	
  }
  if(t != '*')fprintf(out,"%c", t);	
}

void convertBin(short int n, unsigned char *bit)
{
	int size = 0;
	while( n > 0)
	{	
		bit[size] = (n%2)+'0';
		size++;
		n = n/2;	
	}
	//printf("%s\n", bit);
}

void write(FILE *in, FILE *out, short int tree_size)
{
	short int size_arq, i, trash;
	unsigned char c, *palavra, *bit_trash, *bit_tree_size;
	strcpy(palavra, "");
	strcpy(bit_trash, "");
	
	size_arq = ftell(in);//tamanho do arquivo
	fseek(in,0,SEEK_SET);//volta para o inicio do arquivo	
	for(i = 0; i < size_arq; i++)
	{
		c = getc(in);
		strcat(palavra,ht->table[c]->value);
	}		
	
	trash = (strlen(palavra)%8 == 0)? 0 : 8- (strlen(palavra)%8);
	convertBin(trash, bit_trash);
	convertBin(tree_size, bit_tree_size);
	
	//printf("%s %s\n", bit_trash, bit_tree_size);
	
	fprintf(out ,"%s", bit_trash);
	for(i = 3; i < 16 - strlen(bit_tree_size); i++)
		fprintf(out,"%s", "0");
	fprintf(out,"%s", bit_tree_size);
	set_tree(out, HEAD);
	fprintf(out,"%s", palavra);
}

void encode(FILE *in, FILE *out)
{
	HEAD = NULL;
	short int freq[MAX] = {0}, i, q_node = 0,tree_size = 0,size_arq;
	unsigned char byte = 0, c;
	
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
	size_tree(HEAD, &tree_size);
	//ajeitar : tam_tree atraves de outra funcao 
	printf("TAM_tree %d Letras %d\n", tree_size);
	
	BuildTable(freq);	
	print_table();

	write(in , out, tree_size);
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

void BuildTable(short int *frequencies)
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

void size_tree(Node *tree, short int *tree_size)
{
	if(tree != NULL)
	{
		*tree_size += 1;
		printf("%c %d\n", tree->item, tree->freq);
		size_tree(tree->left, tree_size);
		size_tree(tree->right, tree_size);
	}
}

void build_tree(short int *q_node)
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
		
		add_node(tree->item, tree->freq, tree->left, tree->right);;
		*q_node +=1;
		
		build_tree(q_node);	
	}
}
