#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// {10,20,30,40,50}
// Prefix Sum = {10,30,60,100,150}
// prefix_array[i] = sum(array[0] + array[1] + .... array[i])

void prefix_sum(vector<int> &arr)
{
    // In O(N) complexity.
    int n = arr.size();
    vector<int> prefix_arr(n, 0);
    prefix_arr[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix_arr[i] = arr[i] + prefix_arr[i - 1];
    }

    for (auto x : prefix_arr)
    {
        cout << x << " ";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {10, 20, 30, 40, 50};
    prefix_sum(arr);

    return 0;
}
