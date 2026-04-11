
def CheckEven(no):
        if no % 2 == 0:
                print("It is even number")
        else:
                print("It is Odd Number")   

def main():
        Value = 0

        Value = int(input("Enter number : "))

        CheckEven(Value)


main() 