class Solution {
public:
    set<int> st;
    int mod = 1e9 + 7;
    long long solve(long long n, long long k, vector<vector<int>>& dp) {
        if(k == 0 || k > n) return 0;
        if (n <= 2)
            return 1;
        if (dp[n][k] != -1)
            return dp[n][k];
        long long ans = 0;
        ans = (ans%mod + solve(n-1,k-1,dp)%mod)%mod;
        ans = (ans%mod + (n-1)* solve(n-1,k,dp)%mod)%mod;
        return dp[n][k] = ans % mod;
    }

    int rearrangeSticks(int n, int k) {
        if (n == k)
            return 1;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        int ans = solve(n, k, dp);
        return ans;
    }
};