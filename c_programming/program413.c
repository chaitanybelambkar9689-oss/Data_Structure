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
    
}

void InsertLast(PPNODE first,PPNODE last,int no)
{

}

void InsertAtFirst(PPNODE first,PPNODE last,int no ,int pos)
{

}
void DeleteFirst(PPNODE first,PPNODE Last)
{
    
}
void DeleteLast(PPNODE first,PPNODE Last)
{

}

void Display(PNODE first,PNODE last)
{

}
int Count(PNODE first,PNODE last)
{
    return 0;
}
void DeleteAtPos(PPNODE first,PPNODE Last,int pos)
{

}
int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    return 0;
}