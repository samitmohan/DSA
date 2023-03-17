#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// notes on pointers

//int *p = arr.data();
//cout << *p << endl;
//*(p+4) =

void function_pointer(int *ptr)
{
    *ptr = 50;
    cout << *ptr << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a = 15;
    // p storing address of a. (of type int)
    int *p = &a;
    cout << a << endl;
    cout << p << endl;
    // me jis bande ko point kar raha hu -> Uska value kya hai?
    cout << *p << endl;
    // indirectly accessing a and changing the value
    *p = 75;
    cout << a << "\n";

    // int *p = stores address of int (a = 15)
    // khud ka bhi toh address hoga p ka? -> address of p?
    // **q = &p. q is also storing address of the pointer which is storing address of an integer (a=15)
    int **q;
    q = &p;
    // same
    cout << *q << "\n";
    cout << p << "\n";

    // p = 1k(pointing to a), q = 2k (pointing to p), address of q? r (pointing to q)

    int ***r = &q;
    // same
    cout << **r << " " << *q << " " << p << "\n";

    // dereferencing (75)
    cout << ***r << " " << **q << " " << *p << "\n";

    int arr[] = {10, 20, 30, 40};
    // initially array[] = 1000 (address of first variable)
    // proof -> cout << *arr (value at arr)
    cout << arr << endl; // address of 10
    cout << *arr << endl;

    // cout << arr = address of 10
    // what will arr + 1 give? (1004) -> address of 20.
    cout << *(arr + 1) << "\n"; // should give 20.

    // Question
    // arr ? -> Stores address of arr[0] = 10 or 1K (address)

    int *ptr = arr;             // ptr is pointing to address of arr which is pointing to 0th elem. (10)
    cout << *(ptr + 3) << "\n"; // should give me 40

    // in revision, all these things are the same. (20)
    cout << *(ptr + 1) << " " << arr[1] << " " << *(arr + 1) << "\n";

    int num = 100;
    // change is reflected because call by ref -> addressed is passed.
    function_pointer(&num);

    // should be 50, not 100. (because of function_pointer)
    cout << num << endl;

    return 0;
}
