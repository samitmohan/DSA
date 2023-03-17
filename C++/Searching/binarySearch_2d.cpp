#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

/* BS in 2D Arrays
Row Col Index = 0 1 2
Target = 91

18 9 12
36 -4 91
44 33 16

for row = 0; row<n; row++;
    for col = 0; col < n; col++;
        if arr[row][col] == target:
            return found [1,2]

    return -1;

Time Complexity -> O(N^2)
*/

/* Matrix sorted in a row wise and col wise manner

10 20 30 40
15 25 35 45
28 29 37 49
33 34 38 50

every col/row is sorted

HINT -> Sorted. Use Binary Search

*/

int search(vector<vector<int>> &matrix, int target)
{
    int row = 0;
    int col = matrix.size() - 1;
    // Condition
    while (row < matrix.size() && col >= 0)
    {
        if (matrix[row][col] == target)
        {
            // found
            return true;
        }
        if (matrix[row][col] < target)
        {
            row++;
        }
        else
        {
            // elem > target
            col--;
        }
    }
    // if not found
    return -1;
}

int main()
{
    vector<vector<int>> matrix = { {10, 20, 30, 40},
                                   {15, 25, 25, 45},
                                   {28, 29, 37, 49},
                                   {33, 34, 38, 50},};
    // cout << search(matrix, 100);

    return 0;
}
