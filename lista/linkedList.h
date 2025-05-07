#ifndef LINKED_LIST
#define LINKED_LIST

// Para listas duplamente encadeadas
typedef struct DoubleNode {
  int value;
  struct DoubleNode *prev;
  struct DoubleNode *next;
} DoubleNode;

// Para listas encadeadas
typedef struct Node {
  int value;
  struct Node *next;
} Node;

// Para listas usando o head
typedef struct {
  Node *head;
  int size;
} LinkedList;

LinkedList *initList();
Node *createNode(int value);
void push(LinkedList *list, int value);  // Para listas com head
void pushDoubleNode(DoubleNode **head, int value); // Para listas duplamente encadeadas
void pushNoHead(Node **head, int value);  // Para listas sem head
void printList(Node *head);
void printDoublyList(DoubleNode *head);
void freeList(LinkedList *list);
void freeListNoHead(Node **head);
void freeDoublyList(DoubleNode **head);
#endif