#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char** args) {
  // Make a list by prepending (pushing) new elements
  struct ListElem *current = NULL;
  for (unsigned int i=0; i<10; i++){
    struct ListElem *p = (struct ListElem *) malloc(sizeof(struct ListElem));
    p->val = i*7 % 11;
    p->next = current;
    current = p; 
  }
  struct LinkedList LL = {current};
  printList(&LL);

  // Reverse the list 
  struct LinkedList *pLL;
  pLL = reverse(&LL);
  // pLL = &LL;
  printList(pLL);

  // Sort the list 
  pLL = insertionSort(pLL);
  printList(pLL);

  // Push a value
  push(pLL, 100);
  printList(pLL);

  printf("Head of list: %d\n", peek(pLL));

  // Pop a value
  printf("Pop value: %d\n", pop(pLL));
  printf("Pop value: %d\n", pop(pLL));
  printf("Pop value: %d\n", pop(pLL));
  printList(pLL);
  
  return 0;
}


