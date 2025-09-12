class Solution {
public:
    int mod = 1e9+7;
    int f(int d, int n, int del, int fog, vector<int>& dp){
        if(d < 0) return 0;
        if(dp[d] != -1) return dp[d];
        if(d == 0) return dp[d]=1;
        if(d < 0) return dp[d]=0;

        long long ans = 0;
        for(int j = max(0,d-fog+1); j <= d-del; j++){
            ans += f(j,n,del,fog,dp);
        }
        return dp[d] = ans%mod;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1, -1);
        long long int ans = 0;

        for(int i = n-forget; i < n; i++){
            ans += f(i,n,delay,forget,dp);
        }
        
        return ans%mod;
    }
};