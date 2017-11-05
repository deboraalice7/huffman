/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "compress.h"

unsigned char add_bit(unsigned char c_saida, short int pos)
{
	 return (c_saida | (1<<(7-pos)));
}

void write_compress(FILE *in, FILE *out, short int tree_size, Hashtable *ht, Node* tree)
{
    unsigned char c = 0, item =0, trash;
    short int tam =0, i, size = 0;
    fprintf(out,"%c", c);
    fprintf(out,"%c", c);

    set_tree(out, tree);
    fseek(in,0,SEEK_SET);//volta para o inicio do arquivo

    while((fscanf(in,"%c",&c)) != EOF)
    {
	tam = strlen((char *)ht->table[c]->value);
	unsigned char a[tam];
        strcpy(a, (char*)ht->table[c]->value);
        
	i = 0;
	while(i < tam)
	{
            if(size == 8)
	    {
                fprintf(out,"%c", item);
                size = 0;
                item = 0;
            }
	    if(a[i] & 1)item = add_bit(item,size);	
            ++size;
            i++;
        }
    }
    fprintf(out,"%c", item);
    
    printf("trash %d size %d  tree_size %d\n", 8-size,size, tree_size);
    trash = (8 - size)<<5;
    
    fseek(out,0,SEEK_SET);

    trash = trash | tree_size>>8;
    fprintf(out,"%c", trash);

    trash = tree_size & 255;
    fprintf(out,"%c", trash);	
}

void* BuildTable(Node *HEAD, Hashtable *ht, short int *tree_size)
{
    unsigned char prefix[2];
    ht = (Hashtable *)create_hashtable(ht);
    prefix[0] = 0;
    ht = (Hashtable *)TraverseTree(HEAD, &(*tree_size), prefix,0, ht);
    return ht;
}

void compress()
{
	char name_in[200], name_out[200], c;
	short int q_node, tree_size;
	int i,j;
	int (*freq)[MAX] = (int (*)[MAX])malloc(sizeof(int));
	int *aux = (int *)malloc(sizeof(int));
	int item[MAX] = {0};
	
	//FILE *in;
	//FILE *out;
	FILE *in = fopen("teste.jpg", "rb");
	FILE *out = fopen("new_out.huff", "wb");

	/*
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
	out = fopen(name_out,"wb");*/

	Node *list = (Node *)malloc(sizeof(Node));
	list = NULL;

	for(i =0 ; i < MAX; i++)
	{
		item[i] = i;
		(*freq)[i] = 0;		
	}
	frequency(in, freq);
        
	q_node = 0;
	i = 0;
	while(i < MAX)
	{
            if((*freq)[i])
            {
		q_node++;
                Node *new_node = (Node *)malloc(sizeof(Node));
                new_node = (Node *)set_node(new_node, &(item[i]), &(*freq)[i]);
                list = (Node *)add_node(list, new_node);
            }
            i++;
	}
    //
        printll(list);
    
    
    list = (Node *)build_tree(list, &q_node, aux, aux);
    //print_pre_order(list);
    
    
    printf("2Aguarde ...\n");
    tree_size = 0;
    Hashtable *ht = BuildTable(list,ht, &tree_size);
    print_table(ht);
    write_compress(in, out, tree_size, ht, list);
    fclose(in);
    fclose(out);
    printf("Concluido com exito!");
}