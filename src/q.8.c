// Questão 8:
// Escreva uma função que verifique se duas listas simplesmente encadeadas são
// ou não iguais.

#include <stdbool.h>
#include <stdio.h>

#include "../lista/linkedList.c"

bool ListAreTheSame(Node *list1, Node *list2) {
  while (list1 != NULL && list2 != NULL) {
    if (list1->value != list2->value) return false;
    list1 = list1->next;
    list2 = list2->next;
  }

  return (list1 == NULL && list2 == NULL);
}

int main() {
  Node *list1 = NULL;
  Node *list2 = NULL;

  pushNoHead(&list1, 1);
  pushNoHead(&list1, 2);
  pushNoHead(&list1, 3);

  pushNoHead(&list2, 1);
  pushNoHead(&list2, 2);
  pushNoHead(&list2, 3);

  if (ListAreTheSame(list1, list2)) {
    printf("\nAs duas listas sao iguais!");
  } else {
    printf("\nAs duas listas nao sao iguais!");
  }

  freeListNoHead(&list1);
  freeListNoHead(&list2);

  return 0;
}