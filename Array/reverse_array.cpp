#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// reverse array without extra space

int reverse(vector<int> &arr)
{
    int temp;
    // starting point
    int i = 0;
    // ending point (last number)
    int j = arr.size() - 1;
    while (i < j)
    {
        // swap
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        // incrementing the list until all are reversed
        i++;
        j--;
    }

    // display
    for (auto elem : arr)
    {
        cout << elem << " ";
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {1, 2, 3, 4, 5};
    reverse(arr);

    return 0;
}
