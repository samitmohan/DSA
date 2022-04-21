#include <bits/stdc++.h>
using namespace std;

// Problem Link -> https://leetcode.com/problems/design-hashset/submissions/

// Good approaches -> https://leetcode.com/problems/design-hashset/discuss/773006/C%2B%2B-3-Approaches

// Using Array / Vector -> Not a proper solution since it uses O(N) to search where as hashmap works in O(1)

class MyHashSet
{
private:
    vector<int> arr;

public:
    MyHashSet()
    {
    }

    void add(int key)
    {
        auto i = find(arr.begin(), arr.end(), key);
        if (i == arr.end())
        {
            arr.push_back(key);
        }
    }

    void remove(int key)
    {
        auto i = find(arr.begin(), arr.end(), key);
        if (i != arr.end())
        {
            arr.erase(i);
        }
    }

    bool contains(int key)
    {
        auto i = find(arr.begin(), arr.end(), key);
        if (i == arr.end())
        {
            return false;
        }
        return true;
    }
};
o
    // Another hack way

    class MyHashSet
{
    // store details of key k in kth index of array
    vector<bool> ans;

public:
    MyHashSet()
    {
        // max possible value of key is 10^6 so array should be of length 10^6 + 1
        ans.resize(1e6 + 1, false);
    }

    // change presence of Kth value of array to add or remove from hashset

    void add(int key)
    {
        ans[key] = true;
    }

    void remove(int key)
    {
        ans[key] = false;
    }

    // to check if present just return it's value at K th position
    bool contains(int key)
    {
        return ans[key];
    }
};

// Better way

class MyHashSet
{
public:
    const int BUCKET_SIZE = 100; // any number you like
    vector<int> bucket[100];
    MyHashSet()
    {
    }

    void add(int key)
    {
        int index = key % BUCKET_SIZE; // k mod m
        if (!contains(key))            // if it doesn't contain key -> add it, if it does -> chaining (linked list, it doesnt cover that here)
            bucket[index].push_back(key);
    }

    void remove(int key)
    {
        int index = key % BUCKET_SIZE;
        for (int i = 0; i < bucket[index].size(); i++) // go through linked list and check for key, and erase it.
            if (bucket[index][i] == key)
            {
                bucket[index].erase(bucket[index].begin() + i);
                break;
            }
    }

    bool contains(int key)
    {
        int index = key % BUCKET_SIZE;
        for (int i = 0; i < bucket[index].size(); i++)
            if (bucket[index][i] == key)
                return true;
        return false;
    }
};

// Also a good way to solve this
// https://leetcode.com/problems/design-hashset/discuss/768723/C%2B%2B-Elegant-Solution-Explained-~90-Time-~90-Space

struct Bucket
{
    vector<int> bucket = {};
    void add(int val)
    {
        if (!contains(val))
            bucket.push_back(val);
    }
    bool contains(int val)
    {
        return find(begin(bucket), end(bucket), val) != end(bucket);
    }
    void remove(int val)
    {
        auto pos = find(begin(bucket), end(bucket), val);
        if (pos != end(bucket))
            bucket.erase(pos);
    }
};

class MyHashSet
{
public:
    vector<Bucket> buckets;
    int hashSize;
    MyHashSet(int keySpace = 137)
    {
        hashSize = keySpace;
        buckets.resize(keySpace);
    }
    void add(int key)
    {
        buckets[key % hashSize].add(key);
    }
    void remove(int key)
    {
        buckets[key % hashSize].remove(key);
    }
    bool contains(int key)
    {
        return buckets[key % hashSize].contains(key);
    }
};