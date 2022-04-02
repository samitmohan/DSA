#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Write a program to calculate inverse of a number.
// (For calculating inverse, you should have a valid input i.e, for a number of ndigits, the value of each digit should be 1 to n and is unique.)
// 25413 -> 41532 (in “25413” 2 is at 1st place therefore 1 is placed on 2nd place in“41532”. 5 is at 2nd place in “25413”
// therefore 2 is at 5th place in “41532” and soon

// Answer -> 25413 -> index 1 2 3 4 5 -> swap indexes with numbers -> inverse. 41532.
// 2-> 1st index. 5 -> 2nd Index || In inverse -> 1 -> 2nd index, 2 -> 5th index

int countOfdigits(int n)
{
    int count = 0;
    while (n != 0)
    {
        count++;
        n /= 10;
    }
    return count;
}

int inverse(int number)
{
    int n = countOfdigits(number); // length of number
    int index = n;
    int inverse = 0; // for now
    while (number > 0)
    {
        int rem = number % 10; // last digit of the number -> 3
        inverse = inverse + index * pow(10, n - rem);
        number /= 10;
        index--;
    }
    cout << inverse;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // countOfdigits(1232);
    inverse(25413);
    return 0;
}
