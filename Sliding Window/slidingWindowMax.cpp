#include <iostream>
#include <vector>
#include <deque>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/sliding-window-maximum/

int maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> res;
    deque<int> dq;
    int i = 0, j = 0;

    // sliding window condition
    while (j < nums.size())
    {
        // while last element of deque < current number (remove that element)
        // why? because we want to find max element in that window.
        // if we have greater element than current element, which is at the end of deque, then that smaller element is of no use -> remove it from back of dq.
        while (dq.size() > 0 and dq.back() < nums[j])
        {
            dq.pop_back();
        }

        // after removing all smaller elements, push the larger element in dq
        dq.push_back(nums[j]);

        // if window size not found
        if (j - i + 1 < k)
        {
            j++;
        }
        // window size found
        else if (j - i + 1 == k)
        {
            // front element of dq  = max element from that particular window
            res.push_back(dq.front());

            // reverse operations -> shifting window
            // remove i (if i is pointing to the same element which is present at the front of dq)
            if (nums[i] == dq.front())
            {
                dq.pop_front();
            }
            // shift window
            i++;
            j++;
        }
    }

    return res;

    // for(auto x : res)
    // {
    //     cout << x << " ";
    // }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    maxSlidingWindow(nums, 3);
    return 0;
}
