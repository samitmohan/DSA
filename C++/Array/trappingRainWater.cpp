#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/trapping-rain-water/

// BruteForce

// ans = 0
// max_left = 0, max_right = 0
// max_left = max(max_left, height[j])
// max_right = max(max_right, height[j])
// min(max_left,max_right) - height[i] = ans.

// Example -> In the diagram.

int trap(vector<int> &height)
{
    // empty vectors (left and right with val = 0)
    vector<int> left(height.size(), 0);
    vector<int> right(height.size(), 0);

    // finding max of left (from beginning)
    for (int i = 1; i < height.size(); i++)
    {
        left[i] = max(left[i - 1], height[i - 1]);
    }

    // finding max of right (from last) (height.size() - 2 because we initialize height with 0. so second last will be the actual last.)
    for (int i = height.size() - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], height[i + 1]);
    }

    // answer
    int ans = 0;
    for (int i = 0; i < height.size(); i++)
    {
        int val = min(left[i], right[i]) - height[i];
        // only add val to answer when it's positive, else no point (5-4 = -1, how will water fall occupy negative space?)
        if (val > 0)
        {
            ans = ans + val;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height);

    return 0;
}
