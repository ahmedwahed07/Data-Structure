#define List_Linked
typedef int ListEntry;
#ifdef List_Linked
typedef struct listnode
{
    ListEntry Entry;
    struct listnode *next;
}ListNode;

typedef struct ListEntry
{
 ListNode *head;
 int size1;
}List;
#else
#define MAXSIZE 100

typedef int ListEntry;
typedef struct list1{
    ListEntry entry[MAXSIZE];
    int size1;
}List;

#endif // List_Linked

void CreateList(List *Pl);
int ListEmpty(List *pl);
int ListFull(List *pl);
int ListSize(List *pl);
void DestoryList(List *pl);
void TraverseList(List *pl,void (*visit)(ListEntry));
void InsertList(int pos,ListEntry e,List *pl);
void DeleteList(int pos,ListEntry *e,List *pl);
void RetrieveList(int pos,ListEntry *e,List *pl);
void ReplaceList(int pos,ListEntry e,List *pl);
