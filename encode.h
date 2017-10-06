#ifndef encode_h
#define encode_h
#define T 10000
//ajeitar o tamanho T
#define MAX 257

typedef struct node{
	unsigned char item;
	int freq;
	struct node *next;
	struct node *left;
	struct node *right;
}Node;

typedef struct element{
	char key;
 	char value[T];
}Element;

typedef struct  hashtable{
	Element *table[MAX];
}Hashtable;

Node *HEAD;
Node *dequeued;

void printll(Node *HEAD);
void add_node(char item, int freq, Node *left, Node *right);
void dequeue();
void print_pre_order(Node *tree, int *tam_tree);
void build_tree(int *q_node);

void create_hashtable();
void put(char key, char *value);
void BuildTable(int *frequencies);
void TraverseTree(Node *HEAD, Hashtable *ht, char *prefix);
char *Concat(char *prefix, char letter);
void print_table();

#endif
