// Questão 2:
// Seja uma lista simplesmente encadeada de estruturas da forma 'typedef struct
// celula { int x; struct cel *prox; } celula;'. Apresente a implementação
// iterativa e recursiva da função 'celula *busca(int x, celula *lista)', que
// verifica se x pertence à lista simplesmente encadeada.

#include <stdio.h>

#include "../lista/linkedList.c"

// Pegar um item da lista
Node *busca(Node *head, int searchedValue) {
  while (head != NULL) {
    if (head->value == searchedValue) return head;

    head = head->next;
  }

  return NULL;
}

// Pegar um item da lista recursivamente
Node *buscaRecursiva(Node *head, int searchedValue) {
  if (head == NULL) return NULL;

  if (head->value == searchedValue) return head;

  return buscaRecursiva(head->next, searchedValue);
}

int main() {
  Node *lista = NULL;

  pushNoHead(&lista, 1);
  pushNoHead(&lista, 2);
  pushNoHead(&lista, 3);

  printList(lista);

  const Node *searchedItem = busca(lista, 4);

  const Node *recursivelySearchedItem = buscaRecursiva(lista, 2);

  if (searchedItem != NULL) {
    printf("\nItem encontrado: %d", searchedItem->value);
  } else {
    printf("\nItem nao encontrado!");
  }

  if (recursivelySearchedItem != NULL) {
    printf("\nItem encontrado recursivamente: %d",
           recursivelySearchedItem->value);
  } else {
    printf("\nItem nao encontrado recursivamente!");
  }

  return 0;
}