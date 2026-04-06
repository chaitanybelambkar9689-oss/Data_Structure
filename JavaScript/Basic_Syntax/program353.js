
function SumDigit(no)
{
    let iCount = 0;
    let iDigit = 0;
    let iSum = 0;

    while(no != 0)
    {
        iDigit = no % 10;
        iSum = iSum + iDigit;
        no = Math.floor(no/10);
    }
    return iSum;
}

function main()
{
    let iValue = 72231;

    let iRet = 0;

    iRet = SumDigit(iValue);
    console.log(` Summation is : ${iRet}`);

}
main();