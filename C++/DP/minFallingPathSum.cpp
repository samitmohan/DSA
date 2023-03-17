// https://leetcode.com/problems/minimum-falling-path-sum/description/
class Solution {
public:
    // https://www.youtube.com/watch?v=oJ5leqo6vjg
    int dp[101][101]; // dp table -> constraints 100
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int row = matrix.size();
      int col = matrix[0].size();

      // fill first row in dp table as it is
      for (int i = 0; i < col; i++) {
        dp[0][i] = matrix[0][i];
      }

      for (int i = 1; i < row; i++) {
        for (int j = 0; j < col; j++) {
          int minimum = 10005; // ans
          // check for 3 cases -> diagonal upleft, diagonal upright, direct up
          // direct up
          if (i - 1 >= 0) {
            minimum = min(minimum, dp[i - 1][j]);
          }
          // diagonal upleft
          if (i - 1 >= 0 && j - 1 >= 0) {
            minimum = min(minimum, dp[i - 1][j - 1]);
          }
          // diagonal upright
          if (i - 1 >= 0 && j + 1 < col) {
            minimum = min(minimum, dp[i - 1][j + 1]);
          }
          dp[i][j] = minimum + matrix[i][j]; // prefix sum throughout row/col
        }
      }
      int ans = dp[row - 1][0]; // set to last val in table
      // last row : 13 13 14 -> find min
      for (int i = 1; i < row; i++) {
        ans = min(ans, dp[row - 1][i]);
      }
      return ans;
    }
};
