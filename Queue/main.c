#include <stdlib.h>
#include <stdlib.h>
#include "queue.h"

void main (){
  Queue q;
  int x,sel;
  initialize(&q);

  for(;;){
    printf("Menu\n");
    printf("\nSELECT AN OPTION: \n");
    printf("1. INSERT\n2. REMOVE\n3. LIST\n4. EXIT\n");
    scanf("%d",&sel);
    switch(sel){
      case 1: printf("INPUT: "); scanf("%d",&x);
      if(insert(&f,x) == ERRORFULLQUEUE){
        printf("\nSTACK OVERFLOW");
      }
      else{
        printf("\nSUCCESS\n");
      }
      ;break;
      case 2: x = remove(&f);
      if(x == ERROREMPTYQUEUE){
        printf("\nEMPTY QUEUE\n");
      }
      else{
        printf("\nDELETED: %d\n",x);
      }
      ;break;
      case 3: exibe(&q) ;break;
      case 4: exit(1);break;
    }
  }

}