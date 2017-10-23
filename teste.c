#include <stdio.h>
#include <locale.h>
#include "compress.h"

#include <string.h>

void set_tree(FILE *out, Node *tree)
{
  if(tree != NULL)
  {
  	fprintf(out,"%c", tree->item);
  	set_tree(out, tree->left);
  	set_tree(out, tree->right);	
  }
}

unsigned char add_bit(unsigned char c_saida, short int pos){
	printf("OI |%c| %d |%c|\n", c_saida, pos, c_saida | (1<<(pos)));
    return (c_saida | (1<<(pos)));
}

void print_binary(int x, FILE *out, short int tam)
{
	int bit;
    for( bit = 1 << tam; bit != 0; bit >>= 1)
        fprintf(out,"%c", (x & bit) ? '1' : '0');
}

void write(FILE *in, FILE *out, short int tree_size)
{
	short int size_arq, i, size = 0,  j, trash;
	unsigned char c, *palavra,bit = 0;

	strcpy(palavra, "");
	size_arq = ftell(in);//tamanho do arquivo
	fseek(in,0,SEEK_SET);//volta para o inicio do arquivo	

	for(i = 0; i < size_arq; i++)
	{
		c = getc(in);
		strcat(palavra, ht->table[c]->value);
	}		
	
	
	trash = (strlen(palavra)%8 == 0)? 0 : 8- (strlen(palavra)%8);
	printf("Size %d  %d |%s|\n", trash, strlen(palavra), palavra);
	
	print_binary(trash, out, 2);
	print_binary(tree_size,out, 12);
    set_tree(out, HEAD);//ultimo
    
	fprintf(out,"%s", palavra);
}

void dequeue()
{
	if(HEAD == NULL)
		aux = NULL;
	else{
		aux = HEAD;	
		HEAD = HEAD->next;
		aux->next = NULL;		
	}
}

void frequency(FILE *in, short int *freq)
{
	char c; 
	while(fread(&c,sizeof(char),1,in)!=0)
		freq[c]++;
}

