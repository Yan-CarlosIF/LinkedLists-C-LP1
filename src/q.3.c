// Questão 3:
// Escreva uma função que copie um vetor para uma lista simplesmente encadeada.
// Apresente também a implementação para uma lista duplamenta encadeada.

#include <stdio.h>

#include "../lista/linkedList.c"

void copyArrayToList(Node **head, int arr[], int size) {
  for (int i = 0; i < size; i++) pushNoHead(&(*head), arr[i]);
}

void copyArrayToDoublyList(DoubleNode **head, int arr[], int size) {
  for (int i = 0; i < size; i++) pushDoubleNode(&(*head), arr[i]);
}

int main() {
  int array[] = {1, 2, 3, 4, 5};
  int size = sizeof(array) / sizeof(array[0]);

  Node *list = NULL;

  DoubleNode *DoublyLinkedList = NULL;

  copyArrayToList(&list, array, size);
  copyArrayToDoublyList(&DoublyLinkedList, array, size);

  // Lista Encadeada
  printList(list);

  // Lista Duplamente Encadeada
  printDoublyList(DoublyLinkedList);

  return 0;
}