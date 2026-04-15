def Summation(Brr):
      Sum = 0 

      for no in Brr:   #For each loop
            Sum  = Sum + no
      return Sum      
def main():
      Size = 0
      Value = 0

      Arr = []  

      print("Enter number of elemnets : ")
      Size  = int(input())

      print("Enter the elements : ")

      for i in range(Size):
            Value = int(input())
            Arr.append(Value)

      Ret = Summation(Arr)      
      print("Summation is : ",Ret)

main() 