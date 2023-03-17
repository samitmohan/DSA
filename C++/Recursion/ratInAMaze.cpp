#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void ratInMaze(int sr, int sc, int er, int ec, string ans)
{
    // Base Case
    if (sc == ec && sr == er)
    {
        // all consumed
        cout << ans << endl;
        return;
    }
    if (sc + 1 <= ec)
    {
        // column+1 -> Horizontally Move
        ratInMaze(sr, sc + 1, er, ec, ans + "H");
    }
    if (sr + 1 <= er)
    {
        // row + 1 -> Row Move
        ratInMaze(sr + 1, sc, er, ec, ans + "V");
    }

    //  For Diagonal-> SR + 1, SC + 1 Both -> Horizontal+Vertical -> Diagonal
    if (sc + 1 <= ec && sr + 1 <= er)
    {
        ratInMaze(sr + 1, sc + 1, er, ec, ans + "D");
    }
}

void rat()
{
    // Starting pos (row, column) = 0, 0
    // End pos (row, column) = 2, 3
    int sr = 0, sc = 0;
    // int er = 2, ec = 2;
    int er, ec;
    cin >> er >> ec;
    // string -> ans
    ratInMaze(sr, sc, er, ec, "");
}

int main()
{
    rat();

    return 0;
}

// Modification -> Interview Question
// Enter 2D Matrix, N*M and fill 0s and 1s in the matrix.
// 0 -> No Bomb
// 1 -> Bomb (Can't go here)

// condition -> if (sc+1 <= er && arr[sr][sc+1] != 1)
//           -> if (sr+1 <ec && arr[sr+1][sc] != 1)

// int sr, int sc, cin >> er >> ec (N*M)
// enter elements into the matrix
// for (int i = 0; i < n; i++)
//      for (int j = 0; j < m; i++)
//          cin >> arr[i][j]