void add_node(Node *new_node,short int freq){

    if(HEAD == NULL || HEAD->freq >= new_node->freq){
        new_node->next = HEAD;
        HEAD = new_node;
    }
    else
    {
    	Node *aux = HEAD;
    	while(aux->next != NULL && aux->next->freq < new_node->freq)
        	aux = aux->next;
    	new_node->next = aux->next;
    	aux->next = new_node;
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
		tree->freq = aux->freq;
		tree->left = aux;
		*q_node -=1;

		dequeue();
		tree->freq += aux->freq;
		tree->right = aux;
		*q_node -=1;
		
		add_node(tree, tree->freq);
		*q_node +=1;
		
		build_tree(q_node);	
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

void print_table()
{
	int i;
	for(i = 0; i < MAX; i++)
	   if(ht->table[i] != NULL)	printf("%c -> %s\n", i, ht->table[i]->value);
}

unsigned char *Concat(unsigned char *prefix, unsigned char letter)
{
  	unsigned char *result = (unsigned char *)malloc(sizeof(unsigned char));
    sprintf(result, "%s%c", prefix, letter);
	return result;
}

void put(unsigned char key, unsigned char *value)
{
	Element *new_element = (Element*)malloc(sizeof(Element));	
	new_element->key = key;
	new_element->value = (unsigned char *)malloc(sizeof(unsigned char));
	strcpy(new_element->value, value);
	
	ht->table[key] = new_element;
	//uma hash de tam 256 é eficiente?
}

void TraverseTree(Node *HEAD, Hashtable *ht, unsigned char *prefix)
{
    if(HEAD != NULL)
    {
    	if(HEAD->left == NULL && HEAD->right == NULL)put(HEAD->item, prefix);
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

void BuildTable()
{
    create_hashtable();
    unsigned char *prefix = (unsigned char *)calloc(1, sizeof(unsigned char));
    TraverseTree(HEAD, ht, prefix);
}

void create_node(unsigned char item, short int freq)
{
	aux = (Node*)malloc(sizeof(Node));
	
	aux->item = item;
	aux->freq = freq;
	aux->left =NULL;
	aux->right = NULL;
	aux->next = NULL;	
}

void rebuild_huffman_tree(FILE *in, Node **HEAD, short int tree_s, unsigned char *prefix)
{	
	if(tree_s >= 1)
	{	
	    short int condition = 1;
	    unsigned char c;
	
		fscanf(in, "%c", &c);
		create_node(c, 0);
		
		if(c != '*')condition = 0;
		if(*HEAD == NULL)
		{
			*HEAD =  aux;
			//printf("%c\n", c);
			if(aux->item != '*')put(aux->item, prefix);
			tree_s -=1;	
		}
		if(condition)
		{
			rebuild_huffman_tree(in, &(*HEAD)->left, tree_s, Concat(prefix, '0'));
			rebuild_huffman_tree(in, &(*HEAD)->right, tree_s, Concat(prefix, '1'));
			free(prefix);
		}	
	}
}

void search(unsigned char *value,unsigned char *r, short int *size, FILE * out)
{
	short int i;
	//printf("Value %s\n", value);
	for(i = 0; i < MAX; i++)
	{
		if(ht->table[i] != NULL)
		{
			if(strcmp(value, ht->table[i]->value) == 0)
			{
				 //fprintf(out,"%c", ht->table[i]->value);
				 
				 sprintf(r, "%s%c",r, ht->table[i]->key);
				 *size = -1;
			}
		}	
	}
}
void write_descompress(FILE *in, FILE *out, short int trash)
{
	unsigned char *palavra, c, *r;
	short int i, size_arq, size = 0;
	palavra = (unsigned char *)malloc(sizeof(unsigned char));
	r = (unsigned char *)calloc(1, sizeof(unsigned char));
	strcpy(palavra, "");
	
	while((fscanf(in, "%c", &c)) != EOF)
	{
		palavra[size] = c;
		
		search(palavra, r, &size, out);
		if(size == -1)palavra = (unsigned char *)malloc(sizeof(unsigned char));
		
		size++;
	}
	
	printf("%d %s\n", size, r);	
	fprintf(out,"%s", r);
}


int verification(unsigned char *nome_in)
{
	char extensao[5];
	int i,j, t;
	strcpy(extensao, ".huff");
	
	j = 4;
	t = 1;
	for(i = strlen(nome_in)-1; i >= strlen(nome_in)- 5; i--)
	{
		if(nome_in[i] != extensao[j])
		{
			printf("A|%c| |%c|\n", nome_in[i], extensao[j]);
			t = 0;
			break;
		}
		j--;	
	}
	if(t == 0)printf("Arquivo nao compactado.\n");
	
	printf("Is nor %d\n", t);	
	return t;	
}

void descompress()
{
	char name_in[100], name_out[100];
	unsigned char c;
	short int trash = 0,tree_s = 0, i;
	HEAD = NULL;
	FILE *in, *out;
	
	while(1)
	{
		printf("Digite o nome do arquivo :\n");
		scanf("%[^\n]s", name_in);
		getchar();
		
		in = fopen(name_in, "rb");
		if(in == NULL)
		{
			printf("Nome inválido\nTente novamente\n");
			continue;
		}
		if(!verification(name_in))continue;
		printf("Digite o nome do arquivo de saida: \n");
		scanf("%[^\n]s", name_out);
		getchar();
		break;
	}
	//strcat(name_out,".huff");
	out = fopen(name_out, "wb");
	
	for(i =2 ; i >= 0; i--)
	{
		fscanf(in, "%c", &c);
		trash += (c - '0')<<i;
	}
	printf("Trash %d\n", trash);
	
	for(i = 12; i >= 0; i--)
	{
		fscanf(in, "%c", &c);
		tree_s +=(c - '0')<<i;
	}
	printf("Size tree %d\n", tree_s);
	
	create_hashtable();
    unsigned char *prefix = (unsigned char *)calloc(1, sizeof(unsigned char));
    rebuild_huffman_tree(in, &HEAD, tree_s, prefix);
    
    print_table();
	write_descompress(in, out, trash);  			
}

void compress()
{
	char name_in[200], name_out[200];
	short int freq[MAX] = {0}, q_node,tree_size, i;
	HEAD = NULL;
	FILE *in, *out;
	while(1)
	{
		printf("Digite o nome do arquivo :\n");
		scanf("%[^\n]s", name_in);
		getchar();
		
		in = fopen(name_in, "rb");
		if(in == NULL)
		{
			printf("Nome inválido\nTente novamente\n");
			continue;
		}
		
		printf("Digite o nome do arquivo de saida: \n");
		scanf("%[^\n]s", name_out);
		getchar();
		break;
	}
	strcat(name_out,".huff");
	printf("%s\n", name_out);
	out = fopen(name_out,"wb");
	
	frequency(in, freq);
	q_node = 0;
	for(i = 0; i < MAX; i++)
	{
		if(freq[i])
		{
			q_node++; 
			create_node(i, freq[i]);			
			add_node(aux, aux->freq);
		 }
	}
	printll(HEAD);

	build_tree(&q_node);
	tree_size = 0;
	size_tree(HEAD, &tree_size);
	printf("TRe size %d\n", tree_size);
	
	BuildTable();	
	print_table();
		
	write(in, out, tree_size);
}

int main()
{
	int option;
	
	while(1)
	{
		setlocale(LC_ALL, "Portuguese");
		printf(" Escolha uma das opções: \n");
		printf("  Tecle 1 para comprimir. \n");
        printf("  Tecle 2 para descomprimir.\n  ");

        scanf("%d",&option);
        getchar();
        printf("|%d|\n", option);
        
        if(option == 1)
        {
        	compress();
        	break;
		}
		else if(option == 2)
		{
			descompress();
			break;
		}
		else
			printf("Opção inválida! Tente novamente. \n");
	}
	
	return 0;
}/*
int main()
{
	FILE *in, *out;
	in = fopen("arq.txt", "rb");
	out = fopen("saida2.txt", "wb");

	if(in == NULL)
	{
		printf("Arquivo vazio\n");
		return -1;
	}	
	compress(in, out);
	//descompress(in, out);
	
	return 0;
}*/
