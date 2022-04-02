// https://leetcode.com/problems/reverse-string/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Print the reverse of the string.
// 2 pointer approach, Low and High, keep swapping and incrementing low and decrementing high

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

void reverseString(vector<int> &s)
{
    int low = 0, high = s.size() - 1;
    while (low < high)
    {
        // char temp = s[low]
        // s[low] = s[high]
        // s[high] = temp;
        swap(s[low], s[high]);

        // Increment / Decrement the pointers
        low++;
        high--;
    }
    for (auto x : s)
    {
        cout << x << " ";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
