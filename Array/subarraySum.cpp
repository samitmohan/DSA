#include <iostream>
#include <vector>
using namespace std;

// time complexity -> O(N^2) (Brute force method of subarray sum problem)

using namespace std;
typedef long long ll;

int subarraySum(vector<int> &arr, int target)
{
    int currsum;
    for (int i = 0; i < arr.size(); i++)
    {
        currsum = arr[i];
        // sub array
        for (int j = i + 1; j <= arr.size(); j++)
        {
            if (currsum == target)
            {
                cout << "Sum found between indexes : " << i << " to " << j - 1 << "\n";
            }
            // if subarray sum > target or list has ended (j=arr.size()) then break
            if (currsum > target || j == arr.size())
            {
                break;
            }

            // sum incrementing as we progress through array
            currsum = currsum + arr[j];
        }
    }

    // if no subarray found
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {1, 2, 3};
    subarraySum(arr, 3);

    return 0;
}
