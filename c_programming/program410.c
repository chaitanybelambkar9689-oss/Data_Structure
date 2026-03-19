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

void InsertAtPos(PPNODE first ,PPNODE Last,int no,int pos)
{

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
  else if(*first == *Last) // case 2
  {
    free(*first);
    *first = NULL;
    *Last = NULL;
  } 
  else //case 3
  {
    temp = *first;
    
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    free(*Last);
    *Last = temp;

    (*Last) -> next = (*first);
  } 

}

void DeleteAtPos(PPNODE first,PPNODE Last ,int pos)
{

}

void Display(PNODE first ,PNODE Last)
{
    do 
    {
        printf("| %d | ->",first ->data);
        first = first->next;
    }while(first != Last -> next);

    printf("");
    
}

int Count(PNODE first ,PNODE Last)
{
    int iCount = 0;

    do 
    {
        iCount++;
        printf("| %d | ->",first ->data);
        first = first->next;
    }while(first != Last -> next);
    return iCount;
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
    
    return 0;
}