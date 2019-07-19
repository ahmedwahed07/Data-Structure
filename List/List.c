#include "List.h"
#include<stdlib.h>

#ifdef List_Linked

void CreateList(List *pl)
{
    pl->head=NULL;
    pl->size1=0;
}
int ListEmpty(List *pl)
{
    return (pl->size1==0);
}
int ListFull(List *pl)
{
    return 0;
}

int ListSize(List *pl)
{
    return pl->size1;
}

void DestoryList(List *pl)
{
    ListNode *q;
    while(pl->head)
    {
        q=pl->head->next;
        //q=pl->head->next;
        free(pl->head);
        pl->head=q;
    }
    pl->size1=0;
}
void TraverseList(List *pl,void (*visit)(ListEntry))
{
     ListNode *p=pl->head;
     while(p)
     {
      (*visit)(p->Entry);
      p=p->next;
     }
}

void InsertList(int pos,ListEntry e,List *pl)
{
    int i;
    ListNode *n=(ListNode*)malloc(sizeof(ListNode));
    ListNode *p=pl->head;
    n->Entry=e;
    n->next=NULL;
    if(pos==0)
    {
        n->next=pl->head;
        pl->head=n;
    }
    else
    {
    for(i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    n->next=p->next;
    p->next=n;
    }
    pl->size1++;
}

void DeleteList(int pos, ListEntry *e,List *pl)
{
    ListNode *p=pl->head;
    ListNode *m;
    int i;
    if(pos==0)
    {
        *e=pl->head->Entry;
        pl->head=pl->head->next;;
        free(p);
    }
    else
    {
        p=pl->head;
    for(i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    m=p->next;
    *e=m->Entry;
    p->next=m->next;
    free(m);
    }
    pl->size1--;
}
void RetrieveList(int pos,ListEntry *e,List *pl)
{
    int i;
    ListNode *p=pl->head;
    for(i=0;i<pos;i++)
    {
        p=p->next;
    }
    *e=p->Entry;
}

void ReplaceList(int pos,ListEntry e,List *pl)
{
    int i;
    ListNode *p=pl->head;
    for(i=0;i<pos;i++)
    {
        p=p->next;
    }
    p->Entry=e;
}

#else
void CreateList(List *pl)
{
    pl->size1=0;
}

int ListEmpty(List *pl)
{
return !pl->size1;
}

int ListFull(List *pl)
{
return pl->size1==MAXSIZE;
}
int ListSize(List *pl)
{
return pl->size1;
}

void InsertList(int p, ListEntry e, List *pl)
{

int i;
for(i=pl->size1-1;i>=p;i--)
{
    pl->entry[i+1]=pl->entry[i];
}
pl->entry[p]=e;
pl->size1++;

}
void DeleteList(int p,ListEntry *e,List *pl)
{
    int i;
    *e=pl->entry[p];
    for(i=p+1;i<=pl->size1-1;i++)
    {
        pl->entry[i-1]=pl->entry[i];
    }
    pl->size1--;
}

void DestroyList(List *pl)
{
    pl->size1=0;
}
void RetrieveList(int p,ListEntry *e,List *pl)
{
    *e=pl->entry[p];
}

void ReplaceList(int p, ListEntry e, List *pl)
{
    pl->entry[p]=e;
}

#endif // List_Linked
