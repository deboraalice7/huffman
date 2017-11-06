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

void write_descompress(FILE *in, FILE *out, short int trash, Node *tree){
    Node *aux = tree;
    unsigned char c, aux1;
    int *item;
    int i;

    fscanf(in, "%c", &c);
    aux1 = c;

    while(fscanf(in, "%c", &c) != EOF)
    {
        for(i = 7; i >= 0; i--)
        {
            if(aux->left == NULL && aux->right == NULL)
            {
                item = aux->item;
               // printf("A %c %d\n", *item, i);
                fprintf(out,"%c",*item);
                aux = tree;
            }
	   //1<<i divide por 2^i e compara bit a bit com aux1
            if(aux1 & 1<<i)
                aux = aux->right;
            else
                aux = aux->left;
        }
        aux1 = c;//recebe o caracter atual
    }

    for(i = 7; trash <= 8; trash++, i--)
    {
        if(aux->left == NULL && aux->right == NULL)
        {
            item = aux->item;
            //printf("B %c %d\n", *item, i);
            fprintf(out,"%c",*item);
            aux = tree;
        }
        if(aux1 & 1<<i)
            aux = aux->right;
        else
            aux = aux->left;
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
    in = fopen("new_out.huff", "rb");
    out = fopen("s.jpg", "wb");

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
    trash = c>>5;//divide 2^5
    tree_size = c & 0b00011111;
    tree_size = tree_size << 8; // Multiplica por 2^8
    
    fscanf(in, "%c", &c);
    tree_size = c | tree_size;

    //printf("TRAash %d tree_size %d\n", trash, tree_size);
	
    *freq = 0;
    tree = (Node *)rebuild_huffman_tree(in, &tree_size,freq);

    //printf("\nPRE\n");
    //print_pre_order(tree);
    //printf("Ok\n");
    if(trash == 0)trash = 8;
    write_descompress(in, out, trash, tree);
    printf("Concluido com sucesso\n");
    fclose(in);
    fclose(out);
    printf("Concluido com sucesso\n");
}
