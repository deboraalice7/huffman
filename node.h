#ifndef node_h
#define node_h


typedef struct node{
	unsigned char item;
	int freq;
	struct node *next;
	struct node *left;
	struct node *right;
}Node;


Node *HEAD;
Node *dequeued;

void printll(Node *HEAD);
void add_node(char item, int freq, Node *left, Node *right);
void dequeue();
void print_pre_order(Node *tree, int *tree_size);
void build_tree(short int *q_node);
#endif
