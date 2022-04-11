#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// https://leetcode.com/problems/shift-2d-grid/

int shiftGrid(vector<vector<int>> &grid, int k)
{
    int rows = grid.size();
    int columns = grid[0].size();
    for (; k > 0; k--)
    {
        int previous = grid[rows - 1][columns - 1]; // last element
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                swap(grid[i][j], previous); // swap first with last
            }
        }
    }

    return grid;
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    shiftGrid(grid, 1);
}