#include <stdio.h>
#include <stdlib.h>
#define LISTAVAZIA -1
#define MEMORIAINSUFICIENTE -2
#define  ITEMNAOENCONTRADO -3

typedef struct NoTag {
int info;
struct NoTag *next;
struct NoTag *prev;
} no;

void inicializaLDLC(no **L);
void percorreLDLC(no **L);
int insereFinalLDLC(no **L, int x);
int removeFinalLDLC(no **L);
int insereInicioLDLC (no **L, int x);
int removeInicioLDLC(no **L);
int verificaItem(no **L, int x);
int contItem(no**L);
int encontraMaior (no **L);
void exibeInversa(no **L);
int encontraMenor(no **L);
int removeItemX(no **L, int x);
int insereListaOrdenada(no **L,int x);

void main(){
  no *L;
  int x,y,sel;
  inicializaLDLC(&L);
  for(;;){
    printf("\n\n--Menu--\n\n1. Insere item no final\n2. Remove item do final\n3. Exibe lista\n4. Insere item no inicio\n5. Remove item no inicio\n6. Verifica item\n7. Conta itens\n8. encontra Maior\n9. encontra Menor\n10. Sair\n11. Exibe lista inversa\n12. Remove item x\n13. Insere lista ordenada\n");
    scanf("%d",&sel);
    system("cls");
    switch(sel){
      case 1: printf("\nEntre com o valor a ser inserido: ");
      scanf("%d",&x);
      if((insereFinalLDLC(&L,x)) == -2){
        printf("\nMemoria insuficiente. Nao foi possivel inserir o no.");
      }
      else{
        printf("\nItem inserido com sucesso\n");
      }
     break;
     case 2: x = removeFinalLDLC(&L);
     if(x==LISTAVAZIA){
       printf("\nLista vazia");
     }
     else{
       printf("\nO item %d foi removido",x);
     }
     break;
     case 3: printf("\n--Lista--\n");
     percorreLDLC(&L); break;
     case 4: printf("\nEntre com o numero que deseja inserir no inicio: ");
     scanf("%d",&x);
     if((insereInicioLDLC(&L,x))== MEMORIAINSUFICIENTE){
       printf("\nMemoria insuficiente");
     }
     else{
       printf("\nItem inserido com sucesso");
     }
     break;
     case 5: x=removeInicioLDLC(&L);
     if(x==LISTAVAZIA){
       printf("\nLista Vazia");
     }
     else{
       printf("\nO item %d foi removido",x);
     }
     break;
     case 6: printf("\nEntre com o numero que deseja verificar: ");
     scanf("%d",&x);
     y=verificaItem(&L,x);
     if(y==1){
       printf("\nO item %d esta na lista",x);
     }
     else if(y==ITEMNAOENCONTRADO){
       printf("\nItem nao encontrado");
     }
     else{
       printf("\nLista Vazia");
     }
     break;
     case 7: x = contItem(&L);
     printf("\nA lista contem %d elemento(s)",x);
     break;
     case 8: x = encontraMaior(&L);
     if(x != LISTAVAZIA){
       printf("\nO maior item da lista eh o %d",x);
     }
     else{
       printf("\nLista Vazia");
     }
     break;
     case 9: x = encontraMenor(&L);
     if(x != LISTAVAZIA){
       printf("\nO menor item da lista eh o %d",x);
     }
     else{
       printf("\nLista Vazia");
     }
     break;
     case 10: exit(1);break;
     case 11: printf("\n--Lista Inversa--\n");
     exibeInversa(&L); break;
     case 12: printf("\nEntre com o item que deseja excluir: ");
     scanf("%d",&x);
     y = removeItemX(&L,x);
     if(y==LISTAVAZIA){
       printf("\nLista vazia");
     }
     else if(y==ITEMNAOENCONTRADO){
       printf("\nItem nao encontrado");
     }
     else{
       printf("\nO item %d foi removido com sucesso",x);
     }
     break;
     case 13: printf("\nEntre com o item que deseja inserir: ");
     scanf("%d",&x);
     if((insereListaOrdenada(&L,x))==MEMORIAINSUFICIENTE){
       printf("\nmemoria insuficiente");
     }
     else{
       printf("\nItem inserido com sucesso");
     }
   }
  }
}

void inicializaLDLC(no **L){
  *L = NULL;
}

void percorreLDLC(no **L){
  no *P;
  if(*L!=NULL){
    P = *L;
    do{
      printf(" %d",P->info);
      P = P->next;
    } while(P != *L);// percorre todos os nós da Lista ate chegar novamente no primeiro
  }
}

void exibeInversa(no **L){
  no *P;
  if(*L!=NULL){
    P = (*L)->prev;;
    do{
      printf(" %d",P->info);
      P = P->prev;
    } while(P != (*L)->prev);// percorre todos os nós da Lista ate chegar novamente no primeiro
  }
}

int insereFinalLDLC(no **L, int x){
  no *N, *P;
  if((N = (no *) malloc(sizeof(no))) == NULL){
    return MEMORIAINSUFICIENTE;
  }
  else{
    N->info=x;
  }
  if (*L == NULL){ // se a lista estiver vazia
    *L = N;
    (*L)->prev=N;
    (*L)->next=N;
  }
  else{ // se houver elementos
    P = (*L)->prev; //ultimo elemento da lista
    (*L)->prev=N; // aponta para o novo ultimo no
    N->next=*L;
    N->prev=P;
    P->next=N;
  }
}

