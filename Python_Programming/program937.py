
def Addition(Value1,Value2):
    Result = 0
    Result = Value1 +Value2
    return Result



def main():
    No1 = 0
    No2 = 0
    iRet = 0

    print("Enter First Number : ")
    No1 = int(input())

    print("Enter Second Number : ")
    No2 = int(input())

    iRet = Addition(No1,No2)

    print("Addition is : ",iRet)


main() # OS = C/C++,JVM =Java ,PVM = P