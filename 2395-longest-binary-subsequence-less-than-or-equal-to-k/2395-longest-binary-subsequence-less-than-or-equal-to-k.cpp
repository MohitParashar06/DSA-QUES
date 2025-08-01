class Solution {
public:
    int f(int i, int size, int sum, string &s, vector<vector<int>>& dp) {
        if (i < 0) return 0;
        if (dp[i][size] != -1) return dp[i][size];

        int exc = f(i - 1, size, sum, s, dp);
        int inc = 0;

        if ((sum - (s[i] - '0') * pow(2, size)) >= 0) {
            inc = 1 + f(i - 1, size + 1, sum - (s[i] - '0') * pow(2, size), s, dp);
        }

        return dp[i][size] = max(exc, inc);
    }

    int longestSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(n - 1, 0, k, s, dp);
    }
};