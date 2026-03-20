#include<iostream>
using namespace std;

#pragma pack(1)
template <class T>
class node
{
    public:
        T data;
        node <T>* next;

    node(int no)
    {
        this -> data = no;
        this -> next = NULL;
    }    
};


template <class T>
class SinglyLLL
{

    private: //Important
          node <T> *first;  //head
        int iCount;

    public:
       SinglyLLL();
        void InsertFirst(T);
        
        void InsertLast(T);
       
        void DeleteFirst();
       

        void DeleteLast();
       
        void Display();
       
        int Count();
        

        void InsertAtPos(T no,int );
        
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
node<T> * newn = NULL;

newn = new node(no);

if(first == NULL)
{
first = newn;
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

node * newn = NULL;
node * temp =NULL;

newn = new node(no);

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
node<T>* temp = NULL;

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
    node <T> * temp = NULL;

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
    node <T> * temp = NULL;
int iCnt = 0;

temp = first;

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
    node * temp = NULL;
    node * newn = NULL;

int i = 0;
int iCount = 0;


iCount = Count();

if((pos < 1) || (pos > iCount +1))
{
    cout<<"Invalid posistion\n";
    return;
}

if(pos == 1)
{
    InsertFirst(no);
}
else if(pos == iCount+1)
{
    InsertLast(no);
}
else
{
    newn = new node(no);
    

    temp = this->first;
    
    for(i = 0;i <pos-1;i++)
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
node <T>* temp = NULL;
node <T>* target = NULL;

int i = 0;



if((pos < 1) || (pos >iCount ))
{
    cout<<"Invalid posistion";
    return;
}

if(pos == 1)
{
    this-> DeleteFirst();
}
else if(pos == iCount+1)
{
    this->DeleteLast();
}
else
{
    temp = this-> first;
    
    for(i = 0;i <pos-1;i++)
    {
        temp = temp ->next;

    }
    target = temp ->next;

    temp ->next = target ->next;
    delete target;
    this->iCount--;
    
}
}

int main()
{
    SinglyLLL <int> *obj= new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj->InsertLast(101);
    obj->InsertLast(121);
    obj->InsertLast(131);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj->DeleteFirst();
     obj->Display();

  

    iRet = obj->Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj->DeleteLast();
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj->InsertAtPos(105,4);
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj->DeleteAtPos(4);
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    return 0;
}