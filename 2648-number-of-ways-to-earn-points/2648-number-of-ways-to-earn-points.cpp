class Solution {
public:

    int mod = 1e9+7;
    int f(int ind, vector<vector<int>>& p, int tar, vector<vector<int>>& dp){
        if(ind >= p.size()){
            if(tar == 0) return 1;
            return 0;
        }
        if(tar == 0) return 1;
        if(tar < 0) return 0;
        if(dp[ind][tar] != -1) return dp[ind][tar];
        int ans = f(ind+1, p , tar, dp)%mod;
        for(int k = 1; k <= p[ind][0]; k++){
            ans = (ans%mod + f(ind+1,p,tar-k*p[ind][1], dp)%mod)%mod;
        }
        return dp[ind][tar] = ans%mod;
    }

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<vector<int>> dp(types.size(), vector<int>(target+1,-1));
        return f(0,types,target,dp);
    }
};