#include <bits/stdc++.h>
using namespace std;
// Problem Link -> https://leetcode.com/problems/3sum-with-multiplicity/submissions/

// mp : maps element on the array to it's number of appearances.
// Convert 3sum -> 2sum (i + j + k = target)
// target - i - j = k. 
// Include duplicates : mp[arr[i]]++;
// mod for safety -> large numbers

/*

Example : 
Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
*/

typedef long long ll; // for safety

int threeSumMulti(vector<int> &arr, int target) 
{
    ll mod = 1e9+7; // for safety
    ll i, j, k, n = arr.size(); // all start from end
    unordered_map<ll, ll> mp;
    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            // answer
            ans += mp[target - arr[i] - arr[j]];
        }
        // for multiciplities / duplicates, keep a counter -> freq maps element to their number of occurences.
        mp[arr[i]]++;
    }
    return ans % mod;
}

int main() {
    vector<int> arr = {1,1,2,2,3,3,4,4,5,5};
    cout << threeSumMulti(arr, 8) << endl;
}
