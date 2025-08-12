class Solution {
public:

    int mod = 1e9+7;

    long long power(int n){
        if(n <= 1) return (n+1);
        long long res = power(n/2);
        if(n%2) return (((res*res)%mod)*2)%mod;
        return ((res*res)%mod);
    }

    int f(vector<int>& nums, int k, int ind, int sum, int cnt,vector<vector<vector<int>>>&dp){
        if(sum == k){
            return power(nums.size()-cnt);
        }
        if(ind >= nums.size() || sum > k) return 0;
        if(dp[ind][sum][cnt] != -1)return dp[ind][sum][cnt];
        int inc = f(nums,k,ind+1,sum+nums[ind],cnt+1,dp);
        int exc = f(nums,k,ind+1,sum,cnt,dp);
        return dp[ind][sum][cnt] = (inc+exc)%mod;
    }

    int sumOfPower(vector<int>& nums, int k) {
        vector<vector<vector<int>>> dp(100, vector<vector<int>>(100, vector<int>(102,-1)));
        return f(nums,k,0,0,0,dp);
    }
};