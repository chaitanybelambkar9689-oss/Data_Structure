class Demo : 
    def __init__(self,A,B):
        print("Inside Constructor")
        self.No1 = A
        self.No2 = B


        
           
def main():
    dobj1 = Demo(11,21)
    dobj2 = Demo(10,20)

    print(dobj1.No1)
    print(dobj1.No2)


main() 