#include "linked_list.h"
#include <stdio.h>
#include <string.h>

typedef struct {
  char name[50];
  int age;
} Person;

void printPerson(const void *data) {
  const Person *person = (const Person *)data;
  printf("Name: %s, Age: %d\n", person->name, person->age);
}

int comparePersons(const void *a, const void *b) {
  const Person *personA = (const Person *)a;
  const Person *personB = (const Person *)b;
  return strcmp(personA->name, personB->name);
}

int main() {
  LinkedList list;
  initializeList(&list, sizeof(Person), comparePersons);

  Person john = {"John Doe", 30};
  Person jane = {"Jane Smith", 25};
  Person alice = {"Alice Johnson", 28};

  list.push(&list, &john);
  list.push(&list, &jane);
  list.push(&list, &alice);

  list.print(&list, printPerson);

  printf("\nSearching for Jane Smith:\n");
  Node *found = list.find(&list, &jane);
  if (found) {
    printPerson(found->data);
  } else {
    printf("Jane Smith not found.\n");
  }

  printf("\nDeleting Alice Johnson:\n");
  list.delete(&list, &alice);
  list.print(&list, printPerson);

  freeList(&list);

  return 0;
}
