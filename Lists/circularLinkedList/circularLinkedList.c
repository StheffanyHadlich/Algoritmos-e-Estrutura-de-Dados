#include <stdio.h>
#include <stdlib.h>
#define LISTAVAZIA -1
#define MEMORIAINSUFICIENTE -2
#define  ITEMNAOENCONTRADO -3

typedef struct NoTag {
  int info;
  struct NoTag *link;
} no;

void inicializaLLC(no **L);
int insereInicioLLC(no **L,int x );
int removeInicioLLC (no **L);
int insereFinalLLC(no **L, int x);
int verificaItemX(no **L, int x);
int contItens (no **L);
int encontraMaior(no **L);
int encontraMenor(no **L);
int insereFilaDePrioridades (no **L, int x);
void exibeLLC(no **L);
void exibeInversoLLC(no **L);
int removeItemX(no **L, int x);


void main(){
  no *L;
  int x,y,sel;
  inicializaLLC(&L);
  for(;;){
    printf("\n--Menu--\n\n1. Insere item no inicio\n2. Remove item no inicio\n3. Insere no Final\n4. Verificar existencia de um numero\n5. Quantidade de itens\n6. Encontrar maior\n7. Insere por prioridade\n8. Mostrar lista\n9. Sair\n10. Remove Final\n11. Encontra menor\n12. Imprimir invero\n13. Remove itemX\n");
    scanf("%d",&sel);
    system("cls");
    switch(sel){
      case 1: printf("\nEntre com o numero que deseja inserir no inicio: ");
      scanf("%d",&x);
      if((insereInicioLLC(&L,x))== MEMORIAINSUFICIENTE){
        printf("\nMemoria insuficiente");
      }
      else{
        printf("\nItem inserido com sucesso");
      }
      break;
      case 2: x= removeInicioLLC(&L);
      if ( x == LISTAVAZIA){
        printf("\nLista vazia");
      }
      else{
        printf("\nO item %d foi removido",x);
      }
      break;
      case 3: printf("\nEntre com o numero que deseja inserir no final: ");
      scanf("%d",&x);
      if((insereFinalLLC(&L,x))==MEMORIAINSUFICIENTE){
        printf("\nMemoria insuficiente");
      }
      else{
        printf("\nO item %d foi inserido com sucesso",x);
      }
      break;
      case 4: printf("\nEntre com o numero que deseja verificar: ");
      scanf("%d",&x);
      y=verificaItemX(&L,x);
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
      case 5: x=contItens(&L);
      printf("\nA lista contem %d elemento(s)",x); break;
      case 6: x = encontraMaior(&L);
      printf("\nO maior item da lista eh o %d",x); break;
      case 7: printf("\nEntre com o item que deseja inserir: ");
      scanf("%d",&x);
      if((insereFilaDePrioridades(&L,x))==MEMORIAINSUFICIENTE){
        printf("\nMemoria insuficiente");
      }
      else{
        printf("O item %d foi inserido com sucesso",x);
      }
      break;
      case 8: printf("\nLista: ");
      exibeLLC(&L);
      break;
      case 9: exit(1); break;
      case 10: x = removeFinalLLC(&L);
      if(x==LISTAVAZIA){
        printf("\nLista vazia");
      }
      else{
        printf("\nO item %d foi excluido",x);
      }
      break;
      case 11: x = encontraMenor(&L);
      printf("\nO menor item da lista eh o %d",x); break;
      case 12: printf("\nLista inversa: ");
      exibeInversoLLC(&L); break;
      case 13: printf("\nEntre com o item que deseja excluir: ");
      scanf("%d",&y);
      x= removeItemX(&L,y);
      if ( x == LISTAVAZIA){
        printf("\nLista vazia");
      }
      else{
        printf("\nO item %d foi removido",y);
      }
      break;
    }
  }
}

void inicializaLLC(no **L){
  *L = NULL;
}

void exibeLLC(no **L){
  no *P;
  if(*L!=NULL){
      P=(*L)->link; // primeiro elemento
      do{ // percorre (circular percorre com do)
      printf("%d ",P->info);
      P=P->link;
    } while(P != (*L)->link); // até passar o último elemento e voltar para o primeiro
  }
}

void exibeInversoLLC(no **L){
  no *P, *AUX;
  int x;
  inicializaLLC(&AUX); // utiliza uma auxiliar nas listas que nao tem um prev
  if(*L!=NULL){
      P=(*L)->link;
      do{
      x=P->info;
      insereInicioLLC(&AUX,x); // insere na auxiliar na ordem inversa
      P=P->link;
      } while(P != (*L)->link);
      P=AUX->link;
      do{ // depois de passar a lista inversa para outra imprime a auxiliar
      printf("%d ",P->info);
      P=P->link;
    }while(AUX != P->link);
  }
}

int insereInicioLLC(no **L,int x ){
  no *N;
  if((N = (no *) malloc(sizeof(no))) == NULL){
    return MEMORIAINSUFICIENTE;
  }
  N->info=x;
  if(*L==NULL){ //se a lista estiver vazia
    *L=N;
    (*L)->link=N;
  }
  else{ //se houver pelo menos um elemento
    N->link = (*L)->link;// N se liga a lista apontado para o primeiro elemento
    (*L)->link=N; // o ultimo elemento agora aponta para o N que eh considerado primeiro elemento
  }
  return 0; // item inserido com sucesso
}

