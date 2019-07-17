#define LINKED_QUEUE

typedef int QueueEntry;
#ifdef LINKED_QUEUE
typedef int QueueEntry;

typedef struct queueNode{
struct queueNode *next;
QueueEntry entry;
}QueueNode;

typedef struct queue1{

QueueNode *front1;
QueueNode *rear1;
int size1;
}Queue;

#else
#define MAXSIZE 100
typedef struct queue1{
int front1;
int rear1;
int size1;
QueueEntry entry[MAXSIZE];
}Queue;
#endif // LINKED_STACK
void CreateQueue(Queue *pq);
void Append(QueueEntry e,Queue *pq);
void Serve(QueueEntry *pe,Queue *pq);
int QueueEmpty(Queue *pq);
int QueueFULL(Queue *pq);
int QueueSize(Queue *pq);
void ClearQueue(Queue *pq);
void TraverseQueue(Queue *pq,void (*pf)(QueueEntry e ));
