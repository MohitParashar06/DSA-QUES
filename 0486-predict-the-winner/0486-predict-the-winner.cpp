class Solution {
public:

    int f(int i, int j, int tr, vector<int>& nums, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(tr == 0){
            int fr = f(i+1,j,1,nums,dp)+nums[i];
            int ls = f(i,j-1,1,nums,dp)+nums[j];
            return dp[i][j] = max(ls,fr);
        }else{
            int fr = f(i+1,j,0,nums,dp)-nums[i];
            int ls = f(i,j-1,0,nums,dp)-nums[j];
            return dp[i][j] = min(fr,ls);
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        int ans = f(0,nums.size()-1,0,nums,dp);
        // cout << ans;
        return ans >= 0;
    }
};