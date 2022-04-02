#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/fizz-buzz/ (Wrong Problem)

// Fizz Buzz

int solve(vector<string> &result, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            result.push_back("FizzBuzz");
        }
        else if (i % 5 == 0)
        {
            result.push_back("Fizz");
        }
        else if (i % 3 == 0)
        {
            result.push_back("Buzz");
        }
        else
        {
            result.push_back(to_string(i));
        }
    }
    // return result;

    for (auto x : result)
    {
        cout << x << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

// FizzBuzz methods

/* 

Note -> Modulo operations are slow, that's the reason. 
Running time and complexity aren't the same thing.

*/


// standard

void fizzBuzz1(int number) 
{
    for (int i = 1; i <= number; i++)
    {
        if (i % 3 == 0)
        {
            cout << "Fizz, "; 
        }
        else if (i % 5 == 0)
        {
            cout << "Buzz, ";
        }
        else if (i % 15 == 0)
        {
            cout << "FizzBuzz, ";
        }
        else  
        {
            cout << i << ", ";
        }
    }
}

// better approach ( % -> O (1) complexity)

void fizzBuzz2(int number) {
    for (int i = 1; i <= number; ++i)
    {
        string output = "";
        if (i % 15 == 0) output += "FizzBuzz";
        else if (i % 3 == 0) output += "Fizz";
        else if (i % 5 == 0) output += "Buzz";
        else if (output == "") output = to_string(i);
        cout << output << " ";
    }
}

int main()
{
    vector<string> result;
    solve(result, 3);

    return 0;
}
