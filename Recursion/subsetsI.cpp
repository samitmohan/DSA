#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Write a program to input an array & print all possible subsets of the array For eg: for [7, 2, 6] the following subsets are possible
// {}
// {7}
// {2}
// {6} {7,2} {7,6} {2,6} {7,2,6}

/* Solving backtracking problems

Pick a starting point.
while(Problem is not solved)
    For each path from the starting point.
        check if selected path is safe, if yes select it
        and make recursive call to rest of the problem
        before which undo the current move.
    End For
If none of the move works out, return false, NO SOLUTION.

*/

// Vector Example -> 1 2 3  (8 Subsets 2^n)

// Either include and go on (while incrementing the level(index)) or dont include and go on (increment the level(index)).
// Including -> push_back to the array, and go back (backtracking)
//              check other possibilities (pop_back first bcs we're passing by reference and we dont need to change(push_back) in prevs tree)

/*
                        []
            /                       \
          [1]                         []
       /       \                   /      \
   [1,2]          [1]             [2]        []
    /    \       /    \          /   \      /   \
 [1,2,3] [1,2]  [1,3]  [1]     [2,3] [2]   [3]  []

// 8 Subsets -> [], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]

*/

// Vector to store all subsets in the end.

vector<vector<int>> allSubsets;

// We're passing subsets, we need to generate. Basic intuition -> Either number will get added or it wont

// Generate(new subset vector, i (need to check if this index should be included/not), original_vector)
void generate(vector<int> &subset, int i, vector<int> &nums)
{
    // Base condition -> All elements will get consumed and 1 subset will remain containing all numbers.
    if (i == nums.size())
    {
        // Store this subset in pairs in FinalVector (vector<vector> allSubsets)
        allSubsets.push_back(subset);
        // return the vector
        return;
    }

    // Recursion condition

    // 1) Not including ith element -> Subset -> Empty -> Move on to next index (i+1) -> Call same generate function for that.
    generate(subset, i + 1, nums);

    // 2) Including ith element -> Put it in original array(nums) -> Call repeat for next index (i+1)
    subset.push_back(nums[i]);
    generate(subset, i + 1, nums); // Next element

    // 3) Backtracking Step -> Remove recently added element bcs we are calling generate fn again so it will go back and we need to undo the recent change.

    // subset vector -> pass by reference (original val) -> to go back and check if we should include the element, the new currently added val shouldn't be visible.

    // Example -> {1,2} and if we put 3 and call generate function again so the prevs function shouldn't see {1,2,3}, it should only have {1,2}

    // as we go down, changes keep increasing and as we go up, changes are decreasing (look at recursive tree)

    // undo change
    subset.pop_back();
}

int main()
{
    // Input numbers
    int x;
    cin >> x;
    // Nums array of x size
    vector<int> nums(x);
    for (int i = 0; i < x; i++)
    {
        cin >> nums[i];
    }
    // Passing empty vector which will store all our values
    vector<int> empty;
    // Starting index -> 0 -> if no elements are to be included

    generate(empty, 0, nums);

    // Putting all elements of subset in allSubsets in pairs.
    for (auto subset : allSubsets)
    {
        for (auto elem : subset)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}

// LC Answer :

class Solution
{
public:
    // recursive function, i -> ith element -> should be present/not
    // temp vector -> store elements to make a subset
    void solve(int i, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans)
    {
        // base case if reached till end
        if (i == nums.size())
        {
            // store whatever there is in temp in answer
            ans.push_back(temp);
        }
        // recursive case
        // either consider it or not consider it
        // Case 1 : consider it. ('1') [considering 1]
        else
        {
            temp.push_back(nums[i]);
            // recursive function for next element
            solve(i + 1, nums, temp, ans);
            // backtrack to undo our step and do this for next element (last element is reduced)
            temp.pop_back();

            // Case 2: not consider it -> ith element is not present (no push_back(nums[i]))
            // ('') and then solving for others ('', '2'), ('', '3'), ('', '2/3', '3/2') etc
            solve(i + 1, nums, temp, ans);
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, nums, temp, ans);
        return ans;
    }
};