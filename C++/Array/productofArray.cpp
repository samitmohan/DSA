#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// Famous interview question -> Product of array except self
// sum of prod of all numbers in the array except itself
// Given array -> [1,2,3,4];
// Answer array -> [24,12,8,6]

// Bruteforce Solution -> Get total multiplication value and divide the item.

// O(n)
void productexceptSelfBruteforce(vector<int> &arr)
{
    int product = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        // multiplication
        product = product * arr[i];
    }

    for (int i = 0; i < arr.size(); i++)
    {
        // divide by itself
        arr[i] = product / arr[i];
    }

    // Print the vector

    for (auto elem : arr)
    {
        cout << elem << " ";
    }
}

// Problem with the above soln -> if any number in arr = 0; wont work.
// To solve this we can add a zero counter and ignore that

// Not using the divide operator (O(N))

// Given array -> {1,2,3,4}
// Answer -> {24,12,8,6}

void productOfarrayExceptSelf(vector<int> &arr)
{

    // defining left and right array of the same size as arr
    vector<int> left_products(arr.size());
    vector<int> right_products(arr.size());

    // output array where left*right happens
    vector<int> output_arr(arr.size());

    // initially there is nothing towards left of left_array and right of right_array so set them to 1
    left_products[0] = 1;
    right_products[arr.size() - 1] = 1;

    // Left array
    // (starts from index 1 bcs we have set index 0 to 1) {1,2,3,4} -> {1,1,2,6}
    for (int i = 1; i < arr.size(); i++)
    {
        // arr[i-1] = original array elements, left_products[i-1] = sum of products till now in the new array
        left_products[i] = arr[i - 1] * left_products[i - 1];
    }

    // Right array
    // (starts from arr.size()-2 bcs we have set last index (arr.size()-1) to 1) {4,3,2,1} -> {24, 12, 4, 1}
    // going till index 0 from right (i--)
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        // arr[i+1] = original array elements, right_products[i+1] = sum of products till now in the new array
        right_products[i] = arr[i + 1] * right_products[i + 1];
    }

    // left * right {24,12,8,6}
    for (int i = 0; i < arr.size(); i++)
    {
        output_arr[i] = left_products[i] * right_products[i];
    }

    // printing
    for (auto elem : output_arr)
    {
        cout << elem << " ";
    }
}

// for even better, use less space -> remove left and right, just use output_arr and multiply it to itself
// R = 1;
// output_arr[i] = output_arr[i] * R;
// R = R * arr[i];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {1, 2, 3, 4};
    // productexceptSelfBruteforce(arr);
    // productOfarrayExceptSelf(arr);

    return 0;
}
