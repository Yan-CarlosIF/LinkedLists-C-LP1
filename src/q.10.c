// Questão 10:
// Altere a questão anterior para que seja uma lista simplesmente encadeada de
// strings (vetores de char's - Alocadas dinamicamente). Use a função 'int
// strcmp(char *string1, char *string2) ' de stdio.h. Se < 0, string1 < string2,
// se = 0, string1 = string2, se > 0, string1 > string2. Apresente também a
// implementação para uma lista duplamenta encadeada.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char *value;
  struct Node *next;
} Node;

typedef struct DoubleNode {
  char *value;
  struct DoubleNode *prev;
  struct DoubleNode *next;
} DoubleNode;

Node *createNode(char *value);
DoubleNode *createDoubleNode(char *value);
void insert(Node **head, char *value);
void insertDoubleNode(DoubleNode **head, char *value);
void printList(Node *head);
void printDoublyList(DoubleNode *head);

int main() {
  Node *list = NULL;
  DoubleNode *doublyList = NULL;

  insert(&list, "Yan");
  insert(&list, "Arthur");
  insert(&list, "Ermerson");

  insertDoubleNode(&doublyList, "Silas");
  insertDoubleNode(&doublyList, "Felipe");
  insertDoubleNode(&doublyList, "Alexandro");

  printList(list);

  printDoublyList(doublyList);

  return 0;
}

Node *createNode(char *value) {
  Node *newNode = (Node *)malloc(sizeof(Node));

  newNode->value = value;
  newNode->next = NULL;

  return newNode;
}

DoubleNode *createDoubleNode(char *value) {
  DoubleNode *newNode = (DoubleNode *)malloc(sizeof(DoubleNode));

  newNode->value = value;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

void insert(Node **head, char *value) {
  Node *newNode = createNode(value);

  if (*head == NULL) {
    *head = newNode;
  } else if (strcmp((*head)->value, value) > 0) {
    newNode->next = *head;
    *head = newNode;
  } else {
    Node *temp = *head;

    while (temp->next != NULL && strcmp(temp->next->value, value) < 0)
      temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void insertDoubleNode(DoubleNode **head, char *value) {
  DoubleNode *newNode = createDoubleNode(value);

  if (*head == NULL) {
    *head = newNode;
  } else if (strcmp((*head)->value, value) > 0) {
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
  } else {
    DoubleNode *temp = *head;

    while (temp->next != NULL && strcmp((*head)->value, value) < 0)
      temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) temp->next->prev = newNode;

    temp->next = newNode;
  }
}

void printList(Node *head) {
  printf("\nLista: [");
  while (head->next != NULL) {
    printf("'%s', ", head->value);
    head = head->next;
  }
  printf("'%s']\n", head->value);
}

void printDoublyList(DoubleNode *head) {
  printf("\nLista duplamente ligada:\n");
  while (head != NULL) {
    const char *prev = head->prev ? head->prev->value : "NULL";
    const char *next = head->next ? head->next->value : "NULL";

    printf("'%s' <- '%s' -> '%s'\n", prev, head->value, next);

    head = head->next;
  }
  printf("\n");
}