
def Sumfactors(no):
        iSum = 0
        for  i in range(1,int((no/2)+1)):
                if (no % i ==0) :
                        iSum = iSum + i
        return iSum                

def main():
        Value = 0
        Ret = 0

        Value = int(input("Enter number : "))

        Ret = Sumfactors(Value)
        print("Summation of factors : ",Ret)


main() 