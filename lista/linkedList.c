#include "./linkedList.h"

#include <stdio.h>
#include <stdlib.h>

LinkedList *initList() {
  LinkedList *newList = (LinkedList *)malloc(sizeof(LinkedList));

  newList->head = NULL;
  newList->size = 0;

  return newList;
}

Node *createNode(int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));

  newNode->value = value;
  newNode->next = NULL;

  return newNode;
}

void push(LinkedList *list, int value) {
  Node *newNode = createNode(value);

  if (list->head == NULL) {
    list->head = newNode;
    list->size++;
  } else {
    Node *temp = list->head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    list->size++;
  }
}

void pushDoubleNode(DoubleNode **head, int value) {
  DoubleNode *newNode = (DoubleNode *)malloc(sizeof(DoubleNode));

  newNode->value = value;
  newNode->prev = NULL;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    DoubleNode *list = *head;
    while (list->next != NULL) list = list->next;

    newNode->prev = list;
    list->next = newNode;
  }
}

void pushNoHead(Node **head, int value) {
  Node *newNode = createNode(value);

  if (*head == NULL) {
    *head = newNode;
  } else {
    Node *list = *head;
    while (list->next != NULL) list = list->next;
    list->next = newNode;
  }
}

void printList(Node *head) {
  printf("\nLista: ");
  while (head != NULL) {
    printf("%d ", head->value);
    head = head->next;
  }
  printf("\n");
}

void printDoublyList(DoubleNode *head) {
  printf("\nLista Duplamente Encadeada: \n");
  while (head != NULL) {
    const int prev = head->prev ? head->prev->value : 0;
    const int next = head->next ? head->next->value : 0;

    printf("%d <- %d -> %d\n", prev, head->value, next);
    head = head->next;
  }
}

void freeList(LinkedList *list) {
  Node *temp = list->head;

  while (temp != NULL) {
    Node *next = temp->next;
    free(temp);
    temp = next;
  }

  free(list);
  list = NULL;
}

void freeListNoHead(Node **head) {
  Node *temp = *head;

  while (temp != NULL) {
    Node *next = temp->next;
    free(temp);
    temp = next;
  }

  *head = NULL;
}

void freeDoublyList(DoubleNode **head) {
  DoubleNode *temp = *head;

  while (temp != NULL) {
    DoubleNode *next = temp->next;
    free(temp);
    temp = next;
  }

  *head = NULL;
}