#include <iostream>
#include <vector>
using namespace std;
// Amazon
// Question -> Given target, form dice combinations that add upto target
// basically permutation with repetition with a different approach

// approach 1
void dice(string p, int target)
{
    // base case
    if (target == 0)
    {
        cout << p;
        cout << endl;
        return;
    }

    // recursive case
    for (int i = 1; i <= 6 && i <= target; i++)
    {
        dice(p + to_string(i), target - i);
    }
}

// approach 2 -> permutation with repetition

void target_sum(vector<int> &arr, int target, int sum, string ans) 
{
    // sum starts from 0 && answer string is empty. (keep appending both as we continue through the program)
    // base case -> sum = target, print the output.
    if (sum == target)
    {
        cout << ans << endl;
        return;
    }
    // Recursive case, go thorugh all numbers.
    for (auto i : arr)
    {
        // if i + sum (0 for now) <= target, then we can add i in our answer list.
        if (sum + i <= target) {
            // add i to our ans list, and do this again for new sum = sum + i.
            target_sum(arr, target, sum + i, ans + to_string(i));
        }
    }
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    int target = 4;

    // both print the same thing
    target_sum(arr, target, 0, "");
    dice("", 4);
    return 0;
}
