vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int top = 0, left = 0, right = n - 1, bottom = n - 1;
    int k = 1;
    // iterate through 2d array
    while (left <= right && top <= bottom)
    {
        // 1 2 3
        for (int i = left; i <= right; i++)
        {
            // 1, second iteration = 2, third iteration = 3 so on...
            ans[top][i] = k;
            k++;
        }
        // update row.
        top++;
        // 3 4 5
        for (int i = top; i <= bottom; i++)
        {
            ans[i][right] = k;
            k++;
        }
        // update (3 and then 4 and then 5 (right--))
        right--;
        // if rowBegin <= rowEnd, go from end col to start
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans[bottom][i] = k;
                k++;
            }
            bottom--;
        }
        // 4 5
        if (left <= right)
        {
            // go from up now to beginning.
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