/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "descompress.h"

int verification(unsigned char *nome_in)//desc
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
            t = 0;
            break;
	}
	j--;
    }
    if(t == 0)printf("Arquivo nao compactado.\n");
    return t;
}

int is_bit_i_set(unsigned char c, int j)
{
	unsigned char mask = 1<<j;
	return (mask & c);
}

void write_descompress(FILE *in, FILE *out, short int trash, Node *tree)
{
    Node *aux = tree;
    int *item = (int *)malloc(sizeof(int));
    unsigned char c, aux1;
    int i, j, bit_set;

    while(fscanf(in, "%c", &c) != EOF)
    {
	aux1 = c;
        for(i = 7; i >= 0; i--)
        {
            bit_set = is_bit_i_set(c,  i);
            if(bit_set)
                aux = aux->right;
            else
                aux = aux->left;

            if(aux->left == NULL && aux->right == NULL)
            {
            	item = aux->item;
                fprintf(out,"%c",*item);
                aux = tree;
            }	    
        }
    }  
    for(i = 7; trash <= 8; trash++, i++)
    {
    	bit_set = is_bit_i_set(c,  i);
    	//printf("%d\n", bit_set);
      	if(bit_set)
            aux = aux->right;
        else
            aux = aux->left;
                
        if(aux->left == NULL && aux->right == NULL)
        {
            item = aux->item;
           //printf("A %c %d\n", *item, i);
            fprintf(out,"%c",*item);
            aux = tree;
        }
    }
    return ;
}


void descompress()
{
    char name_in[100], name_out[100];
    unsigned char c;
    short int trash = 0,tree_size = 0, i;
    char *item = (char *)malloc(sizeof(char));
    int *freq = (int *)malloc(sizeof(freq));
    int *aux = (int *)malloc(sizeof(freq));
    Node *tree = (Node *)malloc(sizeof(Node));
	
    tree = NULL;
    FILE *in;
    FILE *out;
    in = fopen("sadia.huff", "rb");
    out = fopen("s.txt", "wb");

	/*while(1)
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
	out = fopen(name_out, "wb");*/

    fscanf(in, "%c", &c);
    trash = c>>5;
    tree_size = c & 0b00011111;
    tree_size = tree_size << 8;
    
    fscanf(in, "%c", &c);
    tree_size = c | tree_size;

    printf("TRAash %d tree_size %d\n", trash, tree_size);

    *freq = 0;
    tree = (Node *)rebuild_huffman_tree(in, &tree_size,freq);

    //printf("\nPRE\n");
    //print_pre_order(tree);
    //printf("Ok\n");
    if(trash == 0)trash = 8;
    write_descompress(in, out, trash, tree);
    fclose(in);
    fclose(out);
    printf("Concluido com sucesso\n");
}