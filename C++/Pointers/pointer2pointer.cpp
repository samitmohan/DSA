#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int number1 = 10;
    int *ptr1 = &number1; // 10
    int *ptr2 = ptr1;     // 10 (pointer to another pointer)

    cout << *ptr1 << endl;
    cout << *ptr2 << endl;

    int number2 = 20;
    *ptr2 = number2; // changed for both ptr1 and ptr2. If ptr2 = &number2 then ptr2 would've have been changed but ptr1 would've been stayed the same.
    // Changes for both ptr1 and ptr2 since ptr2 -> ptr1 -> a

    cout << *ptr1 << endl; // 20;
    cout << *ptr2 << endl; // 20;

    return 0;
}