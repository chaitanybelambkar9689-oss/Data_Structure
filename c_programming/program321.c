#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first,int no)
{
  
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn-> data = no;
    newn->next =NULL;

    if(*first == NULL) //LL is empty
    {
        *first = newn;
    }
    else // LL contain  atleast one node
    {
        newn -> next = (*first);
        (*first)= newn;
    } 

}
void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d |\t",first->data);
        first = first->next;
    }
    printf("NULL \n");
}
void InsertLast(PPNODE first,int no)
{
  
    PNODE newn = NULL;
    PNODE temp =NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn-> data = no;
    newn->next =NULL;

    if((*first) == NULL) //LL is empty
    {
        (*first) = newn;
    }
    else // LL contain  atleast one node
    {
          temp =*first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp -> next = newn;

    } 
}

int Count(PNODE first)
{
    int iCount =0;
    while(first != NULL)
    {
        iCount++;
        first =first->next;
    }
    return iCount;
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if((*first) == NULL) //case-1
    {
        return;
    }
    else if( (*first ) -> next == NULL) //case-2
    {
        free(*first);
        *first = NULL; 
    }
    else //case 3
    {
        temp = *first;
        *first = (*first) -> next;
        free(temp);
    }
}
void DeleteLast(PPNODE first)
{

    if((*first) == NULL) //case-1
    {
        return;
    }
    
    else if( (*first ) != NULL) //case-2
    {
        free(*first);
        *first =NULL; 
    }
    else  // case 3
    {


    }
}


int main()
{
    PNODE head = NULL; //which point to first  Node =head
    int iRet = 0;

    InsertFirst(&head,75);
    InsertFirst(&head,91);
    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    iRet = Count(head);

   
    printf("Number of nodes are : %d\n",iRet);
 
    InsertLast(&head,22);
    InsertLast(&head,66);
    InsertLast(&head,44);

    DeleteFirst(&head);
    
    Display(head);

    iRet = Count(head);
    printf("Number of nodes are : %d\n",iRet);
    
    return 0;
}