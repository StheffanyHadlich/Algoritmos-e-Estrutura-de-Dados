#include "queue.h"

void initialize(Queue *q) {
  q->first = 0;
  q->last = 0;
  q->count = 0;
}

int emptyQueue(Queue *q) {
 if (q->count == 0){
 return(1);
 }
 else {
 return(0);
 }
}

int fullQueue(Queue *q){
  if (q->count == MAXSIZE){
    return(1);
  }
  else{
    return(0);
  }
}

int insert(Queue *q, int x) {
    if (fullQueue(q)) {
      return(ERRORFULLQUEUE);
    }
    else {
      q->item[q->last] = x;
      q->count++;
      if (q->last == MAXSIZE -1)
        q->last = 0;
      else
        q->last++;
        return(q->last);
  }
}

int remove(Queue *q){
  int x;
   if(emptyQueue(q)){
     return(ERROREMPTYQUEUE);
   }
   else{
     x=q->item[q->first];
     q->count--;
     if(q->first == MAXSIZE -1)
        q->first = 0;
    else
        q->first++;
   return x;
  }
}

int show(Queue *q){
  int j = q->first;
  int i;
  if(emptyQueue(q)){
    return ERROREMPTYQUEUE;
  }
  else{
    printf("\n\n--Queue--\n");
    for(i=0;i<q->count;i++){
        printf("\n%d",q->item[j]);
        if(j == MAXSIZE-1){
          j=0;
        }
        else{
          j++;
        }
    }
  }
}
