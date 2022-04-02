#include <iostream>
#include <vector>
#include <algorithm>

// https://leetcode.com/problems/container-with-most-water/

using namespace std;
typedef long long ll;

/*
----Documentation----

2 pointer approach -> low at 0, high at end. while(low<high) -> Run loop.
ans = Total water contained in an interval = width * height
= distance (high-low) * min(arr[low], arr[high]) (height)

if arr[low] < arr[high] (whenever length of low pointer < length of high pointer)
low++ (shift low to next)

else
high-- (shift high to left)

*/

int maxArea(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = 0;

    while (low < high)
    {
        ans = max(ans, min(arr[low], arr[high]) * (high - low));

        // moving
        if (arr[low] < arr[high])
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(arr);

    return 0;
}
