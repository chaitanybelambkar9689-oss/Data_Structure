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

    if((*first)== NULL &&(*last== NULL)) //LL contain at least one node
    {

        *first = newn;
        *last = newn;
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

    if((*first)== NULL &&(*last== NULL)) //LL containn at least one node
    {

        *first = newn;
        *last =  newn;
    }
    else // LL containt at least one node
    {
     (*last) ->next = newn;
     newn ->prev = *last;
     *last = newn;   
    }
    (*last )->next = *first;
    (*first) ->prev = *last;
}

void DeleteFirst(PPNODE first,PPNODE Last)
{
 
    if(*first ==NULL && (*Last)==NULL) //LL is empty
    {
        return ;
    }
    else if(*first == (*Last)) //LL contain at least one NODE
    {
        free(*first);
        *first = NULL;
        *Last = NULL;
    }
    else
    {
        *first = (*first) ->next;
        free((*first) -> prev);

        (*Last)-> next = *first;
        (*first) -> prev = *Last;
    }

}
void DeleteLast(PPNODE first,PPNODE Last)
{
    
    if(*first ==NULL && (*Last)==NULL) //LL is empty
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
      
      
        (*Last)-> next = *first;
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
        printf("|%d|  <=> ",first ->data);
        first = first ->next;
    }while(first != last -> next);
    printf("\n");
}

int Count(PNODE first,PNODE last)
{
    int iCount = 0;

    if(first == NULL && last == NULL)
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

void InsertAtFirst(PPNODE first,PPNODE last,int no ,int pos)
{

    int i = 0;
    
    int iCount = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount = Count(*first,*last);

    if((pos < 1)||(pos > iCount +1))
    {
        printf("Invalid Position");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == iCount +1)
    {
        InsertLast(first,last,no);

    }
    else
    {
        newn  = (PNODE)malloc(sizeof(NODE));
         

        temp = *first;

        for(i = 1;i<pos -1;i++)
        {
            temp = temp ->next;
        }

        newn ->next = temp ->next;
        newn -> next ->prev =newn;

        temp -> next = newn;
        newn -> prev = temp;
   
    }
}

void DeleteAtPos(PPNODE first,PPNODE last,int pos)
{
    int i = 0;
    int iCount = 0;
    PNODE temp = NULL;

    iCount = Count(*first,*last);

    if((pos < 1)||(pos > iCount ))
    {
        printf("Invalid Position");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos == iCount +1)
    {
        DeleteLast(first,last);

    }
    else
    {
        temp = *first;

        for(i = 1;i<pos -1;i++)
        {
            temp = temp ->next;
        }
        temp -> next = temp->next->next;
        free(temp->next->prev) ; //400 gone
        temp ->next->prev = temp;
    }
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
   print(iRet);

    InsertLast(&head,&tail,1);
    Display(head,tail);

    iRet = Count(head,tail);
   print(iRet);

   DeleteFirst(&head,&tail);
   DeleteLast(&head,&tail);

   Display(head,tail);

   iRet = Count(head,tail);
   print(iRet);

   InsertAtPos(&head,&tail,105,3);
   InsertAtPos(&head,&tail,111,4);
   InsertAtPos(&head,&tail,115,5);

   Display(head,tail);

   iRet = Count(head,tail);
   print(iRet);

    return 0;
}