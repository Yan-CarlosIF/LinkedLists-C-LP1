// Questão 4:
// Escrever uma função que exporte uma lista simplesmente encadeada para um
// vetor: int *Exportar(celula *lista). Apresente esta implementação para uma
// lista simplesmente encadeada sem cabeça e com cabeça.

#include <stdio.h>

#include "../lista/linkedList.c"

int numberOfCellsNoHead(Node *head);
int *Export(Node *head);
int *ExportWithHead(LinkedList list);

int main() {
  Node *list = NULL;

  LinkedList *listWithHead = initList();

  pushNoHead(&list, 1);
  pushNoHead(&list, 2);
  pushNoHead(&list, 3);

  push(listWithHead, 1);
  push(listWithHead, 2);
  push(listWithHead, 3);

  int *array = Export(listWithHead->head);
  int *arrayWithHead = ExportWithHead(*listWithHead);

  printf("Array: ");
  for (int i = 0; i < numberOfCellsNoHead(listWithHead->head); i++) {
    printf("%d ", array[i]);
  }

  printf("\nArray vindo da lista com head: ");
  for (int i = 0; i < listWithHead->size; i++) {
    printf("%d ", arrayWithHead[i]);
  }

  return 0;
}

int numberOfCellsNoHead(Node *head) {
  int cont = 0;

  while (head != NULL) {
    head = head->next;
    cont++;
  }

  return cont;
}

int *Export(Node *head) {
  int *array = (int *)malloc(sizeof(int) * numberOfCellsNoHead(head));

  int i = 0;

  while (head != NULL) {
    array[i] = head->value;
    head = head->next;
    i++;
  }

  return array;
}

int *ExportWithHead(LinkedList list) {
  int *array = (int *)malloc(sizeof(int) * list.size);

  int i = 0;

  while (list.head != NULL) {
    array[i] = list.head->value;
    list.head = list.head->next;
    i++;
  }

  return array;
}