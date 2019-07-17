#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main()
{
    Queue q;
    QueueEntry e;
    CreateQueue(&q);
    if(!QueueFULL(&q))
    {
     Append(5,&q);
    }


   if(!QueueFULL(&q))
    {
     Append(3,&q);
    }
  if(!QueueFULL(&q))
    {
     Append(7,&q);
    }
    //ClearQueue(&q);
printf("%d\n",QueueSize(&q));
   if(!QueueEmpty(&q))
   {
       Serve(&e,&q);
       printf("%d ",e);
   }


   if(!QueueEmpty(&q))
   {
       Serve(&e,&q);
       printf("%d ",e);
   }
   if(!QueueEmpty(&q))
   {
       Serve(&e,&q);
       printf("%d ",e);
   }


    return 0;
}
