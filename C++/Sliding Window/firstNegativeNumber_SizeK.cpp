// https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/

/* Documentation
Given an array and a positive integer k, find the first negative integer for each window(contiguous subarray) of size k.
If a window does not contain a negative integer, then print 0 for that window.

12,-1,-7,8,-15,30,16,8
Answer = -1 -1 -7 -15 -15 0
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;
typedef long long ll;

// Bruteforce

void firstNegativeNum(vector<int> &arr, int k)
{
    // every window in the array
    bool found = false;
    for (int i = 0; i < arr.size() - k; i++)
    {
        // in the window
        for (int j = i; j < i + k; j++)
        {
            if (arr[j] < 0)
            {
                cout << arr[j] << " ";
                found = true;
                break;
            }
        }
    }
    if (!found)
    {
        cout << "0 ";
    }
}

// Using Queue (sliding window)
void firstNegativeInteger(vector<int> &arr, int k)
{
    // create Deque (FIFO)
    deque<int> q;

    // traverse the first window
    for (int i = 0; i < k; i++)
    {
        // if the current element is negative = add to the end of deque
        if (arr[i] < 0)
            q.push_back(i);
    }

    // if deque is not empty, front of deque is the index of first negative element
    if (!q.empty())
        cout << arr[q.front()] << " ";
    else
        // else there is no negative element in this window
        cout << "0 ";

    // slide window
    for (int i = k; i < arr.size(); i++)
    {
        // remove previous window elements
        while (!q.empty() && q.front() <= (i - k))
        {
            q.pop_front();
        }

        // if the current element is negative, add it to the deque
        if (arr[i] < 0)
            q.push_back(i);

        // if deque is not empty, front of deque is the index of first negative element
        // else there is no negative element in this window
        if (!q.empty())
            cout << arr[q.front()] << " ";
        else
            cout << "0 ";
    }

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 8};
    firstNegativeInteger(arr, 3);

    return 0;
}
