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
    // return ans;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    int k = 2;
    topKFrequent(arr, k);

    // output -> [1,2]
    return 0;
}

// Leetcode Solution

class Solution
{
public:
    // comparator to sort pairs in decreasing order of their second element
    static bool MYcomparator(pair<int, int> a, pair<int, int> b)
    {
        return b.second < a.second;
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<pair<int, int>> x;
        map<int, int> mp; // creating a map to store every element and its frequency
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (auto it : mp)
        {
            x.push_back(make_pair(it.first, it.second)); // storing every key-value(map pair) in a vector so that it can be sorted
        }
        sort(x.begin(), x.end(), MYcomparator); // using our MYcompartor function
        vector<int> v;
        for (auto i = x.begin(); i != x.begin() + k; i++)
        { // iterating over first K elements and storing them in a vector to return
            v.push_back(i->first);
        }
        return v;
    }
};

// Using Heaps -> https://leetcode.com/problems/top-k-frequent-elements/discuss/1419093/C%2B%2B-or-Minheap-or-Well-Commented

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // O(1) time
        if (k == nums.size())
        {
            return nums;
        }

        // 1. build hash map : element and how often it appears
        // O(N) time
        map<int, int> count_map;
        for (int n : nums)
        {
            count_map[n] += 1;
        }

        // initialise a heap with most frequent elements at the top
        auto comp = [&count_map](int n1, int n2)
        { return count_map[n1] > count_map[n2]; };
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);

        // 2. keep k top fequent elements in the heap
        // O(N log k) < O(N log N) time
        for (pair<int, int> p : count_map)
        {
            heap.push(p.first);
            if (heap.size() > k)
                heap.pop();
        }

        // 3. build an output array
        // O(k log k) time
        vector<int> top(k);
        for (int i = k - 1; i >= 0; i--)
        {
            top[i] = heap.top();
            heap.pop();
        }
        return top;
    }
};