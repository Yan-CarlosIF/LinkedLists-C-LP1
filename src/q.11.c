// Questão 11:
// Escreva uma função que remova o i-ésimo item de uma lista simplesmente
// encadeada. Apresente também a implementação para uma lista duplamenta
// encadeada.

#include <stdio.h>

#include "../lista/linkedList.c"

void del(Node **head, int i) {
  if (*head == NULL || i < 0) return;  // Lista vazia ou índice inválido

  Node *temp = *head;

  if (i == 0) {
    *head = temp->next;
    free(temp);
    return;
  }

  for (int index = 0; temp != NULL && index < i - 1; index++) {
    temp = temp->next;
  }

  if (temp == NULL || temp->next == NULL) return;  // Índice fora dos limites

  Node *toRemove = temp->next;
  temp->next = toRemove->next;
  free(toRemove);
}

void delDouble(DoubleNode **head, int i) {
  if (*head == NULL || i < 0) return;  // Lista vazia ou índice inválido

  DoubleNode *temp = *head;

  if (i == 0) {
    *head = temp->next;
    if (*head != NULL) (*head)->prev = NULL;
    free(temp);
    return;
  }

  for (int pos = 0; temp != NULL && pos < i; pos++) {
    temp = temp->next;
  }

  if (temp == NULL) return;  // Índice fora dos limites

  if (temp->prev != NULL) {
    temp->prev->next = temp->next;
  }

  if (temp->next != NULL) {
    temp->next->prev = temp->prev;
  }

  free(temp);
}

int main() {
  Node *list = NULL;
  DoubleNode *doublyList = NULL;

  pushNoHead(&list, 1);
  pushNoHead(&list, 2);
  pushNoHead(&list, 3);
  pushNoHead(&list, 4);

  pushDoubleNode(&doublyList, 1);
  pushDoubleNode(&doublyList, 2);
  pushDoubleNode(&doublyList, 3);
  pushDoubleNode(&doublyList, 4);

  printList(list);
  printDoublyList(doublyList);

  del(&list, 3);
  delDouble(&doublyList, 3);

  printList(list);

  printDoublyList(doublyList);

  return 0;
}