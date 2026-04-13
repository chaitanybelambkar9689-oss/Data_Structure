
def  DisplaySumDigits(No):

        Digit = 0
        iSum = 0

        while(No != 0):
                Digit = No % 10
                iSum = iSum+Digit
                No = No // 10
        return iSum             
        
        
def main():
        Value = 0
        Ret = 0

        print("Enter number")
        Value = int(input())

        Ret = DisplaySumDigits(Value)
        print("Summation of Digits : ",Ret)

main() 