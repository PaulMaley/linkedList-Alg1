#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

struct LinkedList *reverse(struct LinkedList *l) {
  struct ListElem *c;
  struct ListElem *t;
  struct ListElem *p;

  // Short circuiting in || or crash
  // List is length 0 or 1
  if (l->head == NULL || l->head->next == NULL) 
    return l;
  
  c = l->head->next;
  l->head->next = NULL;
  p = l->head;
  while (c->next != NULL) {
//    printf("p.val : %d, c.val ; %d\n",p->val,c->val);
    t = c->next;
    c->next = p;
    p = c;
    c = t; 
  }
  // Link to previous element
  c->next = p;
   
  l->head = c;
  return l;
}

void printList(struct LinkedList *l) {
  struct ListElem *p;
  printf("[");
  if(l->head != NULL) {
    p = l -> head;
    printf("%d",p->val);
    p = p->next;
    while (p != NULL) {
      printf(",%d",p->val);
      p = p->next;
    }
  }   
  printf("]\n");
}

void printListElements(struct ListElem *ple) {
  struct LinkedList LL = {ple};
  printList(&LL);
}

struct LinkedList *insertionSort(struct LinkedList *l) {
  // List is length 0 or 1
  if (l->head == NULL || l->head->next == NULL) 
    return l;
 
  // Elements preceding h have been ordered (increasing) 
  // dh (dummy element) allows us to insert at the head
  struct ListElem dh = {-1,l->head};
  struct ListElem *p = &dh;
  struct ListElem *h = p->next->next; //l->head->next->next; 
  struct ListElem *t;

  // Terminate ordered part of list
  p->next->next = NULL; 

  while(h != NULL){
    //printf("current h->val : %d\n", h->val);
    //printListElements(&dh);

    // insert in correct place   
    p = &dh; // l->head;
    t = h->next;
    //printf("p->next->val %d, h->val %d\n ",p->next->val,h->val);
    // Advance while the element to insert is < the next element
    // or until we get to the next-to-last element
    while(p->next->val < h->val && p->next->next != NULL) {
      //printf("  current p : %d\n",p->next->val);
      p = p->next; 
    }
    if (p->next->val >= h->val) {
      // insert here - quit loop because of comparison
      h->next = p->next; 
      p->next = h;
    } else {
      // insert after - quit loop because no more elements
      p->next->next = h;
      h->next = NULL;
    }
    // Move on
    h = t;
  }
  l->head = dh.next;
  return l;
}

