void main(){
  no *L;
  int x,sel;
  initialize(&L);
  for(;;){
    printf("\n--MENU--\n");
    printf("\n1. INSERT AT THE END\n2. REMOVE FROM THE END\n3. SHOW LIST\n4. INSERT AT THE BEGINNING\n5. REMOVE FROM THE BEGINNING\n6. INSERT IN ORDER\n7. REMOVE ESPECIFIC ITEM \n8. FIND THE BIGGER ITEM\n9. FIND THE SMALLEST ITEM\n10. SHOW LIST IN REVERSE ORDER\n11.EXITE\n");
    printf("\nSELECT AN OPTION: \n");
    scanf("%d",&sel);
    system("cls");
    switch(sel){
      case 1: printf("\nINPUT: ");
      scanf("%d",&x);
      if((insertAtTheEnd(&L,x)) == -2){
        printf("\nINSUFFICIENT MEMORY");
      }
      else{
        printf("\nSUCCESS\n");
      }
      break;

      case 2: x=removeFromTheEnd(&L);
      if(x==-1){
        printf("\nEMPTY LIST");
      }
      else{
        printf("\nDELETED: %d\n",x);
      }
      break;

      case 3: printf("\n---LIST---\n"); goThroughList(&L); break;

      case 4: printf("\nINPUT: ");
      scanf("%d",&x);
      if((insertAtTheBeginning(&L,x)) == -2){
        printf("\nINSUFFICIENT MEMORY");
      }
      else{
        printf("\nSUCCESS\n");
      }
      break;

      case 5: x=removeFromTheBeginning(&L);
      if(x==-1){
        printf("\nEMPTY LIST");
      }
      else{
        printf("\nDELETED: %d \n",x);
      }
      break;

      case 6: printf("\nINPUT: ");
      scanf("%d",&x);
      if((insertInOrder(&L,x)==-2)){
        printf("\nINSUFFICIENT MEMORY");
      }
      else{
        printf("\nSUCCESS");
      }
      break;

      case 7: printf("\nINPUT: ");
      scanf("%d",&x);
      int aux;
      aux = removeItemX(&L,x);
      if(aux ==-3){
        printf("\nITEM NOT FOUND");
      }
      else if(aux==-1){
        printf("EMPTY LIST");
      }
      else{
        printf("\nDELETED: %d ",x);
      }
      break;

      case 8: printf("\nBIGGER ITEM: %d",findBigger(&L)); break;

      case 9: printf("\nSMALLEST ITEM: %d",findSmallest(&L)); break;

      case 10: printf("\n-- INVERSE LIST --\n"); showInverse(&L); break;

      case 11: exit(1); break;
    }
  }
}