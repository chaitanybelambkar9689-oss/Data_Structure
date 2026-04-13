
def  DisplayDigits(No):

        Digit = 0

        while(No != 0):
                Digit = No % 10
                print(Digit)
                No = No // 10     #Floor Division
        
        
def main():
        Value = 0

        print("Enter number")
        Value = int(input())

        DisplayDigits(Value)

main() 