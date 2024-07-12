#include "linked_list.h"
#include <stdio.h>
#include <string.h>

void pushFront(LinkedList *list, const void *element) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = malloc(list->elementSize);
  memcpy(newNode->data, element, list->elementSize);
  newNode->next = list->head;
  list->head = newNode;
  list->size++;
}

void deleteNode(LinkedList *list, const void *target) {
  Node **indirect = &list->head;
  while (*indirect != NULL) {
    if (list->cmp((*indirect)->data, target) == 0) {
      Node *toDelete = *indirect;
      *indirect = toDelete->next;
      free(toDelete->data);
      free(toDelete);
      list->size--;
      return;
    }
    indirect = &(*indirect)->next;
  }
}

Node *findNode(LinkedList *list, const void *target) {
  Node *current = list->head;
  while (current != NULL) {
    if (list->cmp(current->data, target) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void printList(LinkedList *list, void (*printFunc)(const void *)) {

  Node *current = list->head;
  while (current != NULL) {
    printFunc(current->data);
    current = current->next;
  }
}

void freeList(LinkedList *list) {
  Node *current = list->head;
  Node *next;

  while (current != NULL) {
    next = current->next;
    free(current->data);
    free(current);
    current = next;
  }

  list->head = NULL;
  list->size = 0;
}

void initializeList(LinkedList *list, size_t elementSize,
                    int (*cmpFunc)(const void *, const void *)) {
  list->head = NULL;
  list->size = 0;
  list->elementSize = elementSize;
  list->cmp = cmpFunc;
  list->push = pushFront;
  list->delete = deleteNode;
  list->find = findNode;
  list->print = printList;
}
