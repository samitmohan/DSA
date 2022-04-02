#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1 2 3 4 5 (5 = n)

void printIncreasing(int n)
{
    // base case
    if (n == 0)
        return;
    // apna aage ka sab print kardo 1 2 3 4
    // f(5) -> f(4) -> f(3) -> f(2jkkk) -> f(1) -> f(0) (base case, return from here)
    printIncreasing(n - 1);
    // uske baad mujhe print kardena 1 2 3 4 5
    cout << n << " ";
}

// you can do the same for opposite, question -> print 5 4 3 2 1
// print the first one and then pass the function to n-1 to print the other numbers
// if (n == 0) return; print(n); f(n-1);

void printDecreasing(int n)
{
    // base case
    if (n == 0)
        return;
    cout << n << " ";
    printDecreasing(n - 1);
}


// good way to understand call stack -> see notebook. (recursive tree)

void fun(int n, int level)
{
    if (n <= 2)
    {
        cout << "Base " << n << " @ " << level << "\n";
        return;
    }
    cout << "Pre " << n << " @ " << level << "\n";
    fun(n - 1, level + 1);
    cout << "In " << n << " @ " << level << "\n";
    fun(n - 2, level + 1);
    cout << "Post " << n << " @ " << level << "\n";
}

// Substring
// All subset without return type. (10,20,30) - " , 30, 20, 20 30, 10, 10 30, 10 20, 10 20 30"

void all_subset_without_return_type(vector<int> &arr, int idx, string ans) {
    // base case
    if (idx == arr.size()) {
        cout << ans << "\n";
        return;
    }
    // recursive case
    // 2 options -> include / not include 
    // not include -> index will always increase, ans will stay same (id+1, ans)
    all_subset_without_return_type(arr, idx + 1, ans);
    // include -> index will increase by 1, ans will increase by arr[id] 
    // in c++ to add number + string, convert it to string (to_string)
    all_subset_without_return_type(arr, idx + 1, ans + to_string(arr[idx]) + " ");
}


// Another way to do this -> with return type
// Just add me in front of whatever you already have -> Recursive case. Return type.

vector<string> all_subset_with_return_type(vector<int> arr, int idx) {
    // base case 
    if (idx == arr.size()) 
    {
        // add empty string
        vector<string> base;
        base.push_back("");
        return base;
    }

    // Whatever is there, let it be -> store it.
    vector<string> ans = all_subset_with_return_type(arr, idx + 1);
    // Just let it be like that and then add myself to everything.
    // STEP 1
    vector<string> my_ans;
    // Past answer -> add to my_ans 
    for (string elem : ans) {
        my_ans.push_back(elem);
    }
    // STEP 2 -> Add my value before every answer of past (my_ans) 
    // my_ans + arr[id]
    for (string elem : ans) {
        my_ans.push_back(to_string(arr[idx]) + " " + elem);
    }

    return my_ans;


}

void allsubsets() 
{
    vector<int> arr = {10,20,30};
    // without return type
    // all_subset_without_return_type(arr, 0, "");

    // with return type
    vector<string> ans = all_subset_with_return_type(arr, 0); // no passing of string, it'll return and store it in ans
    // print 
    for (string elem : ans)
    {
        cout << elem << "\n";
    }

}

int main()
{
    // printIncreasing(5);
    // printDecreasing(5);
    // fun(5, 0);
    allsubsets();


    return 0;
}

// Questions -> 5 length array, how many 3 length subset can you form
// in the above question, 3 length array, how many 3 length subsets you form -> 3 (20 30, 10 30, 10 20)
// How do we know this?  -> nCr -> n = length of array, r = length of subsets you want to form.
// Answer to original question -> 5C3