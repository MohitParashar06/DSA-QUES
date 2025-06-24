class Solution {
public:

    int solve(int i, int j, vector<int>& stones, vector<vector<int>>& dp, vector<int>& sum){
        if(i > j) return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
            int sl = sum[j+1] - sum[i+1], sr =sum[j]-sum[i];
        // if(turn == false){
        //     // int sum = 0;
        //     // for(int k = i; k <= j; k++){
        //     //     sum += stones[k];
        //     // }
        //     int c1 = solve(i+1,j,stones,1,dp,sum) + sum[j+1] - sum[i+1];
        //     int c2 = solve(i,j-1,stones,1,dp,sum)+sum[j]-sum[i];
        //     return dp[i][j][turn] = max(c1,c2);
        // }else{
        //     // int sum = 0;
        //     // for(int k = i; k <= j; k++){
        //     //     sum += stones[k];
        //     // }
        //     int c1 = solve(i+1,j,stones,0,dp,sum)- (sum[j+1] - sum[i+1]);
        //     int c2 = solve(i,j-1,stones,0,dp,sum)- (sum[j]-sum[i]);
        //     return dp[i][j][turn] = min(c1,c2);
        // }
        return dp[i][j] = max(sl - solve(i+1,j,stones,dp,sum), sr - solve(i,j-1,stones,dp,sum));
    }

    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(stones.size()+1,vector<int>(n+1,-1));
        vector<int>preSum(n+1,0);
         for (int i = 0; i < n; i++)
            preSum[i + 1] = preSum[i] + stones[i];
        int ans = solve(0,stones.size()-1, stones,dp,preSum);
        return ans;
    }
};