// Questão 12:
// Escrever uma função que insere na lista uma nova célula de conteúdo x entre
// as posições k e k + 1 de uma lista simplesmente encadeada. Apresente também a
// implementação para uma lista duplamenta encadeada.

#include <stdio.h>

#include "../lista/linkedList.c"

DoubleNode *createDoubleNode(int value) {
  DoubleNode *newNode = (DoubleNode *)malloc(sizeof(DoubleNode));

  newNode->value = value;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

void add(Node **head, int value, int k) {
  if (k < 0) return;

  Node *temp = *head;

  if (temp == NULL) {
    *head = createNode(value);
  } else if (k == 0) {
    Node *newNode = createNode(value);
    newNode->next = (*head)->next;
    *head = newNode;
  } else {
    while (temp->next != NULL && k > 0) {
      temp = temp->next;
      k--;
    }

    if (temp->next == NULL) {
      Node *newNode = createNode(value);
      temp->next = newNode;
    } else {
      Node *newNode = createNode(value);
      newNode->next = temp->next;
      temp->next = newNode;
    }
  }
}

void addDouble(DoubleNode **head, int value, int k) {
  if (k < 0) return;

  DoubleNode *temp = *head;
  DoubleNode *newNode = createDoubleNode(value);

  if (temp == NULL) {
    *head = newNode;
  } else if (k == 0) {
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
  } else {
    while (temp->next != NULL && k > 0) {
      temp = temp->next;
      k--;
    }

    if (temp->next == NULL) {
      temp->next = newNode;
      newNode->prev = temp;
    } else {
      newNode->next = temp->next;
      temp->next = newNode;
      newNode->prev = temp;
      newNode->next->prev = newNode;
    }
  }
}

int main() {
  Node *list = NULL;
  DoubleNode *doubleList = NULL;

  add(&list, 1, 0);
  add(&list, 2, 1);
  add(&list, 4, 2);
  add(&list, 5, 3);
  add(&list, 3, 1);

  addDouble(&doubleList, 1, 0);
  addDouble(&doubleList, 2, 1);
  addDouble(&doubleList, 4, 2);
  addDouble(&doubleList, 5, 3);
  addDouble(&doubleList, 3, 1);

  printList(list);
  printDoublyList(doubleList);

  return 0;
}