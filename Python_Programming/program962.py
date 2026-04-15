def Maximum(Brr):
      iMax = Brr[0] 

      for i in range(len(Brr)):

            if (Brr[i] > iMax):
                  iMax = Brr[i]
      return iMax   
         
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

      Ret = Maximum(Arr)      
      print("Maximum number is: ",Ret)

main() 