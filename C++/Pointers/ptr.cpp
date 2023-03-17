#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
// Pointers Basic

// Wrong way to do it.
int swap(int a, int b)
{
    cout << a << " " << b << endl;
    cout << &a << " " << &b << endl;
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
    cout << &a << " " << &b << endl;
    // Address remains the same, only the value changes (call by value not reference)

    return 0;
}

int betterSwap(int *pointer_x, int *pointer_y)
{
    // 2 pointers -> int type.
    int temp;
    temp = *pointer_x;       // value of pointer_x = temp;
    *pointer_x = *pointer_y; // swapping
    *pointer_y = temp;

    // The value of pointer_x and pointer_y get swapped as well as the reference gets swapped (the memory address) -> Pass by reference method.

    return 0;
}

// Finding the length using normal method and pointers

int len_of_str(string s)
{
    // cout << s << endl;
    int count = 0;
    // Bruteforce
    for (int i = 0; i < s.length(); i++)
    {
        count++;
    }
    cout << count;
    cout << endl;
    // Direct approach
    cout << s.length();

    // Pointer approach

    return 0;
}

int strlen(char *s)
{ // defined that s is a pointer of type char.
    int i;
    for (i = 0; *s != 0; s++)
    {
        // till the value of s (basically till it reaches the end) is != 0, keep increming s.
        i++; // to keep count.
    }
    return i;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // swap(4,5);
    // betterSwap(4,5);
    // len_of_str("samit");
    // strlen('s');

    return 0;
}
