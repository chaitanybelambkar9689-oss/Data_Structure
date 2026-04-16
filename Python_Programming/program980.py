class Arithematic:
    def  __init__(self,A = 0,B = 0):
        self.No1 = A
        self.No2 = B

    def Addition(self):
        Ans = 0
        Ans = self.No1 +self.No2
        return Ans
    
    def Substraction(self):
        Ans = 0
        Ans = self.No1 - self.No2
        return Ans

def main():
    aobj = Arithematic()
    Ret = 0

    Ret = aobj.Addition()
    print("Addition of two number is : ",Ret)

    Ret = aobj.Substraction()
    print("Substraction of two number is : ",Ret)


main() 