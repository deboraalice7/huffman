#include "priorityQueue.h"

struct priorityQueue {
  node *head;
};

struct node {
  int item;
  int priority;
  node *next;
};

priorityQueue* newPriorityQueue() {
  priorityQueue *temp = malloc(1 * sizeof(priorityQueue));
  temp->head = NULL;
  return(temp);
}

node* newNode(int item, int priority) {
  node *temp = malloc(1 * sizeof(node));
  temp->item = item;
  temp->priority = priority;
  temp->next = NULL;
  return(temp);
}

int isPriorityQueueEmpty(priorityQueue *pq) {
  return(pq->head == NULL);
}

node* head(priorityQueue *pq) {
  if (isPriorityQueueEmpty(pq)) return(NULL);

  return(pq->head);
}

int maximum(priorityQueue *pq) {
  if (isPriorityQueueEmpty(pq)) return(INT_MIN);

  return(pq->head->item);
}

void printPriorityQueue(priorityQueue *pq, char mode) {
  if (isPriorityQueueEmpty(pq)) return;

  node *curr = pq->head;
  while (curr->next != NULL)
  {
    printf("%d%c", curr->item, mode);
    curr = curr->next;
  } printf("%d\n", curr->item);
}

int enqueuePriorityQueue(priorityQueue *pq, int item, int priority) {
  node *temp = newNode(item, priority);
  int compares = 1;
  if (isPriorityQueueEmpty(pq) || temp->priority > pq->head->priority)
  {
    temp->next = pq->head;
    pq->head = temp;
  }
  else
  {
    node *curr = pq->head;
    while ((compares ++) && curr->next != NULL && temp->priority < curr->next->priority)
      curr = curr->next;

    temp->next = curr->next;
    curr->next = temp;
  }
  return(compares);
}

int dequeuePriorityQueue(priorityQueue *pq) {
  if (isPriorityQueueEmpty(pq)) return(1);

  node *temp = pq->head;
  pq->head = pq->head->next;
  free(temp);

  return(1);
}

void destroyPriorityQueue(priorityQueue *pq) {
  while (!isPriorityQueueEmpty(pq))
    dequeuePriorityQueue(pq);

  free(pq);
}