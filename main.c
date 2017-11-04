/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: MAceio
 *
 * Created on 4 de Novembro de 2017, 07:03
 */

#include <stdio.h>
#include <stdlib.h>
#include "compress.h"
#include "descompress.h"

/*
 * 
 */

int main(){

    int option;
    setlocale(LC_ALL, "Portuguese");

    while(1)
    {

        printf("  Escolha uma das opcoes: \n");
        printf("  Tecle 1 para comprimir. \n");
        printf("  Tecle 2 para descomprimir.\n  ");

        scanf("%d",&option);
        getchar();

        if(option == 1)
        {
            compress();
            //system("pause");
            break;
        }
        else if(option == 2)
        {
            descompress();
            //system("pause");
            break;
        }
        else
        {
            printf("Opcao invalida! Tente Novamente.\n");
        }
        system("cls");
    }
    getchar();
    return (EXIT_SUCCESS);
}

