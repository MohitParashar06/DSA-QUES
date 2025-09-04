class Solution {
public:
int dp[1001][1001][2];
    bool solve(int i, int j, vector<int>& nums, int turn){
        if(i > j){
            return !turn;
        }
        if(dp[i][j][turn] != -1) return dp[i][j][turn];
        if(!turn){
            return dp[i][j][turn] = solve(i+1,j,nums,1) || solve(i,j-1,nums,1);
        }else{
            bool x = solve(i,j-1,nums,0) && solve(i+1,j,nums,0);
            return dp[i][j][turn] = x;
        }
    }

    bool xorGame(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
            for(int k = 0; k < nums.size(); k++)
                ans ^=nums[k];
            if(ans == 0) return true;
        bool a1 = solve(0,nums.size()-1, nums, 0);
        return a1;
    }
};