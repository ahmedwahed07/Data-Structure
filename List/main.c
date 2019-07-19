#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main()
{
    List l;
    ListEntry e;
    CreateList(&l);
    if(!ListFull(&l)&&(0<=l.size1))
    {
        InsertList(0,5,&l);
    }
    if(!ListFull(&l)&&(1<=l.size1))
    {
        InsertList(1,3,&l);
    }
    if(!ListFull(&l)&&(2<=l.size1))
    {
        InsertList(2,8,&l);
    }
    if(!ListFull(&l)&&(0<=l.size1))
    {
        InsertList(0,9,&l);
    }
    if(!ListEmpty(&l)&&(1<l.size1))
    {
    DeleteList(1,&e,&l);
    printf("%d ",e);
    }
    if(!ListEmpty(&l)&&(1<l.size1))
     {
        DeleteList(1,&e,&l);
        printf("%d ",e);
     }
    if(!ListEmpty(&l)&&(1<l.size1))
     {
        DeleteList(1,&e,&l);
        printf("%d",e);
}
    return 0;
}
