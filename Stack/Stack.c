
#include "stack.h"
#include"stdlib.h"

#ifdef LINKED_STACK
void CreateStack(Stack * ps)
{
    ps->top=NULL;
    ps->size1=0;
}
void Push(StackEntry e,Stack * ps)
{
    StackNode *pn=(StackNode *)malloc(sizeof(StackNode));
    pn->next=ps->top;
    ps->top=pn;
    pn->entry=e;
    ps->size1++;
}
int StackFull(Stack * ps)
{
    return 0;
}
void Pop(StackEntry *pe,Stack * ps)
{
     StackNode *pn=ps->top;
     ps->top=pn->next;
     *pe=pn->entry;
      ps->size1--;
     free(pn);
}
int StackEmpty(Stack * ps)
{
    return ps->top==NULL;
}

void StackTop(StackEntry *pe,Stack * ps)
{
    *pe=ps->top->entry;
}

int StackSize(Stack * ps)
{
    return ps->size1;
}
void ClearStack(Stack * ps)
{
    StackNode *pn1=ps->top;
    StackNode *pn2=ps->top;
    while(pn2)
    {
        pn2=pn1->next;
        free(pn1);
        pn1=pn2;
    }
    ps->top=NULL;
    ps->size1=0;
}
void TraverseStack(Stack * ps,void(*pf)(StackEntry))
{
    StackNode *pn=ps->top;
    while(pn)
    {
        (*pf)(pn->entry);
        pn=pn->next;
    }
}

#else
void CreateStack(Stack * ps)
{
    ps->top=0;
}

void Push(StackEntry e,Stack * ps)
{
    ps->entry[ps->top++]=e;
}

int StackFull(Stack * ps)
{
    return ps->top>=MAXSIZE;
}

void Pop(StackEntry *pe,Stack * ps)
{
    *pe=ps->entry[--ps->top];
}

int StackEmpty(Stack * ps)
{
    return !ps->top;
}

void StackTop(StackEntry *pe,Stack * ps)
{
    *pe=ps->entry[ps->top];
}

int StackSize(Stack * ps)
{
    return ps->top;
}

void ClearStack(Stack * ps)
{
    ps->top=0;
}
void TraverseStack(Stack * ps,void(*pf)(StackEntry ))
{
    int i;
    for(i=ps->top;i>0;i--)
    {
        (*pf)(ps->entry[i-1]);
    }
}


#endif
