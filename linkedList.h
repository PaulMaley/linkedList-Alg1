struct ListElem {
  unsigned int val;
  struct ListElem *next;
};

struct LinkedList {
  struct ListElem *head;
};

struct LinkedList *reverse(struct LinkedList *l);
struct LinkedList *insertionSort(struct LinkedList *l);
void printList(struct LinkedList *l);
