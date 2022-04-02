#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/rotate-image/

// Leetcode Medium Question
void rotate(vector<vector<int>> &matrix)
{
    // Step 1 -> Transpose Vector.
    // Step 2 -> Reverse that Vector = Answer

    // Transpose -> row becomes col, col becomes row.
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i + 1; j < matrix.size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reversing the tranposed vector (Just like how you reverse an array -> Two Pointer Method)
    for (int i = 0; i < matrix.size(); i++)
    {
        // Reversing row.
        int low = 0, high = matrix[i].size() - 1;
        while (low < high)
        {
            // Swap first and last row.
            swap(matrix[i][low], matrix[i][high]);
            // Two Pointer
            low++;
            high--;
        }
    }

    // Printing
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);

    return 0;
}