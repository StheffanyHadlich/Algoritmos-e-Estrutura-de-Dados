#define MAXSIZE 5
#define ERRORFULLQUEUE -1
#define ERROREMPTYQUEUE -2

typedef struct{
  int item[MAXSIZE];
  int first;
  int last;
  int count;
} Queue;

void initialize(Queue *q);
int emptyQueue(Queue *q);
int fullQueue(Queue *q);
int insert(Queue *q, int x);
int remove(Queue *q);
int show(Queue *q);
