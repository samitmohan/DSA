#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Find All numbers disappeared in array. (Google Question)
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// all indexes that do not have the correct indexes = return that
// simple cyclic sort.

// nums = [4,3,2,7,8,2,3,1]
// Output = [5,6]

// Tips : If range = 0, N
// every element will be at index = value

//If range = 1, N
// every element will be at index = value - 1;

int FindAllMissing(vector<int> &arr)
{
    int i = 0;
    vector<int> answer;
    while (i < arr.size())
    {
        int correct = arr[i] - 1; // correct index = value - 1;
        if (arr[i] != arr[correct])
        {
            swap(arr[i], arr[correct]);
        }
        else
        {
            i++;
        }
    }
    // Find Missing numbers

    for (int index = 0; index < arr.size(); index++)
    {
        if (arr[index] != index + 1)
        {
            // that is the missing number
            answer.push_back(index + 1);
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
    cout << FindAllMissing(arr);

    return 0;
}
