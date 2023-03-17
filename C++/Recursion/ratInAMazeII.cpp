#include <bits/stdc++.h>
using namespace std;

// with return type.
// take vector<int> ans and push back H and V in that array.
// Logic in copy -> 2 strings -> V1 and V2, V1+V2 -> Answer. V1 ke peeche H lagao, V2 ke peeche V lagao.

// Left veector -> add H
// Down vector -> add V
// Add left and down vector -> myans
// Print myans;

// in with return type you do vector<returnType> not void/int
vector<string> ratInAMaze(int sr, int sc, int er, int ec)
{
    // base case
    if (sr == er && sc == ec)
    {
        // base case -> empty string + return
        vector<string> base;
        base.push_back("");
        return base;
    }
    vector<string> myans;
    if (sc + 1 <= ec)
    {
        // for left
        vector<string> left = ratInAMaze(sr, sc + 1, er, ec);
        for (int i = 0; i < left.size(); i++)
        {
            myans.push_back("H" + left[i]);
        }
    }

    if (sr + 1 <= er)
    {
        // for down
        vector<string> down = ratInAMaze(sr + 1, sc, er, ec);
        for (int i = 0; i < down.size(); i++)
        {
            myans.push_back("V" + down[i]);
        }
    }
    return myans;
}

void ratInAMaze()
{
    int sr = 0, sc = 0, er = 2, ec = 2;
    vector<string> ans = ratInAMaze(sr, sc, er, ec);
    // printing ans
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}

int main()
{
    ratInAMaze();

    return 0;
}