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

void inicializaLDL(no **L);
void percorreLDL(no **L);
int insereFinalLDL(no **L, int x);
int removeFinalLDL(no **L);
int insereInicioLDL (no **L, int x);
int removeInicioLDL (no **L);
int verificaItem(no **L, int x);
int removeItemX(no**L, int x);
void exibeInversa (no **L);
int contElementos(no **L);
int InsereListaOrdenada(no **L, int x);
int encontraMenor(no **L);
int encontraMaior(no **L);

void main(){
  no *L;
  int x,y,sel;
  inicializaLDL(&L);
  for(;;){
    printf("\n\n--Menu--\n\n1. Insere item no final\n2. Remove item do final\n3. Exibe lista\n4. Insere item no inicio\n5. Remove item no inicio\n6. Verifica Item\n7. Remove item X\n8. Exibe lista inversa\n9. Conta elementos\n10. Sair\n11. encontra Maior\n12. encontra Menor\n13. Insere Lista Ordenada\n");
    scanf("%d",&sel);
    system("cls");
    switch(sel){
      case 1: printf("\nEntre com o valor a ser inserido: ");
      scanf("%d",&x);
      if((insereFinalLDL(&L,x)) == -2){
        printf("\nMemoria insuficiente. Nao foi possivel inserir o no.");
      }
      else{
        printf("\nItem inserido com sucesso\n");
      }
      break;
      case 2: x=removeFinalLDL(&L);
      if(x==-1){
        printf("\nLista Vazia");
      }
      else{
        printf("\nO item %d foi removido\n",x);
      }
      break;
      case 3: printf("\n---Lista---\n");
      percorreLDL(&L);
      break;
      case 4: printf("\nEntre com o valor que deseja inserir no incio da fila: ");
      scanf("%d",&x);
      if((insereInicioLDL(&L,x)) == -2){
        printf("\nMemoria insuficiente. Nao foi possivel inserir o no.");
      }
      else{
        printf("\nItem inserido com sucesso\n");
      }
      break;
      case 5: x=removeInicioLDL(&L);
      if(x==-1){
        printf("\nLista Vazia");
      }
      else{
        printf("\nO item %d foi removido\n",x);
      }
      break;
      case 6: printf("\nEntre com o numero que deseja porcurar: ");
      scanf("%d",&x);
      y = verificaItem(&L,x);
      if(y== LISTAVAZIA){
        printf("\nA lista esta vazia");
      }
      else if(y== ITEMNAOENCONTRADO){
        printf("\nO elemento %d nao esta na lista",x);
      }
      else{
        printf("\nO elemento %d esta na lista",x);
      }
      break;
      case 7: printf("\nEntre com o item que deseja excluir ");
      scanf("%d",&x);
      y = removeItemX(&L,x);
      if(x==LISTAVAZIA){
        printf("\nA lista esta vazia");
      }
      else if(y==ITEMNAOENCONTRADO){
        printf("\nItem nao encontrado");
      }
      else{
        printf("\nO item %d foi removido com sucesso",x);
      }
      break;
      case 8: printf("\n---Lista ao Contrario---\n");
      exibeInversa(&L); break;
      case 9: y = contElementos(&L);
      if(y==LISTAVAZIA){
        printf("\nLista vazia");
      }
      else{
        printf("\nA lista contem %d elementos",y);
      }
      break;
      case 10: exit(1); break;
      case 11: printf("\nO maior item eh %d",encontraMaior(&L)); break;
      case 12: printf("\nO menor item eh %d",encontraMenor(&L)); break;
      case 13: printf("\nEntre com o valor que deseja inserir: ");
      scanf("%d",&x);
      if((InsereListaOrdenada(&L,x))==MEMORIAINSUFICIENTE){
        printf("\nMemoria insuficiente");
      }
      else{
          printf("\nO item %d foi inserido com sucesso",x);
      }
      break;
    }
  }
}

void inicializaLDL(no **L){
  *L = NULL;
}

void percorreLDL(no **L){
  no *P;
  P = *L;
  while(P != NULL){ // percorre todos os nós da Lista, nao para no último
    printf(" %d",P->info);
    P = P->next;
  }
}

int insereFinalLDL(no **L, int x){
  no *N, *P;
  if((N = (no *) malloc(sizeof(no))) == NULL){
    return MEMORIAINSUFICIENTE;
  }
  else{
    N->info=x;
    N->next=NULL;
  }
  if (*L == NULL){
    *L = N;
    N->prev=NULL;
  }
  else{
    P = *L;
    while(P->next != NULL){ // para no último nó
      P = P->next;
    }
    N->prev=P;
    P->next=N;
  }
  return 0;
}

int removeFinalLDL(no **L){
  no *P, *ANT;
  int x;
  if (*L == NULL){ // se a lista estiver vazia
    return LISTAVAZIA;
  }
  else{
    if ((*L)->next == NULL){ //só tem um elemento na lista
      x= (*L)->info;
      free(*L);
      *L=NULL;
      return x;
    }
    else{ //se tiver mais elementos
      P= (*L)->next;
      while (P->next != NULL){ //para no ultimo no
        P=P->next;
      }
      ANT=P->prev;
      ANT->next=NULL;
      x=P->info;
      free(P);
      return x;
    }
  }
}

