#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Problem Link -> https://leetcode.com/problems/top-k-frequent-elements/

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// comparator to sort pair in decreasing order of their second elem (freq)
bool comparator(pair<int, int> a, pair<int, int> b)
{
    return b.second < a.second;
}

int topKFrequent(vector<int> &arr, int k)
{
    vector<pair<int, int>> x;
    // create map to store every element and it's frequency
    map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    // iterate through map
    for (auto element : mp)
    {
        // insert key - value(map pair) in a vector so that it can be sorted.
        x.push_back(make_pair(element.first, element.second));
    }

    // sort using our rules -> comparator
    sort(x.begin(), x.end(), comparator);

    // ans vector
    vector<int> ans;
    // iterating over first K elements and storing them in a vector
    for (auto i = x.begin(); i != x.begin() + k; i++)
    {
        ans.push_back(i->first);
    }

    // return ans
    for (auto i : ans)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    int k = 2;
    topKFrequent(arr, k);

    // output -> [1,2]
    return 0;
}