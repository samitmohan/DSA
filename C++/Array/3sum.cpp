#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

// Google Question

// Given an array containing N integers, and a number target denoting the target sum
// Find all distinct integers that can add up to form target sum.
// The numbers in each triplet should be ordered + asc too, return empty array if no such triplet exists.

// Basically find triplets, ascending order
// array = [1,2,3,4,5,6,7,8,9,15]
// target = 18
// answer :
// 1,2,15
// 3,7,8
// 4,6,8
// 5,6,7

// Bruteforce approach -> O(N^3) just like 2sum, using 3 loops, find target sum.

// Better approach -> 2sum problem -> O(N) using unordered set.

// Don't use unordered set.
// Using 2 pointer approach -> Binary Search

// 1) Sort array (NlogN)
// 2) Iterate over array -> pick current number -> solve pair sum problem for other part, find arr[j] and arr[k]
//             -> O(N) time to iterate -> O(N^2) -> Solve pair sum problem for other 2 parts
// Total -> O(NlogN) + O(N^2) = O(N^2)

vector<vector<int>> threeSum(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    // Pick every number, solve pair sum for remaining part (2 rem numbers)
    for (int i = 0; i < arr.size() - 3; i++)
    {
        // two pointer
        int j = i + 1;
        int k = arr.size() - 1;

        // find b + c = target - a (we're finding b and c using two pointer approach)
        while (j < k)
        {
            int current_sum = arr[i]; // we already have this as of now
            current_sum += arr[j];
            current_sum += arr[k];

            // condition
            if (current_sum == target)
            {
                result.push_back({arr[i], arr[j], arr[k]});
                j++; // to look for other pairs in the array
                k--; // to look for other pairs in the array
            }
            else if (current_sum > target)
            {
                k--; // high--;
            }
            else
            {
                j++; // low++
            }
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    auto result = threeSum(arr, 0);
    for (auto v : result)
    {
        for (auto no : v)
        {
            cout << no << ",";
        }
        cout << endl;
    }
    return 0;
}
