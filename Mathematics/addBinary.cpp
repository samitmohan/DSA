#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/add-binary/submissions/

string addBinary(string A, string B)
{
    // If the length of string A is greater than the length of B
    // swap by calling same function again
    if (A.length() > B.length())
        return addBinary(B, A);
 
    // Calculating the difference len b/w two strings
    int diff = B.length() - A.length();
 
    // Initialise the padding string which is used to store
    // zeroes that should be added as prefix to the string
    // which has length smaller than the other string.
    string padding;
    for (int i = 0; i < diff; i++)
        padding.push_back('0');
 
    A = padding + A;
    string res;
    char carry = '0';
 
    for (int i = A.length() - 1; i >= 0; i--) {
        // This if condition solves 110 111 possible cases
        if (A[i] == '1' && B[i] == '1') {
            if (carry == '1')
                res.push_back('1'), carry = '1';
            else
                res.push_back('0'), carry = '1';
        }
        // This if condition solves 000 001 possible cases
        else if (A[i] == '0' && B[i] == '0') {
            if (carry == '1')
                res.push_back('1'), carry = '0';
            else
                res.push_back('0'), carry = '0';
        }
        // This if condition solves 100 101 010 011 possible
        // cases
        else if (A[i] != B[i]) {
            if (carry == '1')
                res.push_back('0'), carry = '1';
            else
                res.push_back('1'), carry = '0';
        }
    }
 
    // If at the end their is carry then just add it to the result
    if (carry == '1')
        res.push_back(carry);
    // reverse the result
    reverse(res.begin(), res.end());
 
    // To remove leading zeroes
    int index = 0;
    while (index + 1 < res.length() && res[index] == '0')
        index++;
    return (res.substr(index));
}

int main() 
{
    cout << addBinary("11", "100");
    return 0;
}
