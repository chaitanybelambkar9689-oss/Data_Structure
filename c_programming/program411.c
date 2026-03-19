#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first ,PPNODE Last,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn -> next = NULL;

    if((*first == NULL)&&(*Last == NULL)) //@
    {
        *first = newn;
        *Last = newn;

    }
    
    else
    {
        newn -> next = *first;
        *first = newn;

    }
    
    (*Last) -> next = *first;



}

void InsertLast(PPNODE first ,PPNODE Last,int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn -> data = no;
    newn -> next = NULL;

    if((*first == NULL)&&(*Last == NULL))
    {
        *first = newn;
        *Last = newn;

    }
    
    else
    {
        (*Last) -> next = newn; //@
        *Last  = newn;        //@
        
    }
    
    (*Last) -> next = *first;
     

}



void DeleteFirst(PPNODE first,PPNODE Last)
{
    PNODE temp = NULL;

  if((*first == NULL) && (*Last == NULL)) // case 1
  {
    return;
  }
  else if(*first == *Last) // case 2
  {
    free(*first);
    *first = NULL;
    *Last = NULL;
  } 
  else //case 3
  {
    temp = *first;
    
    *first = (*first) -> next;
    free(temp);
    (*Last)-> next = *first;
  } 
}

void DeleteLast(PPNODE first,PPNODE Last)
{
    PNODE temp = NULL;

  if((*first == NULL) && (*Last == NULL)) // case 1
  {
    return;
  }
  else if(*first = *Last) // case 2
  {
    free(*first);
    *first = NULL;
    *Last = NULL;
  } 
  else //case 3
  {
    temp = *first;
    
    while(temp -> next != *Last)
    {
        temp = temp -> next;
    }

    free(*Last);
    *Last = temp;

    (*Last) -> next = (*first);
  } 

}


void Display(PNODE first ,PNODE Last)
{
    do 
    {
        printf("| %d | ->",first ->data);
        first = first->next;
    }while(first != Last -> next);

    printf("\n");
    
}

int Count(PNODE first ,PNODE Last)
{
    int iCount = 0;

    do 
    {
        iCount++;
        first = first->next;
    }while(first != Last -> next);
    return iCount;
}

void InsertAtPos(PPNODE first ,PPNODE Last,int no,int pos)
{
    int iCount = 0;
    int i = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    iCount =   Count(*first,*Last);
 
    if((pos < 1) || pos >(iCount +1))
    {
        printf("Invalid input");
        return ;
    }

    if(pos == 1)
    {
         InsertFirst(first,Last,no);
    }

    else if(pos == iCount +1)
    {
         InsertLast(first,Last,no);
    }

    else
    {
    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no ;
    newn -> next = NULL;

    temp = *first;
    for(i = 1;i< pos -1 ; i++)
    {
        temp = temp ->next;
    }

    newn ->next = temp ->next;
    temp ->next = newn;
    }
}


void DeleteAtPos(PPNODE first,PPNODE Last ,int pos)
{
    int iCount = 0;
    int i = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;
    PNODE target = NULL;

    iCount =   Count(*first,*Last);

    if(pos < 1 || pos >(iCount))
    {
        printf("Invalid input");
        return ;
    }
    if(pos == 1)
    {
       DeleteFirst(first,Last);
    }

    else if(pos == iCount )
    {
        DeleteLast(first,Last);
    }
    else
    {

    }
}
int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;   //@
    int iRet = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);
    InsertLast(&head,&tail,131);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("No of nodes are %d",iRet );

    DeleteFirst(&head,&tail);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("No of nodes are %d",iRet );

    DeleteFirst(&head,&tail);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("No of nodes are %d",iRet );

    InsertAtPos(&head,&tail,105,3);

    Display(head,tail);

    iRet = Count(head,tail);
    printf("No of nodes are %d",iRet );
    
    return 0;
}