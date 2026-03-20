//use of this->
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;


class SinglyLL
{
    public:
        PNODE first;  //head
        int iCount;

        SinglyLL()
        {
            cout<<"Object of singly LL gets created.\n";
            this->first = NULL;
            this->iCount = 0;
        }
        void InsertFirst(int no)
        {
         PNODE newn = NULL;
         
         newn = new NODE;

         newn->data = no;
         newn ->next = NULL;
        
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
        void InsertLast(int no)
        {
            
        PNODE newn = NULL;
        PNODE temp =NULL;
         
         newn = new NODE;

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

        void DeleteFirst()
        {
            PNODE temp = NULL;

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

        void DeleteLast()
        {
            PNODE temp = NULL;
            
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

        void Display()
        {
            PNODE temp = NULL;
            int iCnt = 0;

            temp = first;

            for(iCnt = 1;iCnt <= iCount;iCnt++)  //Updated
            {
                cout<<"|"<<temp->data<<"|->";
                temp = temp ->next;
            }
            cout<<"NULL\n";
        }
        
        int Count()
        {
            return this->iCount;
        }

        void InsertAtPos(int no,int pos)
        {
            PNODE temp = NULL;
            PNODE newn = NULL;

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
                newn = new NODE;
                newn->data = no;
                newn->next = NULL;

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

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL;
            PNODE target = NULL;

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
};

int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj.InsertLast(101);
    obj.InsertLast(121);
    obj.InsertLast(131);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj.DeleteFirst();
     obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj.InsertAtPos(105,4);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    obj.DeleteAtPos(4);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of nodes are"<<iRet <<"\n";

    return 0;
}