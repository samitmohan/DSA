#include <bits/stdc++.h>
using namespace std;

// Permutation without repetition (Remember This)

// Ans -> 1,3 | 3,1 | 4

void target_sum(vector<int> arr, int target, int sum, string ans, vector<int> &visited)
{
    // Base Case
    if (sum == target)
    {
        cout << ans << endl;
        return;
    }

    // Recursive Case

    // When going -> mark it, when coming -> unmark (preoreder check, postorder uncheck)
    // Go from 0 -> arr.size()
    for (int i = 0; i < arr.size(); i++)
    {
        // Visited array shouldn't be filled (condn)
        if (sum + arr[i] <= target && visited[i] == 0)
        {
            visited[i] = 1; // flag
            target_sum(arr, target, sum + arr[i], ans + to_string(arr[i]), visited);
            // Backtracking
            visited[i] = 0;
        }
    }
}


int main()
{
    vector<int> arr = {1,2,3,4};
    vector<int> visited;
    int target = 4;
    // initially idx = 0
    target_sum(arr, target, 0, "", visited);
    return 0;
}
