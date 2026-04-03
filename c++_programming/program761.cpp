#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;
        bool Sorted;

    ArrayX(int no);
    ~ArrayX();

    void Accept();
    void Display();
    
    bool CheckSorted();

    void BubbleSort();
};

ArrayX :: ArrayX(int no)
{
    cout<<"Inside constructor\n";
    iSize = no;
    Arr = new int[iSize];
    Sorted = true;
}

ArrayX :: ~ArrayX()
{
    cout<<"Inside destructor\n";
    delete [] Arr;
}

void ArrayX :: Accept()
{
    int iCnt = 0;

    cout<<"Enter the elements : \n";
    cin>>Arr[iCnt];
    
    // iSize = 5

    // 0    1   2   3   4
    // 11   14  17  21  26

    for(iCnt = 1; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];

        if(Arr[iCnt-1] > Arr[iCnt])
        {
            Sorted = false;
        }
    }

    //Sorted = CheckSorted();
}

void ArrayX :: Display()
{
    int iCnt = 0;

    cout<<"Elements of the array are : \n";

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

bool ArrayX :: CheckSorted()
{
    int i = 0;
    bool bFlag = true;

    for(i = 0; i < iSize-1; i++)
    {
        if(Arr[i] > Arr[i+1])
        {
            bFlag = false;
            break;
        }
    }

    return bFlag;
}

void ArrayX :: BubbleSort()
{
    int i = 0, j = 0;
    int temp = 0;

    if(Sorted == true)  // Important filter  // Aadhich array sorted ahe ka nahi te check karto
    {
        return;
    }

    for(i = 0; i < iSize - 1; i++)          // Outer  iSize = 5// iSize -1 mhanje loop 0 to 3 chalel ani 4th element autamatically sorted houn jato
    {
        for(j = 0; j < iSize - 1 - i; j++)  // Inner  // element  pratek  vela  1 ne kami hoto ani shevati jaun thambato 
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }
    }

    Sorted = true;
}

int main()
{   
    int iValue = 0;
    
    cout<<"Enter the number of elements : \n";
    cin>>iValue;

    ArrayX aobj(iValue);

    aobj.Accept();

    cout<<"Data before sorting\n";

    aobj.Display();

    aobj.BubbleSort();

    cout<<"Data after sorting\n";
    
    aobj.Display();
    
    return 0;
}