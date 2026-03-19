// Doubly Circular linked LIST

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev ;

};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


void InsertFirst(PPNODE first,PPNODE last,int no)
{
 
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no ;
    newn ->next = NULL;
    newn -> prev = NULL;

    if((*first)== NULL &&(*last== NULL)) //LL containn at least one node
    {

        *first = newn;
        *last = NULL;
    }
    else // LL containt at least one node
    {
      newn -> next = *first;
        (*first) -> prev = newn;
        *first = newn;
    }
    (*last )->next = *first;
    (*first) ->prev = *last;
}

void InsertLast(PPNODE first,PPNODE last,int no)
{

    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no ;
    newn ->next = NULL;
    newn -> prev = NULL;

    if((*first)== NULL &&(*last== NULL)) //LL is empty
    {
        *first = newn;
        *last = newn;
    }
    else // LL containt at least one node
    {
     (*last) ->next = newn;
     newn ->prev= *last;
     *last = newn;   
    }
    (*last )->next = *first;
    (*first) ->prev = *last;
}

void InsertAtFirst(PPNODE first,PPNODE last,int no ,int pos)
{

}
void DeleteFirst(PPNODE first,PPNODE last)
{
 
    if(*first && (*last)) //LL is empty
    {
        return ;
    }
    else if(*first == *last) //LL contain at least one NODE
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first) ->next;
        free((*first) -> prev);

        (*last)-> next = *first;
        (*first) -> prev = *last;
    }

}
void DeleteLast(PPNODE first,PPNODE Last)
{
    
    if(*first == (*Last)) //LL is empty
    {
        return ;
    }
    else if(*first == (*Last))
    {
        free(*first);
        *first = NULL;
        *Last = NULL;
    }
    else
    {
      (*Last) = (*Last)->prev;
      free((*Last) -> next); 
      
      (*Last) -> next = *first;
      (*first) -> prev = *Last;
    }
}

void Display(PNODE first,PNODE last) //temp  variable yet nahi
{
    //important filter for circular
    if(first == NULL && last == NULL)  //ll is empty
    {
        printf("LinkedList is empty");
        return;
    }

    printf(" <=>");
    do
    {
        printf("|%d|  <=> ",first ->next);
        first = first ->next;
    }while(first != last -> next);
    printf("\n");
}

int Count(PNODE first,PNODE last)
{
    int iCount = 0;

    if(first == NULL && last == NULL) //LL is empty
    {
        return 0;
    }
    do
    {
        iCount++;
        first = first ->next;
    }while(first != last ->next);

    return iCount;
}

void DeleteAtPos(PPNODE first,PPNODE Last,int pos)
{

}
//segmentation fault  due to Dispaly &Count
int main()
{
    int iRet =0;
    PNODE head = NULL;
    PNODE tail = NULL;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("No of nodes are:",iRet);

    InsertLast(&head,&tail,1);
    Display(head,tail);

    iRet = Count(head,tail);
    printf("No of nodes are:",iRet);

   DeleteFirst(&head,&tail);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("No of nodes are:",iRet);

   DeleteLast(&head,&tail);

   Display(head,tail);

   iRet = Count(head,tail);
   printf("No of nodes are:",iRet);

   return 0;
}