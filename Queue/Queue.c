#include "Queue.h"
#include "stdlib.h"

#ifdef LINKED_QUEUE
void CreateQueue(Queue *pq)
        {
            pq->front1=NULL;
            pq->rear1=NULL;
            pq->size1=0;

        }
        void Append(QueueEntry e,Queue *pq)
        {
          QueueNode *pn=(QueueNode *)malloc(sizeof(QueueNode));
          pn->next=NULL;
          pn->entry=e;
        if(pq->size1==0)
            {
            pq->front1=pn;
            }
        else
            {
                pq->rear1->next=pn;
            }
          pq->rear1=pn;
          pq->size1++;
        }
        void Serve(QueueEntry *pe,Queue *pq)
        {
           QueueNode *pn=pq->front1;
           *pe=pn->entry;
           pq->front1=pq->front1->next;
           free(pn);
           if(!pq->front1)
           {
               pq->rear1=NULL;
           }
           pq->size1--;
    }

        int QueueEmpty(Queue *pq)
        {
            return !pq->size1;
        }

        int QueueFULL(Queue *pq)
        {
            return 0;
        }

        int QueueSize(Queue *pq)
        {
            return pq->size1;
        }

        void ClearQueue(Queue *pq)
        {
            while(pq->front1)
            {
                pq->rear1=pq->front1->next;
                free(pq->front1);
                pq->front1=pq->rear1;
            }
            pq->size1=0;
        }
      void TraverseQueue(Queue *pq,void (*pf)(QueueEntry))
      {
          QueueNode *pn;
          for(pn=pq->front1;pq !=NULL;pn=pn->next)
          {
           (*pf)(pn->entry);
          }

      }

#else
void CreateQueue(Queue *pq)
{
    pq->front1=0;
    pq->rear1=-1;
    pq->size1=0;
}

void Append(QueueEntry e,Queue *pq)
{
    pq->rear1=(pq->rear1+1)%MAXSIZE;
    pq->entry[pq->rear1]=e;
    pq->size1++;
}

void Serve(QueueEntry *pe,Queue *pq)
{
    *pe=pq->entry[pq->front1];
    pq->front1= (pq->front1+1)%MAXSIZE;
    pq->size1--;
}

int QueueEmpty(Queue *pq)
{
    return !pq->size1;
}

int QueueFULL(Queue *pq)
{
    return pq->size1==MAXSIZE;
}

int QueueSize(Queue *pq)
{
    return pq->size1;
}

void ClearQueue(Queue *pq)
{
    pq->front1=0;
    pq->rear1=-1;
    pq->size1=0;

}

void TraverseQueue(Queue *pq,void (*pf)(QueueEntry  ))
{
    int pos=pq->front1;
    int s;
    for(s=0;s<pq->size1;s++)
    {
        (*pf)(pq->entry[pos]);
         pos=(pos+1)%MAXSIZE;

    }
}
#endif
