#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
typedef long long ll;

// Question -> 2 sum problem using O(NlogN)
// {1,4,5,6,7,9,9,10} and target = 12 || Answer = (2,3) and (3,3)

// O(N^2);

int twoSum(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << i << "and " << j << endl;
            }
        }
    }
    // if not found
    return -1;
}

// 2 Pointer Approach
// What if we need a better solution -> Binary Search -> O(nlogn)

int twoSum_bs(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int current_sum = arr[low] + arr[high]; // 1 + 10 = 11
        if (current_sum == target)
        {
            cout << low << " and " << high << endl;
        }
        if (current_sum < target)
        {
            low++; // 4+10 = 14
        }
        else
        {           // current_sum > target
            high--; // 4+9
        }
        // Similarly it will keep checking unless 2 and 3 indexes are found
    }
    // if sum not present
    return -1;
}

// What if we need a more better solution -> Using STL -> Pairs.
// Data Structure -> Hash Table (Unordered Set) O(1) Time. -> Overall O(N)

vector<int> twoSum_better(vector<int> &arr, int target)
{
    // Logic
    unordered_set<int> s;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++)
    {
        // x = total sum - current number (the other number)
        int x = target - arr[i];
        // if x present in the set then x and current number = result
        if (s.find(x) != s.end())
        {
            result.push_back(x);
            result.push_back(arr[i]);
            return result;
        }
        // insert the current number inside set (afterwards)
        // shouldn't insert all numbers before searching -> You won't get distinct values (ex -> 2,2 for 4 which is wrong approach)
        s.insert(arr[i]);
    }
    // if target not present, return empty vector
    return {};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {10, 5, 2, 3, -6, 9, 11};
    int target = 4;
    auto p = twoSum_better(arr, target);
    if (p.size() == 0)
    {
        cout << "No pair found";
    }
    else
    {
        cout << p[0] << "," << p[1] << endl;
    }

    return 0;
}
