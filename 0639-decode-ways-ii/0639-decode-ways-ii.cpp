class Solution {
public:
    int mod = 1e9 + 7;

    long long solve(string& s, int ind, vector<long long>& dp) {
        if (ind >= s.size()) return 1;
        if (dp[ind] != -1) return dp[ind];
        if (s[ind] == '0') return 0;
        long long inco = 0, inct = 0;
        if (s[ind] == '*') {
            inco = (9 * solve(s, ind + 1, dp)) % mod;
        } else {
            inco = solve(s, ind + 1, dp);
        }

        if (ind + 1 < s.size()) {
            char c1 = s[ind], c2 = s[ind + 1];
            if (c1 == '*' && c2 == '*') {
                inct = (15 * solve(s, ind + 2, dp)) % mod;
            } else if (c1 == '*') {
                if (c2 <= '6') inct = (2 * solve(s, ind + 2, dp)) % mod;
                else inct = solve(s, ind + 2, dp) % mod;
            } else if (c2 == '*') {
                if (c1 == '1') inct = (9 * solve(s, ind + 2, dp)) % mod;
                else if (c1 == '2') inct = (6 * solve(s, ind + 2, dp)) % mod;
            } else {
                int num = (c1 - '0') * 10 + (c2 - '0');
                if (num <= 26 && num >= 10) inct = solve(s, ind + 2, dp) % mod;
            }
        }
        return dp[ind] = (inco + inct) % mod;
    }

    int numDecodings(string s) {
        vector<long long> dp(s.size(), -1);
        return solve(s, 0, dp);
    }
};
