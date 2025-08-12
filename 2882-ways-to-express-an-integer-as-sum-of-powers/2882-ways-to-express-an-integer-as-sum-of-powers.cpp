class Solution {
public:
int mod = 1e9+7;
    int f(int i, int n, int x, int val, vector<vector<int>>& dp){
        if(val == 0){
            return 1;
        }
        if(val < 0) return 0;
        if(i > n) return 0;
        if(dp[i][val] != -1) return dp[i][val];
        int exc = f(i+1,n,x,val,dp);
        int inc = 0;
        long long v = pow(i,x);
        if(v <= val)
            inc = f(i+1,n,x,val-(int)v,dp);
        return dp[i][val] = (exc+inc)%mod;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(1,n,x,n,dp);
    }
};