#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{

Stack s;
int e;
CreateStack(&s);
Push(5,&s);
Push(8,&s);
Push(3,&s);
Pop(&e,&s);
Pop(&e,&s);
printf("%d",e);


    return 0;
}
