#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Rotating an array.

int rotateArray(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    while (low < high)
    {
        // swap
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        // increase low and decrease high to move through the list, get in the middle and return the list bcs (low<high)
        low++;
        high--;
    }

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
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    rotateArray(arr);

    return 0;
}