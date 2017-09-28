#include <stdio.h>
#include <stdlib.h>
#define EMPTYLIST -1;
#define INSUFFICIENTMEMORY -2;
#define ITEMNOTFOUND -3;

typedef struct NodeTag {
  int info;
  struct NodeTag *link;
} node;

void initialize(node **L);
void goThroughList(node **L);
int insertAtTheEnd(node **L, int x);
int removeFromTheEnd(node **L);
int insertAtTheBeginning(node **L, int x);
int removeFromTheBeginning (node **L);
int insertInOrder(node **L, int x);
int removeItemX(node **L,int x);
int findBigger(node **L);
int findSmallest(node **L);
void showInverse(node **L);