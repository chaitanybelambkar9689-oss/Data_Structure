
def Displayfactors(no):
        for  i in range(1,int((no/2)+1)):
                if (no % i ==0) :
                        print(i)

def main():
        Value = 0

        Value = int(input("Enter number : "))

        Displayfactors(Value)


main() 