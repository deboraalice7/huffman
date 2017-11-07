#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>

/*
 * typedef de uma estrutura de fila de prioridade: priorityQueue
 */
typedef struct priorityQueue priorityQueue;

/*
 * typedef de uma estrutura do nó: node
 * ----------------------------
 */
typedef struct node node;

/*
 * Função: newPriorityQueue
 * -----------------------------------
 *  retorna uma nova fila de prioridade.
 */
priorityQueue* newPriorityQueue();

/*
 * Function: newNode
 * ----------------------------
 * 
 * retorna o nó criado.
 *   
 */
node* newNode(int value, int priority);

/*
 * Função: isPriorityQueueEmpty
 * ----------------------------
 *
 *   pq: Checa a fila de prioridade
 *
 *   retorna: verdadeiro caso a fila esteja vazio ou falso caso não esteja
 */
int isPriorityQueueEmpty(priorityQueue *pq);

/*
 * Função: head
 * ----------------------------
 *
 *   pq: pega a fila de prioridade
 *
 *   retorna o nó que está na frene
 */
node* head(priorityQueue *pq);

/*
 * Function: maximum
 * ----------------------------
 *
 *   pq: Pega o máximo da fila da prioridade 
 *      
 *   retorna o inteiro na frente do nó.
 *   
 */
int maximum(priorityQueue *pq);

/*
 * Function: printPriorityQueue
 * ----------------------------
 *
 *   pq: Pega o máximo da fila da prioridade 
 * 
 *   mode: separa cada nó enquanto na hora de imprimir
 * 
 *   Não retorna nada.
 *   */
void printPriorityQueue(priorityQueue *pq, char mode);

/*
 * Function: enqueuePriorityQueue
 * ----------------------------
 *
 *   value: inteiro a ser enfilerado.
 *   priority: inteiro que representa a prioridade.
 * 
 *   retorna um inteiro cujo representa o número de comparações.
 *   
 *   */
int enqueuePriorityQueue(priorityQueue *pq, int item, int priority);

/*
 * Function: dequeuePriorityQueue
 * ----------------------------
 *
 *   pq: fila a ser desenfilerada
 * 
 *   retorna um inteiro que representa o número de comparações.
 *   
 *   */
int dequeuePriorityQueue(priorityQueue *pq);

/*
 * Function: destroyPriorityQueue
 * ----------------------------
 *
 *   pq: Libera a memória
 *
 *   Não retorna nada.
 *   */
void destroyPriorityQueue(priorityQueue *pq);



#ifdef __cplusplus
}
#endif

#endif /* PRIORITYQUEUE_H */

