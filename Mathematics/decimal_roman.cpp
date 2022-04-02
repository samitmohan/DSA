#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/integer-to-roman/

// Coverting Decimal to Roman Numeral

/*
Symbol        Value
I             1
IV            4
V             5
IX            9
X             10
XL            40
L             50
XC            90
C             100
CD            400
D             500
CM            900 
M             1000       
*/

// Steps 
// 1) Number = 3549
// 3549 >= 1000 (base), largest base value : 1000 initially.
// 3549/100, quotient = 3, remainder = 549 -> the symbol M will be repeated thrice.
// Append result in 2nd list, call function again.

// 2) Number = 549
// 1000 > 549 >= 500, largest base value : 500
// 549/500, quotient = 1, remainder = 49, D, 1 time and then stop loop.
// Append result in 2nd list, call functin again

// 3) Number = 49
// 50 > 49 > 40, largest base value : 40
// 49/40, quotient = 1, remainder = 9, XL, 1time and stop loop
// Append result in 2nd list, call function again (till remainder = 0)

// 4) Number = 9
// 9 is present in list so directly fetch value from dictionary and set remainder = 0
// IX will be repeated once and added to list again, remainder = 0.

// 5) Join 2nd list values -> MMMDXLIX


void printRoman(int number) 
{
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string symbol[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    // string ans = "";
    while (number > 0) 
    {
        int div = number / num[i];
        number = number % num[i];
        while (div--) 
        {
            cout << symbol[i];
            // ans += symbol[i];
        }
        i--;
    }
    // return ans;
}

int main()
{  
    int number = 58;
    printRoman(number);

    return 0;
}
