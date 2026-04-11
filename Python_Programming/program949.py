
def CheckPerfect(no):
        iSum = 0
        for  i in range(1,int((no/2)+1)):
                if (no % i ==0) :
                        iSum = iSum + i
        return (iSum == no)                

def main():
        Value = 0
        Ret = 0

        Value = int(input("Enter number : "))

        Ret = CheckPerfect(Value)
        
        if(Ret == True):
                print("It is Perfect Number")
        else:
                print("It is not perfect number")        

main() 