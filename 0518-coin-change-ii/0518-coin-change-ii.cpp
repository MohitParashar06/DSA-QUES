class Solution {
public:
 int solve(vector<int>& coins, int n, int target, int index,vector<vector< int>> &dp){
        if(index >= n){
            
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[index][target] != -1){
         
            return dp[index][target];
        }
        int take = 0;
        if(target >= coins[index]){
            take =  solve(coins,n,target-coins[index], index,dp);
        }
         int nottake = solve(coins,n,target, index+1,dp);
      
        dp[index][target] = take+nottake;
        return dp[index][target];
    }
  
    int change(int sum, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int N = coins.size();
          vector<vector< int>> dp(N, vector< int>(sum+1,-1));
        // cout << sum << endl;
       int ans = solve(coins,N,sum, 0,dp)+1;
        return ans-1;
    }
};