#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int exit_point(vector<vector<int>> &arr)
{
    int direction = 0; // 0 = east, 1 = south, 3 = west. 4 will become 0 = East again (4%4 = 0)
    int row = 0;
    int column = 0;

    // Try to imagine
    while (true)
    {
        direction = (direction + arr[row][column]) % 4; // 0 will stay 0, 1 will stay 1, 2 will stay 2, 3 will stay 3, 4 becomes 0. (Back to east.)
        if (direction == 0)
        {
            // Going east, row wont change, column will increase
            column++;
        }
        else if (direction == 1)
        {
            // Going south, row will change by 1, column will stay the same
            row++;
        }
        else if (direction == 2)
        {
            // Going west, row will stay the same, column will decrement by 1
            column--;
        }
        else if (direction == 3)
        {
            // Going north, column will stay the same, row will decrement by 1
            row--;
        }

        // Answer = 2,-1 for now, but we need to print 2,0. (We don't need to print the exit, we need to print the last exit point. So adjust that.)
        // Are we out yet? Exit points conditions
        if (row < 0)
        {
            row++;
            break;
        }
        else if (column < 0)
        {
            column++;
            break;
        }
        else if (row = arr.size())
        {
            row--;
            break;
        }
        else if (column = arr[0].size())
        {
            column--;
            break;
        }
    }

    cout << row << " " << column;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> arr = {{0, 0, 1, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}};
    exit_point(arr);

    return 0;
}
