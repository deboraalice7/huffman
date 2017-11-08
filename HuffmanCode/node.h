#ifndef NODE_H
#define NODE_H
#define MAX 257

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Typedef da estrutura de um nó
 */
typedef struct Node node;

struct Node{
	void *item;
	void  *freq;
	struct node *next;
	struct node *left;
	struct node *right;
};

typedef unsigned char BYTE;

/*
 * Função: frequency
 * 
 * FILE *in: recebe o arquivo de entrada
 * freq[] = recebe ponteiro de array 
 * 
 * Retorna: nada 
 */
void frequency(FILE *in, int freq[]);
/*
 * Função: set_node
 * 
 * l = Node* a ser setado
 * item: ponteiro de item
 * freq: ponteiro de frequência
 * 
/* Retorna: endereço de nó
 */
void* set_node(Node *l, void* item, void *freq);
/*
 * Função: add_node
 * 
 * HEAD = Node* representando a cabeça da lista
 * new_node = Node* representando novo nó
 * 
 * Retorna: endereço do nó da cabeça da lista
 */
void* add_node(Node *HEAD, Node *new_node);

/*
 * Função: dequeue
 * 
 * HEAD: Node* representando a cabeça da lista
 * 
 * Retorna: endereço do nó da cabeça da lista
 */
void* dequeue(Node *HEAD);
#ifdef __cplusplus
}
#endif

#endif /* NODE_H */

