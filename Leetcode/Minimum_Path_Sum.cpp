class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else {
                    dp[i][j] = grid[i][j] + min((i == 0 ? INT_MAX : dp[i - 1][j]), (j == 0 ? INT_MAX : dp[i][j - 1]));
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};