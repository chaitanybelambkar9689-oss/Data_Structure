/////////////////////////////////////////////////////////////////////
////Generalised Data Structure Library
/////////////////////////////////////////////////////////////////////

/*
-------------------------------------------------------------------------------------
 Type             name of class for node              name of class for functionality

-------------------------------------------------------------------------------------
SinglyLinear      SinglyLLLnode                        SinglyLLL
SinglyLinear      SinglycLLnode                        SinglycLL

DoublyLinear      doublyLLLnode                        doublyLLL 
DoublyCircular     doublyCLLnode                        doublyCLL 
-------------------------------------------------------------------------------------
*/


#include<iostream>
using namespace std;


////////////////////////////////////////////////////////////////
//  Singly Linear LinkedList using generic Appoach
/////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
    public:
        T data;
         SinglyLLLnode <T>* next;

     SinglyLLLnode(int no)
    {
        this -> data = no;
        this -> next = NULL;
    }    
};


template <class T>
class SinglyLLL
{

    private: //Important
           SinglyLLLnode <T> *first;  //head
        int iCount;

    public:
       SinglyLLL();
        void InsertFirst(T);
        
        void InsertLast(T);
       
        void DeleteFirst();
       

        void DeleteLast();
       
        void Display();
       
        int Count();
        

        void InsertAtPos(T ,int );
        
        void DeleteAtPos(int );
       
           
};

template <class T>
SinglyLLL<T>::SinglyLLL()
{
cout<<"Object of singly LL gets created.\n";
this->first = NULL;
this->iCount = 0;
}

template <class T>
void SinglyLLL<T>:: InsertFirst(T no)
{
 SinglyLLLnode<T> * newn = NULL;

newn = new  SinglyLLLnode<T>(no);

if(first == NULL)
{
this->first = newn;
}
else
{
newn ->next = first;
this->first = newn;
}
iCount++;
}

template <class T>
void SinglyLLL<T>:: InsertLast(T no)
{

 SinglyLLLnode <T> * newn = NULL;
 SinglyLLLnode <T>* temp =NULL;

newn = new SinglyLLLnode<T>(no);

newn->data = no;
newn ->next = NULL;

if(first == NULL)
{
this->first = newn;
}
else
{
temp = this-> first;
while(temp -> next != NULL)
{
    temp = temp ->next;
}
temp ->next = newn;
}
iCount++;
}

template <class T>
void SinglyLLL<T>:: DeleteFirst()
{
 SinglyLLLnode<T>* temp = NULL;

if(first == NULL)
{
    return;
}
else if(this->first ->next == NULL)  //else if(this->iCount == 1)
{
    delete this->first;
    this->first = NULL;
}
else
{
    temp = this-> first;
    first = this->first -> next;
    delete temp;
}
this->iCount--;
}

template <class T>
void SinglyLLL<T>::DeleteLast()
{
     SinglyLLLnode<T> * temp = NULL;

if(this->first == NULL)
{
    return;
}
else if(this->first ->next == NULL)
{
    delete first;
    this->first = NULL;
}
else
{
    temp = first;
    while(temp ->next ->next != NULL)
    {
        temp = temp ->next;
    }
    delete temp->next;
    temp ->next = NULL;
}
this->iCount--;
}

template <class T>
void SinglyLLL<T>:: Display()
{
     SinglyLLLnode <T> * temp = NULL;
int iCnt = 0;

temp = this->first;

for(iCnt = 1;iCnt <= iCount;iCnt++)  //Updated
{
    cout<<"|"<<temp->data<<"|->";
    temp = temp ->next;
}
cout<<"NULL\n";
}

template <class T>
int SinglyLLL<T>::Count()
{
return this->iCount;
}

template <class T>
void SinglyLLL<T>:: InsertAtPos(T no,int pos)
{
     SinglyLLLnode <T> * temp = NULL;
     SinglyLLLnode <T> * newn = NULL;

int iCnt = 0;

if((pos < 1) || (pos > this-> iCount +1))
{
    cout<<"Invalid posistion\n";
    return;
}

if(pos == 1)
{
    this->InsertFirst(no);
}
else if(pos == iCount+1)
{
    this->InsertLast(no);
}
else
{
    newn = new  SinglyLLLnode<T>(no);
    

    temp = this->first;
    
    for(iCnt = 0;iCnt <pos-1;iCnt++)
    {
        temp = temp ->next;

    }
    newn ->next = temp ->next;
    temp -> next = newn;

    this->iCount++;
}
}

