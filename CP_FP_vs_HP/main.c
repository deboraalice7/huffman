#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>

#include "heap.h"
#include "priorityQueue.h"

#define CSV_HEADER "SEARCHES,PQ,HP""\n"
#define CSV_FILENAME "priorityQueue_vs_heap.csv"

/* If change this value here, change in the .R too */
#define SIZE 50

void generate_csv_file(int *searches, int *comp_pq, int *comp_heap) {
  FILE *file;
  char line[30];
  int i;

  file = fopen(CSV_FILENAME, "w");
  fputs(CSV_HEADER, file);

  for(i = 0; i < SIZE; ++i) {
    sprintf(line, "%d,%d,%d\n", searches[i], comp_pq[i], comp_heap[i]);

    fputs(line, file);
  }

  fclose(file);
}

int main() {
  int i, g;
  int searches[20000], comp_heap[20000], comp_pq[20000];

  Heap *heap = createHeap(20000, '+');
  priorityQueue *pq = newPriorityQueue();

  srand ( time(NULL) );
  for(i = 0; i < 10000; ++i) {
    g = rand()%10000;
    
    searches[i] = g;
    comp_heap[i] = enqueueHeap(heap, g);
    comp_pq[i] = enqueuePriorityQueue(pq,g,g);
    
  }
  
  generate_csv_file(searches, comp_pq, comp_heap);

  // TODO free structures

  return 0;
}