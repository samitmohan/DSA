#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Leetcode -> Find all Duplicates (Amazon)

// FIND ALL -> First do cyclic sort and then run for loop to check what's wrong

// 0 1 2 3 4 5 6 7
// 4 3 2 7 8 2 3 1

// index = 1 to N (index = val - 1)

// Sorted
// 0 1 2 3 4 5 6 7
// 1 2 3 4 3 2 7 8

// Repeated = 3 and 2 (wrong indexes)

int findAllDuplicates(vector<int> &arr)
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
    // Find Duplicate Numbers

    for (int index = 0; index < arr.size(); index++)
    {
        if (arr[index] != index + 1)
        {
            // that is the missing number
            answer.push_back(arr[index]);
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};

    return 0;
}