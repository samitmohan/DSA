#include <iostream>
#include <vector>

using namespace std;

// Non repeating element where every element repeats twice.

// Can use a hash map as well, but using bitwise operation this is easier.

// XOR of all elements gives us number with single occurrence.
// a^a = 0 and a^0 = a
// [7,3,5,4,6,3,4], res = 7 ^ (3 ^ 3) ^ (4 ^ 4) ^ (5 ^ 5) = 7.

int unique(vector<int> &arr)
{
    // xor of all and return
    int result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        result = result ^ arr[i];
    }
    return result;
}

int main()
{
    vector<int> arr = {2, 3, 5, 4, 5, 3, 4}; // ANS ; 2
    cout << "Unique elem : " << unique(arr);

    return 0;
}
