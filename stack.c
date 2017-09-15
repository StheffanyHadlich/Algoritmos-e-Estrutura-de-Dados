#include "stack.h"

void initializeStack(Stack *s){
  s->top = 0;
}

int emptyStack(Stack *s) {
  if (s->top == 0){
    return(1);
  }
  else {
    return(0);
  }
}

int fullStack(Stack *s) {
  if (s->top == MAX){
    return(1);
  }
  else {
    return(0);
  }
}

int push(Stack *s, int x){
  if (fullStack(s)) {
    return(FULLSTACKERROR);
  }
  else {
    s->item[s->top] = x;
    s->top++;
  return(s->top);
  }
}

int pop(Stack *s){
  int x;
  if (emptyStack(s) == 1){
    return (EMPTYSTACKERROR);
  }
  else{
    s->top--;
    x = s->item[s->top];
    return x;
  }
}

void show (Stack *p){
  int i;
  printf("\n-- STACK --\n");
  for(i = s->top-1;i>=0;i--){
    printf("\n%d ",s->item[i]);
  }
}