int insereInicioLDL (no **L, int x){
  no *N;
  if((N = (no *) malloc(sizeof(no))) == NULL){
    return MEMORIAINSUFICIENTE;
  }
  N->info=x;
  N->prev=NULL;
  N->next=*L;
  if(*L!=NULL){
     ((*L)->prev = N);
  }
  *L=N;
  return 0;
}

int removeInicioLDL (no **L){
  no *P;
  P=*L;
  int x;
  if(*L != NULL){
    *L = P->next;
    if (*L!=NULL){
      (*L)->prev=NULL;
    }
    x=P->info;
    free(P);
    return x;
  }
  else{
    return LISTAVAZIA;
  }
}

/*3. Desenvolver um algoritmo que verifica se determinado item existe ou não
em uma LDL. O algoritmo deve receber a lista e o valor a ser encontrado
como parâmetros.
*/

int verificaItem(no **L, int x){
  no *P;
  P = *L;
  if(*L == NULL){
    return LISTAVAZIA;
  }
  else{ // ha itens na lista
    while(P != NULL){ // percorre todos os nós da Lista, nao para no último
      if(P->info == x){
        return 1; // o elemento esta na lista
      }
      P = P->next;
    }
    return ITEMNAOENCONTRADO; // o elmento nao esta na lista
  }
}

/*4. Desenvolver um algoritmo que remova determinado item de uma LDL. O
algoritmo deve receber a lista e o valor a ser removido como parâmetros. */

int removeItemX(no **L, int x){
    no *P, *ANT;
    if (*L != NULL){
      P=*L;
      while((P!=NULL)&&(x != P->info)){ // passa por todos os nós verificando se
        P=P->next;
      }
      if(P==NULL){ // percorre tudo e o item nao eh encontrado
        return ITEMNAOENCONTRADO;
      }
      else{
        if(P==*L){ // eh o primeiro item
          *L=(*L)->next; // L = próximo item ou NULL
          if(*L!=NULL){
            (*L)->prev=NULL;
          }
          free(P); // libera o no
          return 0; // no excluido
        }
        else{ // encontrado mas nao eh  o primeiro
          ANT=P->prev; // ANT recebe o endereco do no antes de P
          ANT->next=P->next; // ANT next recebe o next de P
          free(P); // libera o P
          return 0; //no excluido
        }
      }
    }
    return LISTAVAZIA;
}


/*Desenvolver um algoritmo que imprima uma LDL na ordem inversa (do
último para o primeiro elemento). O algoritmo deve receber a lista como
parâmetro. */

void exibeInversa (no **L){
  no *P;
  P = *L;
  while(P->next != NULL){ //vai ate o ultimo no
    P = P->next;
  }
  while (P != NULL){ //volta imprimindo
    printf(" %d",P->info);
    P = P->prev;
  }
}

/*. Desenvolver um algoritmo que retorne o número de elementos de uma LDL. */

int contElementos(no **L){
  int cont=0;
  no *P;
  P = *L;
  if (*L == NULL){
    return LISTAVAZIA;
  }
  else{
    while(P->next != NULL){ //
      cont ++;
      P = P->next;
    }
    return cont;
  }
}

int encontraMaior(no **L){
  no *P;
  int maior=0;
  if(*L==NULL){
    return LISTAVAZIA;
  }
  else{
    P=*L;
    while(P!=NULL){
      if(P->info>maior){
        maior=P->info;
      }
      P=P->next;
    }
    return maior;
  }
}

int encontraMenor(no **L){
  no *P;
  int menor;
  if(*L==NULL){
    return LISTAVAZIA;
  }
  else{
    P=*L;
    menor=P->info;
    while(P!=NULL){
      if(P->info<menor){
        menor=P->info;
      }
      P=P->next;
    }
    return menor;
  }
}

int InsereListaOrdenada(no **L, int x){
  no *N, *P, *AUX;
  if((N = (no *) malloc(sizeof(no))) == NULL){
    return MEMORIAINSUFICIENTE;
  }
  else{
    N->info=x;
    if(*L==NULL){ // lista vazia
      *L=N;
      (*L)->next=NULL;
      (*L)->prev=NULL;
    }
    else{
      P=*L;
      while((P->info<x)&&(P!=NULL));{
        P=P->next;
      }
      if(P==*L){//eh menor que primeiro
        N->prev=NULL;
        N->next=P;
        P->prev=N;
        *L=N;
      }
      else if(P==NULL){ // eh maior que todos
        P->next=N;
        N->prev=P;
        N->next=NULL;
        (*L)->prev=N;
      }
      else{// se tiver no meio
        AUX=P->prev;
        AUX->next=N;
        N->prev=AUX;
        N->next=P;
        P->prev=N;
      }
     }
     return 0;
  }
}
