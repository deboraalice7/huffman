#ifndef TREE_H
#define TREE_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Função:print_pre_order
 * 
 * tree: Node* a ser impresso
 * 
 * retorna: nada
 *  
 */
void print_pre_order(Node *tree);

/*
 * Função: build_tree
 * 
 * HEAD: Node* que é a cabeça da lista
 * freq: ponteiro de frequência
 * q_node: ponteiro de item
 * 
 * Retorna: endereço do nó da cabeça da árvore
 */
void* build_tree(Node *HEAD, int *freq, int *q_node);

/*
* Função: set_tree
 * 
 * out: FILE* de saída a ser escrito em pré-ordem
 * tree: Node* representando a cabeça da árvore
 * 
 * Retorna: nada
 * 
*/
void set_tree(FILE *out, Node *tree);
/*
* 
 * Função: rebuild_huffman_tree
 * 
 * in: FILE* de entrada
 * tree_size: tamanho da árvore
 * c: char 
 * freq: ponteiro de frequência
 *  
 * Retorna: endereço do nó da cabeça da árvore
*/
void* rebuild_huffman_tree(FILE *in,int *tree_size, char c[], void *freq);
/*
 *  Funçao: TraverseTree
 * 
 * HEAD: Node* representando a cabeça
 * tree_size: tamanho da árvore
 * prefix:
 * position: 
 * table: 
 * Retorna: um tabela
*/
void* TraverseTree(Node *HEAD,int *tree_size, unsigned char *prefix, int position, unsigned char table[][200]);
#ifdef __cplusplus
}
#endif

#endif /* TREE_H */

