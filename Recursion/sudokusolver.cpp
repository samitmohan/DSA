#include <bits/stdc++.h>
using namespace std;

// Problem Link -> https://leetcode.com/problems/sudoku-solver/

// tip, traverse row -> arr.size(); traverse col -> arr[0].size();

// sudoku solver

// is it safe?
// cases -> 1) number shouldn't be present in the row
//          3) number shouldn't be present in the column
//          3) number shouldn't be present in 3*3 subgrid

bool isSafe(vector<vector<int>> &arr, int row, int col, int value)
{
    // row filled
    for (int i = 0; i < arr.size(); i++)
    {
        // if already filled
        if (arr[i][col] == value)
        {
            return false;
        }
    }
    // column filled
    for (int i = 0; i < arr[0].size(); i++)
    {
        if (arr[row][i] == value)
        {
            return false;
        }
    }
    // subgrid filled.
    // trick -> check for subgrid starting point -> (row/3) * 3 and (col/3) * 3 for 3 * 3 submatrix (9*9 grid)
    row = (row / 3) * 3;
    col = (col / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i + row][j + col] == value)
            // why arr[i + row][j + col]
            // lets say r = 3, c = 6, and 3,6 -> empty
            // now we have to check for 3,7. i = 0, j = 1 after first iteration.
            // arr[0 + 3][1 + 6] = arr[3][7], then check for arr[3][8] then for arr[4][6] and so on..
            {
                return false;
            }
        }
    }
    // if all fails -> then we can place the value there its empty
    return true;
}

// display function

void display(vector<vector<int>> &arr)
{
    // for every row
    for (int i = 0; i < arr.size(); i++)
    {
        // for every column
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        // space after every line
        cout << "\n";
    }
}

void sudoku(vector<vector<int>> &arr, int row, int col)
{
    // base case -> if row = arr.size() - 1 (8) and col = arr.size() = 9)
    if (row == arr.size() - 1 && col == arr.size())
    {
        display(arr);
        cout << "\n";
        return;
    }

    // edge cases
    // 1) if column gets exhausted, move to next row, col = 0.
    if (col == arr[0].size())
    {
        row++;
        col = 0;
    }

    // 2) if value is already filled, move to next column. (solve sudoku for next)
    if (arr[row][col] != 0)
    {
        sudoku(arr, row, col + 1);
    }

    else
    {
        // recursive case
        for (int value = 1; value <= 9; value++)
        {
            // check if it's safe to put value there (empty or not)
            if (isSafe(arr, row, col, value))
            {
                // place the value there for now
                arr[row][col] = value;
                // recursive function to place values for all other places
                sudoku(arr, row, col + 1);
                // Backtracking step
                // IF in the future value doesn't solve the sudoku, we have messed up at some place
                // backtrack and change the values to 0 until we find that messed up value and try for some other possibility
                arr[row][col] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                               {6, 0, 0, 1, 9, 5, 0, 0, 0},
                               {0, 9, 8, 0, 0, 0, 0, 6, 0},
                               {8, 0, 0, 0, 6, 0, 0, 0, 3},
                               {4, 0, 0, 8, 0, 3, 0, 0, 1},
                               {7, 0, 0, 0, 2, 0, 0, 0, 6},
                               {0, 6, 0, 0, 0, 0, 2, 8, 0},
                               {0, 0, 0, 4, 1, 9, 0, 0, 5},
                               {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    // solve for arr, row, column
    sudoku(arr, 0, 0);

    return 0;
}

// Output
// 5 3 4 6 7 8 9 1 2
// 6 7 2 1 9 5 3 4 8
// 1 9 8 3 4 2 5 6 7
// 8 5 9 7 6 1 4 2 3
// 4 2 6 8 5 3 7 9 1
// 7 1 3 9 2 4 8 5 6
// 9 6 1 5 3 7 2 8 4
// 2 8 7 4 1 9 6 3 5
// 3 4 5 2 8 6 1 7 9

/*
LC Solution
class Solution
{
public:
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                // if it has blank space
                if (board[i][j] == '.')
                {
                    for (char value = '1'; value <= '9'; value++)
                    {
                        if (isSafe(board, i, j, value))
                        {
                            // is isSafe -> place value
                            board[i][j] = value;
                            if (solve(board) == true) // if we found answer then no need further
                                return true;
                            else
                                // backtrack
                                board[i][j] = '.'; // else removing the char value
                        }
                    }
                    return false; // tho its empty but we cant enter any value return false
                }
            }
        }
        return true;
    }

    bool isSafe(vector<vector<char>> &board, int row, int col, char value)
    {
        for (int i = 0; i < board.size(); i++)
        {
            // for val check in row, row is stable
            if (board[row][i] == value)
            {
                return false;
            }
            // for val check in col, col is stable
            if (board[i][col] == value)
            {
                return false;
            }
            // for the 3x3 matrix
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value)
            {
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};
*/
