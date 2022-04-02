// A knight can move two squares vertically and one square horizontally
// or two squares horizontally and one square vertically.

#include <bits/stdc++.h>
using namespace std;

// Similar to N Queens

// display array
void display(vector<vector<int>> &board)
{
    // row traversal
    for (int i = 0; i < board.size(); i++)
    {
        // board[0].size = same row, column traversal
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
    }
    cout << "\n";
}

// checking that board doesn't run out of rows / cols
bool isValid(vector<vector<int>> &board, int row, int col)
{
    if (row >= 0 && row < board.size() && col >= 0 && col < board.size())
    {
        return true;
    }
    return false;
}

// isSafe function

bool isSafe(vector<vector<int>> &board, int row, int col)
{
    // check for 2 up 1 left
    if (isValid(board, row - 2, col - 1))
    {
        if (board[row - 2][col - 1])
        {
            return false;
        }
    }

    // 2 up 1 right
    if (isValid(board, row - 2, col + 1))
    {
        if (board[row - 2][col + 1])
        {
            return false;
        }
    }

    // 1 up 2 left
    if (isValid(board, row - 1, col - 2))
    {
        if (board[row - 1][col - 2])
        {
            return false;
        }
    }

    // 1 up 2 right
    if (isValid(board, row - 1, col + 2))
    {
        if (board[row - 1][col + 2])
        {
            return false;
        }
    }
    // else
    return true;
}

void kKnight(vector<vector<int>> &board, int row, int col, int knights)
{
    // base case -> all knights exhausted
    if (knights == 0)
    {
        display(board);
        cout << "\n";
        return;
    }

    // if board size reachd
    if (row == board.size() - 1 && col == board.size())
    {
        return;
    }

    // if column ended reached, call knight for next row

    if (col == board.size())
    {
        kKnight(board, row + 1, 0, knights);
        return;
    }

    if (isSafe(board, row, col))
    {
        // place knight (represented as 1)
        board[row][col] = 1;
        // recursive call for next knight(next col) and reduce the size by 1
        kKnight(board, row, col + 1, knights - 1);
        // backtrack (if you mess up in the past, values become 0 and you try again for other possibilities)
        board[row][col] = 0;
    }

    // do this for every combination on board not just 1.
    kKnight(board, row, col + 1, knights);
}

int main()
{
    int n = 4;
    // cin >> n;
    // board of 4*4 with 0s filled
    vector<vector<int>> board(n, vector<int>(4, 0));
    kKnight(board, 0, 0, 4); // starting row = 0

    return 0;
}