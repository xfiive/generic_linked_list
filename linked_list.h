#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct Node {
  void *data;
  struct Node *next;
} Node;

typedef struct LinkedList LinkedList;

struct LinkedList {
  Node *head;
  size_t size;
  size_t elementSize;
  int (*cmp)(const void *, const void *);
  void (*push)(struct LinkedList *, const void *);
  void (*delete)(struct LinkedList *, const void *);
  Node *(*find)(struct LinkedList *, const void *);
  void (*print)(struct LinkedList *, void (*)(const void *));
};

void pushFront(LinkedList *list, const void *element);
void deleteNode(LinkedList *list, const void *target);
Node *findNode(LinkedList *list, const void *target);
void printList(LinkedList *list, void (*printFunc)(const void *));
void freeList(LinkedList *list);
void initializeList(LinkedList *list, size_t elementSize,
                    int (*cmpFunc)(const void *, const void *));

#endif
