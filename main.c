#include <stdlib.h>
#include<stdio.h>
#include "stack.h"


void main(){
  Stack s;
  int x;
  initializeStack(&s);
  printf("Menu\n");
  for(;;){
    int sel;
    printf("\nSELECT AN OPTION: \n");
    printf("1. INSERT\n2. REMOVE\n3. LIST\n4. EXIT\n");
    scanf("%d",&sel);
    switch(sel){
        case 1: printf("INPUT: "); scanf("%d",&x);
        if(push(&s,x) == ERROPILHACHEIA){
          printf("\nSTACK OVERFLOW");
        }
        else{
          printf("\nSUCCESS");
        }
        break; 
        case 2:
        x = pop(&p);
        if ( x == -2){
          printf("\nEMPTY STACK %d");
        }
        else{
          printf("\nDELETED: %d",x);
        }
        break;
        case 3: show(&p);break;
        case 4: exit(1);break;
    }
  }

}
