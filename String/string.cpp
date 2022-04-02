#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Strings Basics

// String -> Sequence of char.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "abcd";
    cout << s << endl;
    // length() -> function | s.size() works in the same way
    cout << s.length() << endl;
    // add to string
    s = s + "123";
    cout << s << endl;

    // String Comparison -> ASCII value se compare karega. (S1-S2 = positive)

    string s1 = "abcdef";
    string s2 = "aabcds";
    if (s1 > s2)
    { // s1-s2 = positive
        cout << s1 << " is greater than " << s2 << endl;
    }
    else if (s1 < s2)
    {
        cout << s1 << " is smaller than " << s2 << endl;
    }
    else
    {
        cout << "Both are equal" << endl;
    }

    // Another method
    if (s1.compare(s2) > 0)
    {
        cout << "s1 is greater than s2" << endl;
    }
    else if (s1.compare(s2) < 0)
    {
        cout << "s1 is smaller than s2" << endl;
    }
    else
    {
        cout << "Both are equal" << endl;
    }

    // Input a string

    string str;
    // cin >> str;
    // cout << str;

    // Another method -> get line
    // getline(cin, str);
    // cout << str;

    // Substring

    string st2 = "abcdefghi";
    st2 = st2.substr(2, 6); // Starting Point, Number of digits to print after that (including the starting point) (start,length)
    cout << st2 << endl;    // cdefgh

    return 0;
}