template <class T>
void SinglyLLL<T>:: DeleteAtPos(int pos)
{
 SinglyLLLnode <T>* temp = NULL;
 SinglyLLLnode <T>* target = NULL;

int iCnt = 0;



if((pos < 1) || (pos >iCount ))
{
    cout<<"Invalid posistion";
    return;
}

if(pos == 1)
{
    this-> DeleteFirst();
}
else if(pos == iCount)
{
    this->DeleteLast();
}
else
{
    temp = this-> first;
    
    for(iCnt = 0;iCnt <pos-1;iCnt++)
    {
        temp = temp ->next;

    }
    target = temp ->next;

    temp ->next = target ->next;
    delete target;
    this->iCount--;
    
}
}




////////////////////////////////////////////////////////////////
// Doubly  Linear LinkedList using generic Appoach
/////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>

class DoublyLLLnode 
{
    public:

    T data;
    DoublyLLLnode*next;
    DoublyLLLnode *prev;

    DoublyLLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyLLL
{
    private:

        DoublyLLLnode<T> * first = NULL;
        int iCount; //total node
    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int); //2.alwayys int

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();


};

template <class T>
DoublyLLL <T>:: DoublyLLL()
{
    cout<<"Linkedlist gets created \n";

    this -> first = NULL;
    this -> iCount = 0;
}

template <class T>
void  DoublyLLL<T> ::InsertFirst(T no)
{
   DoublyLLLnode<T> * newn = NULL;
   newn = new DoublyLLLnode <T>(no);
   
   if(this -> first == NULL)
   {
    this ->first = newn;
   }
   else
   {
    newn -> next = this ->first;
    this -> first->prev = newn;
    this -> first = newn;
   }
   this -> iCount++;
}

template <class T>
void DoublyLLL<T> ::InsertLast(T no)
{
   DoublyLLLnode<T> * newn = NULL;
   DoublyLLLnode <T>*temp = NULL;

   newn = new DoublyLLLnode<T>(no);
   
   if(this -> first == NULL)
   {
    this ->first = newn;
   }
   else
   {
        temp = this ->first;

        while(temp ->next != NULL)
        {
            temp = temp ->next;
        }

        temp ->next = newn;
        newn ->prev = temp;
   }
   this -> iCount++;    
}

template <class T>
void DoublyLLL<T> ::InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    int iCnt = 0;
  if((pos<1)|| pos>iCount+1)
  {
    cout<<"Invalid position";
    return;
  }
  
  if(pos == 1)
  {
    this ->InsertFirst(no);
  }
  else if(pos == iCount+1)
  {
    this->InsertLast(no);
  }
  else
  {
    newn = new DoublyLLLnode<T>(no);

    temp = this ->first;

    for(iCnt= 1;iCnt <pos -1;iCnt++)
    {
        temp = temp -> next;
    }
     newn -> next = temp -> next;
     temp -> next ->prev = newn;

     temp ->next = newn;
     newn -> prev = temp;
     this ->iCount++;
  }
 
}

template <class T>
void DoublyLLL<T> ::DeleteFirst()
{
    
    if(this -> first == NULL)          
    {
        return;
    } 
    else if(this -> first->next ==NULL)  
    {
        delete this->first;
        this -> first  =NULL;

    }
    else                                
    {
        this -> first = this-> first->next;
        delete this ->first -> prev;
        this ->first ->prev = NULL;

    }
    this ->iCount--;
}

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
   DoublyLLLnode <T> *temp = NULL;
   if(this -> first == NULL)          //LL is empty
    {
        return;
    } 
    else if(this -> first->next ==NULL)  //LL contain one node  
    {
        delete this->first;
        this -> first  =NULL;

    }
    else                                //LL contatin more than one node
    {
        temp = this -> first;

        while(temp ->next -> next != NULL)
        {
            temp = temp ->next;
        }

        delete temp ->next ;
        temp -> next = NULL;
    }
    this ->iCount--; 
}

template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    
    DoublyLLLnode<T> *temp = NULL;

    int iCnt = 0;
  if((pos<1)|| pos>iCount)
  {
    cout<<"Invalid position";
    return;
  }
  
  if(pos == 1)
  {
    this ->DeleteFirst();
  }
  else if(pos == iCount)
  {
    this->DeleteLast();
  }
  else
  {
    temp = this ->first;

    for(iCnt= 1;iCnt <pos -1;iCnt++)
    {
        temp = temp -> next;
    }

    temp ->next = temp -> next ->next;
    delete temp ->next ->prev;

    temp ->next ->prev =temp;

     this ->iCount--;
  }
}
template <class T>
void  DoublyLLL <T>::Display()
{
    DoublyLLLnode <T> *temp = NULL;
    
    temp = this-> first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"|"<<temp ->data<<"|<=>";
        temp = temp ->next;
    }

    cout<<"NULL\n";


}

template <class T>
int DoublyLLL<T> ::Count()
{
    return this->iCount;   
}



//////////////////////////////////////////End of Library////////////////////////////////////////////////////////
int main()
{
    return 0;
}