int removeInicioLLC (no **L){
  no *AUX;
  int x;
  if(*L==NULL){
    return LISTAVAZIA;
  }
  else{
    AUX=(*L)->link; // recebe o inicio
    (*L)->link=AUX->link; // o ultimo no aponta para o 2 nó
    x=AUX->info; // guarda o valor excluido
    free(AUX);
    return x;
  }
}

int insereFinalLLC(no **L, int x){
  no *N;
  no *AUX;
  if((N = (no *) malloc(sizeof(no))) == NULL){
    return MEMORIAINSUFICIENTE;
  }
  N->info=x;
  if(*L==NULL){
    *L=N;
    (*L)->link=N;
  }
  else{
    N->link=(*L)->link; // o link de N recebe o primeiro no
    (*L)->link=N; //o link do penultimo aponta para N
    *L=N; // *L aponta para o ultimo que agora eh N
  }
  return 0;
}

int removeFinalLLC(no **L){
  no *P, *ANT;
  int x;
  if (*L == NULL){
    return LISTAVAZIA;
  }
  else{
    if ((*L)->link == *L){ // so ha um elemento
      x= (*L)->info;
      free(L);
      *L=NULL;
      return x;
    }
    else{ // tem mais elementos
      P= *L;
      ANT=(*L)->link;
      while (ANT->link != P){
        ANT= ANT->link;
      }
      ANT->link=P->link;
      x=P->info;
      *L=ANT;
      free(P);
      return x;
    }
  }
}

/*3. Desenvolver uma função que verifique se determinado item existe ou não
em uma LLC. O algoritmo deve receber a lista e o valor a ser encontrado
como parâmetros.
*/
int verificaItemX(no **L, int x){
  no *P;
  if(*L == NULL){
    return LISTAVAZIA;
  }
  else{ // ha itens na lista
    P = (*L)->link;
    do{
      if(P->info == x){
        return 1; // o elemento esta na lista
      }
      P = P->link;
    } while(P != (*L)->link);
    return ITEMNAOENCONTRADO; // o elmento nao esta na lista
  }
}

/* 4. Desenvolver uma função que retorne o número de elementos de uma LLC. */
int contItens (no **L){
  no *P;
  int cont = 0;
  if(*L==NULL){
    return LISTAVAZIA;
  }
  else{
    P=(*L)->link;
    do{
      cont++;
      P=P->link;
    } while(P != (*L)->link);
  }
  return cont;
}

/* . Desenvolver uma função que retorne o maior valor armazenado de uma
LLC. */

int encontraMaior(no **L){
  no *P;
  int maior;
  if(*L==NULL){
    return LISTAVAZIA;
  }
  else{
    P=(*L)->link;
    maior=P->info;
    do{
      if(P->info>maior){
        maior = P->info;
      }
      P=P->link;
    }while(P != (*L)->link);
  }
  return maior;
}

int encontraMenor(no **L){
  no *P;
  int menor;
  if(*L==NULL){
    return LISTAVAZIA;
  }
  else{
    P = (*L)->link;
    menor = P->info;
    do{
      if(P->info<menor){
        menor = P->info;
      }
      P=P->link;
    }while(P != *L);
  }
  return menor;
}

 int insereFilaDePrioridades (no **L, int x){
   no *P, *ANT, *N;
   if((N = (no *) malloc(sizeof(no))) == NULL){
     return MEMORIAINSUFICIENTE;
   }
   N->info=x;
   if(*L==NULL){// se nao tiver elementos na lista nao precisa ver prioridade
     *L=N;
     (*L)->link = *L;
   }
   else{ // se houver elementos eh preciso analisar
     P=(*L)->link; // P receve o primeiro no
     if(N->info <= P->info){ // se x for menor que todos insere no inicio
       N->link = P; // o link de N vai apontar para o inicio
      (*L)->link=N; // O ultimo vai apontar para o N(q agora eh o inicio)
     }
     else{ // nao eh o menor
       do{ // procura a posicao
         ANT=P; // ante rece o primeiro
         P=P->link; // P recebe o 2º elemento
       } while((P != (*L)->link) && (N->info >= P->info));
       if(P == (*L)->link){ // eh maior que todos
         N->link = ANT->link; // o link de N aponta para o primeiro (pq ANT aponta para o ultimo)
         ANT->link = N; // ante eh o penultimo e aponta para o N(ultimo)
         *L=N; // L aponta pra N (ultimo)
       }
       else{ // ta no meio
         ANT->link = N; // o anterior recebe o N
         N->link = P; // O N recebe o P(proximo)
       }
     }
   }
   return 0; //item inserido
}

int removeItemX(no **L, int x){// verificar se existe so um no antes
  no *P, *AUX;
  if(*L==NULL){ // nao tem elementos
    return LISTAVAZIA;
  }
  else{// existe elementos
    P=(*L)->link;
    if(x==P->info){ // eh o primeiro elemento
      if(*L==(*L)->link){
        *L=NULL;
      }
      AUX=P->link; //o segundo elemento
      free(P); // libera o primeiro elemento
      (*L)->link=AUX;
      return 0;
    }
    else{ // nao eh o primeiro
      do{
        AUX=P;
        P=P->link;
      }while((x!=P->info)&& (P!=(*L)->link));
      if(x==P->info){ // encontrou
        if(P==*L){ // achou na ultima posicao
          AUX->link=(*L)->link;
          *L=AUX;
          free(P);
        }
        else{
          AUX->link=P->link;
          free(P);
        }
        return 0;
      }
      else{// nao encontrou
        return ITEMNAOENCONTRADO;
      }
    }
  }
}
