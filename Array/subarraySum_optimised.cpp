#include <iostream>
#include <vector>
using namespace std;

// time complexity -> O(N)
// i = right pointer, start = left pointer.

int subArraySum(int a[], int len, int sum)
{
    // Current sum = Value of first element.

    int current_sum = a[0];
    // Starting point = 0; ( left pointer )
    int start = 0;

    // Looping through array, increasing right pointer (i++)

    for (int i = 1; i <= len; i++)
    {
        // Current sum exceeds actual sum, remove the starting elements ( left pointer and also increment left pointer by 1 )
        while (current_sum > sum and start < i - 1)
        {
            current_sum = current_sum - a[start];
            // incrementing left pointer.
            start++;
        }

        // If current sum = actual sum, return true
        if (current_sum == sum)
        {
            cout << "Sum found between indexes " << start << " to " << i - 1 << endl;
            return 1;
        }

        // sum of array, keep adding right pointer to the current sum until array ends.
        if (i < len)
        {
            current_sum = current_sum + a[i];
        }
    }

    // If no subarray
    cout << "No subarray found";
    return 0;
}

int main()
{
    int a[] = {1, 3, 2, 5, 1, 1, 2, 3};
    int len = sizeof(a) / sizeof(a[0]);
    int sum = 8;
    subArraySum(a, len, sum);
    // Printing the list.
    cout << "Array: ";
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << ", ";
    }
    return 0;
}
