/*Select LINKED or ARRAY Stack  */
#define LINKED_STACK
/*Select data type */
typedef int StackEntry ;
/*Select array size in array based stack*/
#define MAXSIZE 100

#ifdef LINKED_STACK
/*Linked Stack */
typedef struct stacknode{
 StackEntry entry;
 struct stacknode *next;
}StackNode;


typedef struct stack1{
StackNode *top;
int size1;
}Stack;

/*Array stack */
#else
typedef struct stack1{
int top;
StackEntry entry[MAXSIZE];
}Stack;
#endif // LINKED_STACK

void CreateStack(Stack * ps);
void Push(StackEntry e,Stack * ps);
int StackFull(Stack * ps);
void Pop(StackEntry *pe,Stack * ps);
int StackEmpty(Stack * ps);
void StackTop(StackEntry *pe,Stack * ps);
int StackSize(Stack * ps);
void ClearStack(Stack * ps);
void TraverseStack(Stack * ps,void(*pf)(StackEntry));
