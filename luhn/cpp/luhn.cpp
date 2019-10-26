// Prg of LUHN ALGO in C++

#include <bits/stdc++.h>
using namespace std;


bool checkLuhn(const string &cardNo)
{
    int nDigits = cardNo.length();

    int nSum = 0, isSecond = false;
    for (int i = nDigits - 1; i >= 0; i--)
    {

        int d = cardNo[i] - '0';

        if (isSecond == true)
            d = d * 2;

        /* Adding the two digits to handle
           cases that make double digit number
           after doubling */
        nSum += d / 10;
        nSum += d % 10;

        isSecond = !isSecond;
    }
    return (nSum % 10 == 0);
}


// MAIN
int main()
{
    string cardNo = "79927398713";
    if (checkLuhn(cardNo))
        printf("This is a valid identification number.");
    else
        printf("This is not a valid identification number.");
    return 0;
}
