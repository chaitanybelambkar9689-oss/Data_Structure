# Enter String :
# Hello@12
# Updated string is hELLO
def ToggleCase(Brr):

    Result = ""

    for ch in Brr:

        if((ch) >= 'A' and (ch) <='Z' ):
            Result = Result + chr(ord(ch)+32)   #Charactcter la typecaste karnyasathi ch use kartat
        elif((ch) >= 'a' and (ch) <='z' ):
            Result = Result +chr(ord(ch)-32)

        else:
            Result = Result + ch    
                
    return Result        

def main():
    print("Enter String : ")
    Arr = input()

    Ret = ToggleCase(Arr) 

    print("Updated string is",Ret)



main() 