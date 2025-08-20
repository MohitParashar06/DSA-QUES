class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
            return 0;
        if (matrix[i][j] == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int s = solve(i + 1, j, matrix, dp);
        int d = solve(i, j + 1, matrix, dp);
        int di = solve(i + 1, j + 1, matrix, dp);
        return dp[i][j] = min(s, min(d, di)) + 1;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = solve(i, j, matrix, dp);
                ans += val;
            }
        }

        return ans;
    }
};