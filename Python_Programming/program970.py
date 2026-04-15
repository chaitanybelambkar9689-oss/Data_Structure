def CopySmall(Brr):

    Result = ""

    for ch in Brr:

        if((ch) >= 'a' and (ch) <='z' ):
            Result = Result + ch
    return Result        

def main():
    print("Enter String : ")
    Arr = input()

    Ret = CopySmall(Arr) 

    print("Updated string is",Ret)



main() 