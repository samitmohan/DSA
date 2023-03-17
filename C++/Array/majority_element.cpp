#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

// https://leetcode.com/problems/majority-element/solution/
// Majority Elements - element which is present MORE than n/2 in the array where n is the size
// Bruteforce approach -> majority count = n/2. Go through each number and keep a count. If any of the number's count > majority count. That number is the answer. O(N^2) Solution

int solve(vector<int> &arr)
{
    int majorityCount = arr.size() / 2;
    for (auto i : arr)
    {
        int count = 0;
        for (auto j : arr)
        {
            if (j == i)
            {
                count++;
            }
        }
        if (count > majorityCount)
        {
            return i;
        }
    }
    return -1;
}

// Better solution (Using HashMap -> O(logN)) -> Store key(number) value(frequency of the number)
// if value > length/2, then return the key (majority element at this point)

int majority(vector<int> &arr)
{
    map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++; // count (maintain frequency for all the numbers);
    }
    for (auto i : mp)
    {
        if (i.second > (arr.size() / 2))
        {
            return i.first;
        }
    }
    // if no majority element
    return -1;
}

// Better way -> O(N) using voting algorithm

// Boyer Moore Majority Element

/*
{2,1,2,2,2,1,1,3,2}

Set canditate = 0 , count = 0.
Iterate over the array, canditate = 2, count = 1
Comparte the number we're looking at with candidate, if they're different = count-- 
AND update canditate to current number (1 in this case) if count = 0

(if count = 0, make element = new canditate)

Canditate = 1, count = 0
Now canditate = 1, element = 1, so count++ (1)
Canditate = 1, count = 1

Again 2, current number = 2, canditate = 1, element!= canditate => count--;

Canditate = 2, count = 0
Now canditate = 2, element = 2, so count++ (1)
Canditate = 2, count = 1

Again 2, count++ (since current element = canditate); count = 2
Again 2, count++, count = 3

Now 1 -> count--, canditate = still 2, count = 2
1 again -> count--, canditate = still 2, count = 1

Now 3 -> count-- (count = 0 -> make curr element the new canditate)
candidate = 3, count = 0.
current element = canditate, count++, count = 1, canditate = 3.

Now 2. Canditate = 3, count = 0 (count--) since count = 0, make current element the new canditate
Canditate = 2 and also increment the count if curr = canditate, count = 1.

In the end, canditate = 2, count = 0

return canditate (majority element)

*/
int majority_element_boyer_moore(vector<int> &arr)
{
    int canditate = 0;
    int count = 0;
    for (int element : arr)
    {
        if (count == 0)
        {
            // canditate becomes current element we're looking at
            canditate = element;
        }
        if (element == canditate)
        {
            count++;
        }
        else
            count--;
    }

    // Majority Element
    return canditate;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {6, 5, 5};

    return 0;
}