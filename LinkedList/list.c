#include "list.h"

void initialize(node **L){
  *L = NULL;
}

void goThroughList(node **L){
  node *P;
  P = *L;
  while(P != NULL){ // go through all the nodes of the list
    printf(" %d",P->info);
    P = P->link;
  }
}

int insertAtTheEnd(node **L, int x){
  node *New, *P;
  if((New = (no *) malloc(sizeof(no))) == NULL){
    return INSUFFICIENTMEMORY;
  }
  else{
    New->info=x;
    New->link=NULL;
  }
  if (*L == NULL){
    *L = N;
  }
  else{
    P = *L;
    while(P->link != NULL){ // stop search at the last node
      P = P->link;
    }
    P->link=New;
  }
  return 0;
}

int removeFromTheEnd(node **L){
  no *P, *Previous;
  int x;
  if (*L == NULL){
    return EMPTYLIST;
  }
  else{
    if ((*L)->link == NULL){
      x= (*L)->info;
      free(L);
      *L=NULL;
      return x;
    }
    else{
      P= (*L)->link;
      Previous =*L;
      while (P->link != NULL){
        P=P->link;
        Previous = Previous->link;
      }
      Previous->link=NULL;
      x=P->info;
      free(P);
      return x;
    }
  }
}

int insertAtTheBeginning(node **L, int x){
  no *New;
  if((New = (no *) malloc(sizeof(no))) == NULL){
    return INSUFFICIENTMEMORY;
  }
  New->info=x;
  New->link=*L;
  *L=New;
  return 0;
}

int removeFromTheBeginning (node **L){
  node *AUX;
  int x;
  if(*L != NULL){
    if ((*L)->link == NULL){
      x=(*L)->info;
      free(*L);
      *L=NULL;
      return x;
    }
    else{
      AUX=*L;
      x=AUX->info;
      *L=AUX->link;
      free(AUX);
      return x;
    }
  }
  else{
    return EMPTYLIST;
  }
}

int insertInOrder(node **L, int x){
  node *New, *P, *Previous;
    if((New = (no *) malloc(sizeof(no))) == NULL){
    return INSUFFICIENTMEMORY
  }
  else{
    New->info=x;
    if (*L == NULL){
      *L=New;
      New->link = NULL;
    }
    else{
      P=*L;
      while((P != NULL)&&(x>= P->info)){
        Previous = P;
        P = P->link;
      }
      if(P==*L){
        New->link=*L;
        *L=New;
      }
      else{
        Previous->link=New;
        New->link=P;
      }
    }
  return 0;
  }
}

int removeItemX(node **L,int x){
  node *P, *Previous;
  if (*L != NULL){
    P=*L;
    while((P!=NULL)&&(x != P->info)){
      Previous=P;
      P=P->link;
    }
    if(P==NULL){
      return ITEMNOTFOUND;
    }
    else{
      if(P==*L){
        *L=(*L)->link;
        free(P);
      }
      else{
        Previous->link=P->link;
        free(P);
      }
    }
  }
  else{
    return EMPTYLIST;
  }  
}

int findBigger(node **L){
  no *P;
  int bigger = 0;
  if(*L==NULL){
    return EMPTYLIST;
  }
  else{
    P=*L;
    do{
      if(P->info>bigger){
        bigger = P->info;
      }
      P=P->link;
    }while(P != NULL);
  }
  return bigger;
}

int findSmallest(node **L){
  no *P;
  int small;
  if(*L==NULL){
    return EMPTYLIST;
  }
  else{
    small = (*L)->info;
    P=*L;
    do{
      if(P->info<small){
        small = P->info;
      }
      P=P->link;
    }while(P != NULL);
  }
  return small;
}

void showInverse(node **L){
  int x;
  node *P, *AUX;
  inicializaLista(&AUX);
  P = *L;
  while(P != NULL){ 
    x = P->info;
    insereInicioLista(&AUX,x);
    P = P->link;
  }
  P = AUX;
  while(P != NULL){
    printf(" %d ",P->info);
    P=P->link;
  }
}
