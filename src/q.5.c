// Questão 5:
// Escrever uma função que crie e retorne uma cópia de uma lista simplesmente
// encadeada passada como parâmetro. Apresente também a implementação para uma
// lista duplamenta encadeada.

#include <stdio.h>

#include "../lista/linkedList.c"

Node *copyList(Node *head) {
  Node *newList = (Node *)malloc(sizeof(Node));
  newList = NULL;

  while (head != NULL) {
    pushNoHead(&newList, head->value);
    head = head->next;
  }

  return newList;
}

DoubleNode *copyDoublyList(DoubleNode *head) {
  DoubleNode *newList = (DoubleNode *)malloc(sizeof(DoubleNode));
  newList = NULL;

  while (head != NULL) {
    pushDoubleNode(&newList, head->value);
    head = head->next;
  }

  return newList;
}

int main() {
  Node *list = NULL;

  DoubleNode *doublyList = NULL;

  pushNoHead(&list, 1);
  pushNoHead(&list, 2);
  pushNoHead(&list, 3);

  pushDoubleNode(&doublyList, 1);
  pushDoubleNode(&doublyList, 2);
  pushDoubleNode(&doublyList, 3);

  Node *copiedList = copyList(list);
  DoubleNode *copiedDoublyList = copyDoublyList(doublyList);

  printList(copiedList);
  printDoublyList(copiedDoublyList);

  return 0;
}