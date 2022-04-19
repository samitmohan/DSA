#include <iostream>
using namespace std;

// fast exponentiation in O(logN) time instead of O(N) 

int power(int a, int N) 
{
    // base case
    if (N == 0) 
    {
        return 1;
    } 
    else if (N == 1) 
    {
        return a; // base 
    } 
    else 
    {
        int R = power(a, N / 2);
        if (N % 2 == 0) 
        {
            return R * R; // even
        } 
        else 
        {
            return R * a * R; // odd
        }
    }
}

int main() 
{
    cout << power(2,2); // 4
    return 0;
}
