#ifndef HEAP_H
#define HEAP_H

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
 * typedef de uma estrutura heap: Heap
 * ----------------------------
 */
typedef struct Heap Heap;

/*
 * Função: createHeap
 * ----------------------------
 *   capacity: inteiro de capacidade máxima
 *
 *   retorna: Heap* de uma heap criada.
 */
Heap* createHeap(int capacity);

/*
 * Function: enqueueHeap
 * ----------------------------
 *   heap: Heap* para ser enfileirada
 *   item: inteiro a ser infilerado na heap 
 *
 *  retorna: um inteiro de comparações
 *   
 */
int enqueueHeap(Heap *heap, int item);

/*
 * Function: getParentIndex
 * ----------------------------
 *   heap: Heap* para pegar o parente
 *   i: inteiro para pega o índice
 *
 *  retorna: um parente inteiro
 *  
 */
int getParentIndex(Heap *heap, int i);

/*
 * Function: getLeftIndex
 * ----------------------------
 *   heap: Heap* para pegar o parente
 *   i: inteiro para pega o índice
 *
 *  retorna: um parente inteiro do índice esquerdo
 *
 */
int getLeftIndex(Heap *heap, int i);

/*
 * Function: getRightIndex
 * ----------------------------
 *    heap: Heap* para pegar o parente
 *    i: inteiro para pega o índice
 *
 *   retorna: um parente inteiro do índice direito
 */
int getRightIndex(Heap *heap, int i);

/*
 * Function: frontHeap
 * ----------------------------
 *   heap: Heap* para pegar a cabeça
 *
 *   retorna: um inteiro que é a cabeça
 */
int frontHeap(Heap *heap);

/*
 * Function: isHeapEmpty
 * ----------------------------
 *   heap: Heap* a ser checada
 *
 *   retorna: verdadeiro se vazia, e falso se não estiver
 * 
 */
bool isHeapEmpty(Heap *heap);

/*
 * Function: heapify
 * ----------------------------
 *   heap: Heap* para criar a heapify
 *   i: inteiro onde começa a heapify
 *   compares: inteiro com o número de comparações 
 *   
 *   retorna: nada
 */
void heapify(Heap *heap, int i, int *compares);

/*
 * Function: itemOf
 * ----------------------------
 *   heap: Heap* a ser pega 
 *   i: índice inteiro a ser pego 
 *   
 *   retorna: um item inteiro
 */
int itemOf(Heap *heap, int i);

/*
 * Function: heapSort
 * ----------------------------
 *   heap: Heap* a ser ordenada
 *   
 *   retorna: nada
 */
void heapSort(Heap *heap);

/*
 * Function: dequeueHeap
 * ----------------------------
 *   heap: Heap* a ser desenfilerada 
 *   
 *   retorna: nada
 */
int dequeueHeap(Heap *heap);

/*
 * Function: destroyHeap
 * ----------------------------
 *   heap: Heap* para liberar a memória   
 *   
 *   retorna: nada
 */
void destroyHeap(Heap *heap);



#ifdef __cplusplus
}
#endif

#endif /* HEAP_H */

