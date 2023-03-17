#include <bits/stdc++.h>
using namespace std;

// take a board of 4*4 filled with 0s
// Place 4 queens in the board such that the queens don't kill themselves.
// Display all possibilities

// just like sudoku problem.
// if 1 queen placed in a specific row, any other queen cannot be placed in the same row so don't even bother checking just call nqueen(row+1, col)
// Backtrack after finding solution to find other possibilites if messed up somewhere

// Output
// 0 1 0 0
// 0 0 0 1
// 1 0 0 0
// 0 0 1 0

// AND

// 0 0 1 0
// 1 0 0 0
// 0 0 0 1
// 0 1 0 0

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

bool isSafe(vector<vector<int>> &board, int row, int column)
{
    // 3 options -> in notebook. Check for up, upright, upleft
    // Checking for up -> row decrease, column same. i = row (till i >= 0 (board starts))
    for (int i = row; i >= 0; i--)
    {
        if (board[i][column] == 1)
        {
            // can't be placed
            return false;
        }
    }

    // Checking for upright -> row decrease, column increase. i = row, j = column
    // i >= 0 and j will go till end of column of that row -> board[0].size() and ++
    for (int i = row, j = column; i >= 0 && j < board[0].size(); i--, j++)
    {
        if (board[i][j] == 1)
        {
            // can't be placed
            return false;
        }
    }

    // Checking for upleft -> row decrease, column decrease.
    // i >= 0 and j >= 0 for upleft
    for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            // can't be placed
            return false;
        }
    }
    // else it can be placed
    return true;
}

void nQueen(vector<vector<int>> &board, int row)
{
    // base case -> if row = board size
    if (row == board.size())
    {
        display(board);
        cout << "\n";
        return;
    }

    // recursive case
    for (int col = 0; col < board[0].size(); col++)
    {
        if (isSafe(board, row, col))
        {
            // place queen (represented as 1)
            board[row][col] = 1;
            // recursive for next row since no 2 queens can be placed in same row.
            nQueen(board, row + 1);
            // backtrack (if you mess up in the past, values become 0 and you try again for other possibilities)
            board[row][col] = 0;
        }
    }
}

int main()
{
    int n = 4;
    // cin >> n;
    // board of 4*4 with 0s filled
    vector<vector<int>> board(n, vector<int>(4, 0));
    nQueen(board, 0); // starting row = 0

    return 0;
}

// Time Complexity ? -> O(N!) How to reduce -> DP.

/*

// https://leetcode.com/problems/n-queens/
// Leetcode -> N Queens I
class Solution
{
public:
    bool ifPossible(int n, int row, int col, vector<string> &v)
    {
        for (int i = row - 1, j = col; i >= 0; i--)
        {
            if (v[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (v[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (v[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void help(int n, int row, vector<vector<string>> &ans, vector<string> &s)
    {
        if (row == n)
        {
            ans.push_back(s);
            return;
        }
        for (int j = 0; j < n; j++)
        {
            s[row][j] = 'Q';
            if (ifPossible(n, row, j, s))
            {
                help(n, row + 1, ans, s);
            }
            s[row][j] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> s;
        for (int i = 0; i < n; i++)
        {
            string str;
            for (int j = 0; j < n; j++)
            {
                str = str + '.';
            }
            s.push_back(str);
        }
        vector<vector<string>> ans;
        help(n, 0, ans, s);
        return ans;
    }
};

-----------------------------------------------------------------------------------------------------

// https://leetcode.com/problems/n-queens-ii/submissions/
// Leetcode -> N Queens II

// only difference -> just keep a global variable count = 0 and when you find answer (reach base case) instead of ans.push_back(s) you do count++ and return count in end instead of ans string
class Solution
{
public:
    int count = 0;
    bool ifPossible(int n, int row, int col, vector<string> &v)
    {
        for (int i = row - 1, j = col; i >= 0; i--)
        {
            if (v[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (v[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (v[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void help(int n, int row, vector<vector<string>> &ans, vector<string> &s)
    {
        if (row == n)
        {
            count++;
            return;
        }
        for (int j = 0; j < n; j++)
        {
            s[row][j] = 'Q';
            if (ifPossible(n, row, j, s))
            {
                help(n, row + 1, ans, s);
            }
            s[row][j] = '.';
        }
    }
    int totalNQueens(int n)
    {
        vector<string> s;
        for (int i = 0; i < n; i++)
        {
            string str;
            for (int j = 0; j < n; j++)
            {
                str = str + '.';
            }
            s.push_back(str);
        }
        vector<vector<string>> ans;
        help(n, 0, ans, s);
        return count;
    }
};
*/
