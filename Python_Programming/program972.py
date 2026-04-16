def CountCapital(Brr):
    iCount = 0

    for ch in Brr:
        if(ord(ch) >= 65 and ord(ch) <= 90):    # Ord gives ascii value
            iCount = iCount+1
    return iCount


def main():
    print("Enter String : ")
    Arr = input()

    Ret = CountCapital(Arr)
    print("Number of capital characters are : ",Ret)


main() 