int removeFinalLDLC(no **L){
  no *P, *AUX;
  int x;
  if (*L == NULL){ // se a lista estiver vazia
    return LISTAVAZIA;
  }
  else{// tem elementos
    P=(*L)->prev; // P recebe o endereco do ultimo elemento
    if ((*L)->next == (*L)->prev){ //só tem um elemento na lista
      x= (*L)->info;
      free(*L);
      *L=NULL;
      return x;
    }
    else{ //se tiver mais elementos
      AUX=P->prev; // recebe o endereco do penultimo elemento
      (*L)->prev=AUX; // endereco do novo ultimo elemento
      AUX->next=*L; // o novo ultimo elemento recebe o primeiro
      x= P->info; // regasta valor exluico
      free(P); // exclui o no
      return x;
    }
  }
}

int insereInicioLDLC (no **L, int x){
  no *N, *AUX;
  if((N = (no *) malloc(sizeof(no))) == NULL){
    return MEMORIAINSUFICIENTE;
  }
  N->info=x;
  if(*L==NULL){
    *L=N;
    (*L)->prev=N;
    (*L)->next=N;
  }
  else{
    AUX = (*L)->prev;
    N->prev=(*L)->prev;
    N->next=*L;
    (*L)->prev=N;
    *L=N;
    AUX->next=N;
  }
  return 0;
}

int removeInicioLDLC (no **L){
  no *P, *AUX;
  P=*L;
  int x;
  if(*L != NULL){ // se a lista nao estiver vazia
    if((*L)->next==*L){ // só tem um item
        x=(*L)->info;
        free(P);
        *L=NULL;
    }
    else{
      AUX = P->prev;
      *L = P->next; // L recebe o 2 elemento
      (*L)->prev=P->prev; //O novo primeiro elemento aponta para o ultimo
      AUX->next=*L; // o ultimo aponta para o novo primeiro elemento
      x=P->info;
      free(P);
    }
    return x;
  }
  else{
    return LISTAVAZIA;
  }
}

/* 3. Desenvolver uma função que verifique se determinado item existe ou não
em uma LLC. O algoritmo deve receber a lista e o valor a ser encontrado
como parâmetros. */

int verificaItem(no **L,int x){
  no *P;
  P=*L;
  if(*L == NULL){
    return LISTAVAZIA;
  }
  else{
    do{
      if(x==P->info){
        return 1; // o item esta na lista;
      }
      P=P->next;
    }while(P != (*L)->next);
    return ITEMNAOENCONTRADO;
  }
}

/* 4. Desenvolver uma função que retorne o número de elementos de uma LLC. */

int contItem(no **L){
  int cont = 0;
  no *P;
  P=*L;
  if(*L==NULL){
    return LISTAVAZIA;
  }
  else{
    do{
      cont++;
      P=P->next;
    } while(P != *L);
  }
  return cont;
}

/* 5. Desenvolver uma função que retorne o maior valor armazenado de uma LLC. */

int encontraMaior(no **L){
  int maior;
  no *P;
  if (*L==NULL){
    return LISTAVAZIA;
  }
  else{
    P=*L;
    maior=P->info;
    do{
      if( P->info > maior){
        maior=P->info;
      }
      P=P->next;
    }while(P!=*L);
  }
  return maior;
}

int encontraMenor(no **L){
  int menor;
  no *P;
  if (*L==NULL){
    return LISTAVAZIA;
  }
  else{
    P=*L;
    menor=P->info;
    do{
      if( P->info < menor){
        menor=P->info;
      }
      P=P->next;
    }while(P!=*L);
  }
  return menor;
}

int removeItemX(no **L, int x){
  no *P,*PROX, *ANTE;
  if(*L==NULL){
    return LISTAVAZIA;
  }
  else{ // tem itens na lista
    P=*L;
    if(P->info==x){ // eh o primeiro
      if((*L)->next=*L){ //so tem um elemento
        *L=NULL;
        free(P);
      }
      else{
      PROX=P->next;
      ANTE=P->prev;
      PROX->prev=ANTE; //segundo elemento aponta para o ultimo
      ANTE->next=PROX;
      *L=PROX;
      free(P);
      }
      return 0; //item removido
    }
    else{ // nao eh o primeiro
      do{ //percorre
        P=P->next;
      }while((P!=*L)&&(P->info!=x));
      if(P->info==x){ // achou ou esta no meio ou no fim
          if(P==(*L)->prev){//achou na ultima posicao
            ANTE=P->prev;
            ANTE->next=*L;
            (*L)->prev=ANTE;
            free(P);
          }
          else{
            PROX=P->next;
            ANTE=P->prev;
            PROX->prev=ANTE;
            ANTE->next=PROX;
            free(P);
          }
          return 0; // item retirado
      }
      else{ // saiu do while pq voltou ao inicio
        return ITEMNAOENCONTRADO;
      }
    }
  }
}


int insereListaOrdenada(no **L,int x){
  no *N,*P,*AUX;
  if((N = (no *) malloc(sizeof(no))) == NULL){
    return MEMORIAINSUFICIENTE;
  }
  N->info=x;
  if(*L==NULL){ // se a lista estiver vazia
    *L=N;
    (*L)->next=N;
    (*L)->prev=N;
  }
  else{// tem elementos
    P=*L;
    if(P->info>x){ // eh menor que todos
      AUX=P->prev;//ultimo
      N->next=P;
      N->prev=P->prev;
      P->prev=N;
      AUX->next=N;
      *L=N;
    }
    else{
      do{
        P=P->next;
      }while((P!=*L)&&(P->info<x));
      if(P==*L){ //se for maior que todos
        P=P->prev; //volta para o último
        N->next=*L;
        N->prev=P;
        (*L)->prev=N;
        P->next=N;
      }
      else{ // esta no meio
        AUX=P->prev;
        N->prev=AUX;
        N->next=P;
        AUX->next=N;
        P->prev=N;
      }
    }
  }
  return 0; //item inserido
}
