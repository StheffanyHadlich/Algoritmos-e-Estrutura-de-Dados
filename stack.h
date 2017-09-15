#define FULLSTACKERROR -1
#define EMPTYSTACK -2
#define MAX 5

typedef struct{
  int item[MAX];
  int top;
} Stack;

void initializeStack(Stack *s);
int emptyStack(Stack *s);
int fullStack(Stack *s);
int push(Stack *s, int x);
int pop(Stack *s);
void show (Stack *p);



