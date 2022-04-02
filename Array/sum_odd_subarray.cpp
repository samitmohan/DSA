#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Using Prefix Sum

int sumOddLengthSubarrays(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;

    vector<int> presum(n + 1, 0);
    presum[0] = 0;
    presum[1] = arr[0];
    for (int i = 1; i < n; i++)
    {
        // Presum = current element + 1
        // Keep on adding the prefix sum elements with the array elemnts to get the new prefix sum element
        presum[i + 1] = presum[i] + arr[i];
    }

    // [0,0,0,0] = [0,1,0,0] = [0,1,3,6,10, some garbage value]
    // [1,2,3,4] = Prefix Sum Array = [1,3,6,10]

    // Print prefix sum array
    for (int x : presum)
    {
        cout << x << " ";
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
        // go through all the odd sub arrays
        for (int j = i; j < n; j += 2)
        {
            cout << j << " ";
            sum += presum[j + 1] - presum[i];
        }
    }

    cout << endl;

    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {1, 4, 2, 5, 3};
    cout << sumOddLengthSubarrays(arr);

    return 0;
}