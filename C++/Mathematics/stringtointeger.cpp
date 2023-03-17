#include <bits/stdc++.h>
using namespace std;

// Problem Link -> https://leetcode.com/problems/string-to-integer-atoi/
class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.size();
        if (s.empty())
        { // Checking the empty string
            return 0;
        }
        int sign = 1, i = 0;
        while (s[i] == ' ' && i < n)
        { // Removing Whitespaces from starting
            i++;
        }

        if (i == n)
            return 0; // Only contains whitespaces

        if (s[i] == '-')
        { // For checking sign
            sign = -1;
            i++
        }
        else if (s[i] == '+')
        {
            i++;
        }

        long int out = 0;

        while (s[i] >= '0' && s[i] <= '9')
        { // Checking the range
            out *= 10;
            if (out >= INT_MAX || out <= INT_MIN)
                break;
            out = out + s[i] - '0';
            i++;
        }

        if (sign == -1)
        {
            out = -1 * out;
        }
        if (out <= INT_MIN)
        {
            return INT_MIN;
        }
        if (out >= INT_MAX)
            return INT_MAX;
        return (int)out;
    }
};