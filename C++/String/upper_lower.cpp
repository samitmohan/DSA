#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Write a function that accepts a character and prints if it is “Uppercase” or“Lowercase”
// Multiple Ways

// inbuilt function

int upper_lower_one()
{
    char a;
    cin >> a;
    // checks for upper/lower case
    if (isupper(a))
    {
        cout << "Uppercase";
    }
    else
    {
        cout << "Lowercase";
    }
    return 0;
}

// ASCII value
// 65-90 (a-z) ; uppercase
// 97-122 (a-z) ; lowercase

int ascii_method()
{
    char ch;
    cin >> ch;
    if (ch >= 65 && ch <= 90)
    {
        cout << "Uppercase";
    }
    else if (ch >= 97 && ch <= 122)
    {
        cout << "Lowercase";
    }

    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ascii_method();

    return 0;
}