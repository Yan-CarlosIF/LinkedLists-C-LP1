// Questão 9:
// Criar uma lista simplesmente encadeada (de inteiros) onde as células sempre
// estarão ordenadas em ordem crescente pelo campo info. Implemente as operação
// Inserir que faz a Inserção na posição correta. Apresente também a
// implementação para uma lista duplamenta encadeada.

#include <stdio.h>

#include "../lista/linkedList.c"

void insert(Node **head, int value) {
  Node *newNode = createNode(value);

  if (*head == NULL) {
    *head = newNode;
  } else if ((*head)->value > value) {
    newNode->next = *head;
    *head = newNode;
  } else {
    Node *list = *head;

    while (list->next != NULL && list->next->value < value) list = list->next;

    newNode->next = list->next;
    list->next = newNode;
  }
}

void insertDouble(DoubleNode **head, int value) {
  DoubleNode *newNode = (DoubleNode *)malloc(sizeof(DoubleNode));

  newNode->next = NULL;
  newNode->prev = NULL;
  newNode->value = value;

  if (*head == NULL) {
    *head = newNode;
  } else if ((*head)->value > value) {
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
  } else {
    DoubleNode *list = *head;

    while (list->next != NULL && list->next->value < value) list = list->next;

    newNode->next = list->next;
    newNode->prev = list;

    if (list->next != NULL) list->next->prev = newNode;

    list->next = newNode;
  }
}

int main() {
  Node *list = NULL;
  DoubleNode *doublyList = NULL;

  insert(&list, 3);
  insert(&list, 2);
  insert(&list, 6);
  insert(&list, 1);

  insertDouble(&doublyList, 3);
  insertDouble(&doublyList, 2);
  insertDouble(&doublyList, 6);
  insertDouble(&doublyList, 1);

  printList(list);
  printDoublyList(doublyList);

  return 0;
}