#ifndef binary_tree_h
#define binary_tree_h
#define T 1000
#define MAX 257


typedef struct element{
	char key;
 	char value[T];
}Element;

typedef struct  hashtable{
	Element *table[MAX];
}Hashtable;

Hashtable* ht;

void create_hashtable();
void put(char key, char *value);
void BuildTable(short int *frequencies);
void TraverseTree(Node *HEAD, Hashtable *ht, char *prefix);
char *Concat(char *prefix, char letter);
void print_table();



#endif
