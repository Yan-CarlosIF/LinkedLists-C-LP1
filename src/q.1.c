// Questão 1:
// Escreva uma função que conta o no de células de uma lista simplesmente
// encadeada. Apresente a implementação para uma lista encadeada sem cabeça.
// Apresente esta implementação para uma lista encadeada com cabeça.

#include <stdio.h>

#include "../lista/linkedList.c"

// Pegar o tamanho da lista com head
int numberOfCells(LinkedList *list) {
  Node *temp = list->head;

  int cont = 0;
  printf("Lista: ");
  while (temp != NULL) {
    printf("%d ", temp->value);
    temp = temp->next;
    cont++;
  }

  return cont;
}

// Pegar o tamanho da lista sem head
int numberOfCellsNoHead(Node *head) {
  int cont = 0;

  while (head != NULL) {
    head = head->next;
    cont++;
  }

  return cont;
}

int main() {
  LinkedList *list = initList();

  push(list, 1);
  push(list, 2);
  push(list, 3);

  printf("\nNumero de celulas: %d", numberOfCells(list));
  printf("\nNumero de celulas: %d", numberOfCellsNoHead(list->head));

  return 0;
}