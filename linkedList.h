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

/* Stack-like operations */
// bool isEmpty(struct LinkedList *l);
void push(struct LinkedList *l, int val);
int peek(struct LinkedList *l);
int pop(struct LinkedList *l);

