class Solution {
public:
    int f(vector<int>&nums,int i,int diff, vector<vector<int>> &dp){
        if(i<0) return 0;
        if(dp[i][diff+505]!=-1) return dp[i][diff+505];
        int ans = 0;
        for(int j=i-1;j>=0;j--){
            if(nums[i]-nums[j]==diff){
                ans = max(ans,1+f(nums,j,diff,dp));
            }
        }
        return dp[i][diff+505] = ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1050, -1));
        int ans = 2;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans,2+f(nums,i,nums[j]-nums[i],dp));
            }
        }
        return ans;
    }
};