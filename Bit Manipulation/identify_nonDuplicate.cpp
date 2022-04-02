#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Identify number

// arr = [2,3,4,1,2,1,3,6,4] every number is repeated except 6, answer = 6

// O(N) -> XOR entire array -> all duplicates will lead to you (a^a = 0)
// Remaining = a ^ 0 -> (a ^ 0) = 4.

int identify(vector<int> &arr)
{
    int unique = 0;
    for (int number : arr)
    {
        // XOR every number with 0
        unique = unique ^ number;
    }
    return unique;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {2, 3, 4, 1, 2, 1, 3, 6, 4};
    cout << identify(arr);

    return 0;
}
