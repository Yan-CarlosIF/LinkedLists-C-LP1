// Escrever uma função que concatene duas listas simplesmente encadeadas em uma
// única lista simplesmente encadeada. Apresente também a implementação para uma
// lista duplamenta encadeada.

#include <stdio.h>

#include "../lista/linkedList.c"

DoubleNode *concatDoubleList(DoubleNode *list1, DoubleNode *list2) {
  DoubleNode *concatenatedList = (DoubleNode *)malloc(sizeof(DoubleNode));
  concatenatedList = NULL;

  while (list1 != NULL) {
    pushDoubleNode(&concatenatedList, list1->value);
    list1 = list1->next;
  }

  while (list2 != NULL) {
    pushDoubleNode(&concatenatedList, list2->value);
    list2 = list2->next;
  }

  return concatenatedList;
}

int main() {
  // Implementação da lista duplamente encadeada no arquivo linkedList.h
  DoubleNode *list1 = NULL;
  DoubleNode *list2 = NULL;

  pushDoubleNode(&list1, 1);
  pushDoubleNode(&list1, 2);
  pushDoubleNode(&list1, 3);

  pushDoubleNode(&list2, 4);
  pushDoubleNode(&list2, 5);
  pushDoubleNode(&list2, 6);

  printDoublyList(list1);
  printDoublyList(list2);

  DoubleNode *concatenatedList = concatDoubleList(list1, list2);
  printf("\nLista concatenada: \n");

  printDoublyList(concatenatedList);

  return 0;
}