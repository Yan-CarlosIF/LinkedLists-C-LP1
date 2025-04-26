// Questão 7:
// Escreva uma função que inverta a ordem das células de uma lista simplesmente
// encadeada. Apresente também a implementação para uma lista duplamenta
// encadeada.

#include <stdio.h>

#include "../lista/linkedList.c"

void reverseList(Node **head) {
  Node *reversedList = NULL, *next = NULL;

  while (*head != NULL) {
    next = (*head)->next;
    (*head)->next = reversedList;
    reversedList = *head;
    *head = next;
  }

  *head = reversedList;
}

void reverseDoubleList(DoubleNode **head) {
  DoubleNode *list = *head, *temp = NULL;

  while (list != NULL) {
    temp = list->prev;
    list->prev = list->next;
    list->next = temp;

    list = list->prev;
  }

  if (temp != NULL) *head = temp->prev;
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

  reverseList(&list);
  reverseDoubleList(&doublyList);

  printList(list);
  printDoublyList(doublyList);

  return 0;
}