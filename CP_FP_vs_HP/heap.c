#include "heap.h"

struct Heap {
  int size;
  int capacity;
  char heapType;
  int *item;
};

Heap* createHeap(int capacity, char heapType) {
  Heap *temp = (Heap*) malloc(1 * sizeof(Heap));
  temp->size = 0;
  temp->capacity = capacity;
  temp->heapType = heapType;
  temp->item = (int*) malloc((capacity + 1) * sizeof(int));
  return(temp);
}

void swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

bool compareHeapWithType(int a, int b, char heapType) {
  if (heapType == '+')
    return(a > b);
  else // (heapType == '-')
    return(a < b);
}

int enqueueHeap(Heap *heap, int item) {
  int compares = 1;
  if (heap->size >= heap->capacity)
    printf("Heap Overflow\n");
  else
  {
    heap->item[++ heap->size] = item;

    int keyIndex = heap->size;
    int parentIndex = getParentIndex(heap, heap->size);

    while ((compares ++) && parentIndex >= 1 && compareHeapWithType(heap->item[keyIndex], heap->item[parentIndex], heap->heapType))
    {
      swap(&heap->item[keyIndex], &heap->item[parentIndex]);

      keyIndex = parentIndex;
      parentIndex = getParentIndex(heap, keyIndex);
    }
  }
  return(compares);
}

int dequeueHeap(Heap *heap) {
  int compares = 1;
  if (isHeapEmpty(heap))
  {
    printf("Heap underflow\n");
    return(compares);
  }
  else
  {
    //int item = heap->data[1];

    heap->item[1] = heap->item[heap->size];
    heap->size --;

    heapify(heap, 1, &compares);
    return(compares);
  }
}

int getParentIndex(Heap *heap, int i) {
  return(i >> 1); // Dividido por 2
}

int getLeftIndex(Heap *heap, int i) {
  return(i << 1); // Multiplicado por 2
}

int getRightIndex(Heap *heap, int i) {
  return((i << 1) + 1); // Multiplicado por 2 e adicionado 1
}

int frontHeap(Heap *heap) {
  if (isHeapEmpty(heap)) return(INT_MIN);

  return(heap->item[1]);
}

bool isHeapEmpty(Heap *heap) {
  return(!heap->size);
}

void heapify(Heap *heap, int i, int *compares) {
  (*compares) ++;

  int largest;
  int leftIndex = getLeftIndex(heap, i);
  int rightIndex = getRightIndex(heap, i);

  if (leftIndex <= heap->size && compareHeapWithType(heap->item[leftIndex], heap->item[i], heap->heapType))
    largest = leftIndex;
  else
    largest = i;

  if (rightIndex <= heap->size && compareHeapWithType(heap->item[rightIndex], heap->item[largest], heap->heapType))
    largest = rightIndex;

  if (heap->item[i] != heap->item[largest])
  {
    swap(&heap->item[i], &heap->item[largest]);
    heapify(heap, largest, &(*compares));
  }
}

int itemOf(Heap *heap, int i) {
  return(heap->item[i]);
}

void heapSort(Heap *heap) {
  int i, trash = 0;
  for (i = heap->size; i >= 2; i --)
  {
    swap(&heap->item[1], &heap->item[i]);

    heap->size --;
    heapify(heap, 1, &trash);
  }
}

void destroyHeap(Heap *heap){
  free(heap->item);
  free(heap);
}