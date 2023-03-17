#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// What is recursion? Find base case, find the problem and sub problem, generalize the solution.

// Triangles question.
// n = 1, 1 triangle. n = 2, 3 triangles, n = 3, 6 triangles, so on so forth.
// if i have triangles(5) and i want to calculate triangles(6) i just need to add 6 to triangles(5)


int triangles(int n)
{
    // Base Case, n = 1
    if (n == 1)
    {
        return 1;
    }
    // recursive case -> n + triangles(n-1);
    return triangles(n - 1) + n;
}

// Power question. (a^b)

int power(int a, int b)
{
    // Base case.
    if (b == 0)
    {
        return 1;
    }
    // find a^b-1(sub problem) and multiply a to get a^b (problem)
    return power(a, b - 1) * a;
}

// Matrix question.
/*
Write a function that takes two inputs n, m and outputs number of unique paths from the top left corner to bottom right corner of n*m grid
you can only move down or right 1 unit at a time.
*/

int matrix(int x, int y)
{
    // Base Case
    if (x == 1 or y == 1)
    {
        return 1;
    }
    // return rows(x-1) + columns(y-1) = count of unique paths till that point, and the add 1 to it. (answer)
    return matrix(x - 1, y) + matrix(x, y - 1);
}

// Print 1 2 3 4 5 using recursion (head recursion)



void print(int n)
{
    // Base Condition
    if (n == 5)
    {
        cout << 5;
        return;
    }

    // Recursive Case
    cout << n << " ";
    // Last call -> Tail Recursion (does not call another function)
    print(n + 1);
}

// Fibonacci
int fib(int n)
{
    // Base Case
    if (n < 2)
    {
        return n;
    }
    // Recursive Case -> previous number + previous_previous number
    return fib(n - 1) + fib(n - 2);
}

int factorial(int n)
{
    // Base Case
    if (n <= 1)
    {
        return 1;
    }
    // factorial(5) calls factorial(4), which calss factorial(3) .... factorial(1)[Base Case] = 1.
    // not tail recursion
    return factorial(n - 1) * n;
}

// Binary Search using Recursion

int search(vector<int> &arr, int target, int low, int high)
{

    if (low > high)
    {
        // no answer (Base Case)
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
    {
        // answer found
        return mid;
    }

    if (arr[mid] > target)
    {
        // answer is in left side (high--)
        search(arr, target, low, mid - 1);
    }

    // lies on right side (low++)
    return search(arr, target, mid + 1, high);
}

// N to 1

void printIncreasing(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << endl;
    printIncreasing(n - 1);
}

// 1 to N

// pass 5, print 5 and then you call recursion call. (prevs)
// pass 5, print this at end, first give me the answer for  1 2 3 4

void fun2(int n)
{
    if (n == 0)
    {
        return;
    }
    printIncreasing(n - 1);
    cout << n << endl;
}

// Sum of n numbers

int sum_recursion(int n)
{
    if (n < 1)
    {
        return n;
    }
    return sum_recursion(n - 1) + n;
}

// Sum of digits
// 1 3 4 5 = 1 + 3 + 4 + 2 = 10.

// complexity -> log N
int sum_of_digits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n % 10) + sum_of_digits(n / 10);
}

// Reverse a number

int sum = 0;
void reverse1(int n)
{
    if (n == 0)
    {
        return;
    }
    int remainder = n % 10;
    sum = sum * 10 + remainder;
    reverse1(n/10);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    reverse1(1234);
    cout << sum << endl;

    return 0;
}
