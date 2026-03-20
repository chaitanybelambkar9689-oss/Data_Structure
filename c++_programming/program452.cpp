//Doubly Circular
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;


class DoublyCL
{
    private:
        PNODE first;  //head
        PNODE last;
        int iCount;

    public:    
        DoublyCL()
        {
            cout<<"Object of singly LL gets created.\n";
            first = NULL;
            iCount = 0;
        }
        void InsertFirst(int no)
        {
            
        }
        void InsertLast(int no)
        {

        }
        void InsertAtPos(int no,int pos)
        {

        }

        void DeleteFirst()
        {

        }

        void DeleteLast()
        {

        }

        void DeleteAtPos(int pos)
        {

        }

        void Display()
        {

        }
        
        int Count()
        {
            return iCount;
        }

};

int main()
{
   DoublyCL obj;
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

   // obj.first = NULL; //error
     // obj.count = NULL; //error

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
