#include <iostream>
#include <vector>
#define ll long long

using namespace std;

// Amazon Question
// Given an array of duplicates except 2 non duplicates, find the non duplicates
void nonDuplicates(vector<int> &arr)
{
    int ans = 0;
    // finding non duplicates
    for (int elem : arr)
    {
        ans = (ans ^ elem);
    }
    // 0100 (8,12)
    // finding the ON BIT(3rd digit)
    int a = ans;
    int count = 0;
    while (a % 2 != 1)
    {
        a = a / 2;
        count++;
    }

    int mask = (1 << count);
    int ans1 = 0;
    for (int elem : arr)
    {
        if ((mask & elem) == 0)
        {
            ans1 = (ans1 ^ elem);
        }
    }
    int ans2 = (ans ^ ans1);
    cout << ans1 << " " << ans2 << endl;
}

int main()
{
    vector<int> arr = {2, 45, 65, 8, 65, 2, 45, 12}; // 8 12
    nonDuplicates(arr);
}