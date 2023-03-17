#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/spiral-matrix/
// Leetcode Medium

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Move inwards.
// Output: [1,2,3,6,9,8,7,4,5]
//
// Going from begin col to end col, beg row to end row, end col to beg col, end row to beg row.
// To accomplish this -> Have counters / boundaries. Pointers that keep track of these beg/end row/col
// Move the boundary up 1 [1,2,3,6,9-]

// [
//     [ 1, 2, 3]
//     [ 4, 5, 6]
//     [ 7, 8, 9]
// ]

int spiralOrder(vector<vector<int>> &matrix)
{
    // Keep a result vector to store.
    vector<int> result;
    // If matrix empty; return empty.
    if (matrix.size() == 0)
        return result;

    // Boundaries / Counters
    int rowBegin = 0;
    int rowEnd = matrix.size() - 1;
    int columnBegin = 0;
    int columnEnd = matrix[0].size() - 1;

    // Iterating through the matrix.
    while (rowBegin <= rowEnd && columnBegin <= columnEnd)
    {
        // Traversing first row and access column values.
        for (int i = columnBegin; i <= columnEnd; i++)
        {
            // Add it to output array
            result.push_back(matrix[rowBegin][i]);
        }
        // We already did everything in the first row
        rowBegin++;

        // End of column boundary (3 to 9)

        for (int i = rowBegin; i <= rowEnd; i++)
        {
            result.push_back(matrix[i][columnEnd]);
        }

        columnEnd--; // last column and first row ended

        // What we have right now
        // [4,5]
        // [7,8]

        if (rowBegin <= rowEnd)
        {
            // go from end col to
            for (int i = columnEnd; i >= columnBegin; i--)
            {
                result.push_back(matrix[rowEnd][i]);
            }
        }

        rowEnd--;

        if (columnBegin <= columnEnd)
        {
            // going up now, i = rowEnd to beginning row
            for (int i = rowEnd; i >= rowBegin; i--)
            {
                result.push_back(matrix[i][columnBegin]);
            }
        }

        columnBegin++;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    spiralOrder(matrix);

    return 0;
}

// Spiral Matrix 2

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int top = 0, left = 0, right = n - 1, bottom = n - 1;
    int k = 1;
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            ans[top][i] = k;
            k++;
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans[i][right] = k;
            k++;
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans[bottom][i] = k;
                k++;
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans[i][left] = k;
                k++;
            }
            left++;
        }
    }
    return ans;
}