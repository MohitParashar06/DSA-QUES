class Solution {
public:

    long long f(int i, int j, vector<int>& val,vector<vector<int>>& dp){
        if(i+1==j) return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        long long ans = INT_MAX;
        for(int k = i+1; k < j; k++){
            long long num = val[i] * val[k] * val[j] + f(i,k,val,dp)+f(k,j, val,dp);
            ans=min(ans,num);
        }
        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>>dp(51,vector<int>(51,-1));
        long long ans = f(0,values.size()-1, values,dp);
        return (int)ans;
    }
};