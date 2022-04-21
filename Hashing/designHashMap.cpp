#include <bits/stdc++.h>
using namespace std;

// Problem Link -> https://leetcode.com/problems/design-hashset/submissions/

// Using Array / Vector -> Not a proper solution since it uses O(N) to search where as hashmap works in O(1)

class MyHashSet {
private:
    vector<int> arr;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        auto i = find(arr.begin(), arr.end(), key);
        if (i == arr.end()) {
            arr.push_back(key);
        }
    }
    
    void remove(int key) {
        auto i = find(arr.begin(), arr.end(), key);
        if (i != arr.end()) {
            arr.erase(i);
        }
    }
    
    bool contains(int key) {
        auto i = find(arr.begin(), arr.end(), key);
        if (i == arr.end()) {
            return false;
        }
        return true;
    }
};


// https://leetcode.com/problems/design-hashset/discuss/1968085/No-cheating-oror-C%2B%2B-oror-Easy-to-understand

// https://leetcode.com/problems/design-hashset/discuss/1968110/C%2B%2B-2d-vector-and-mod

// https://leetcode.com/problems/design-hashset/discuss/773006/C%2B%2B-3-Approaches
