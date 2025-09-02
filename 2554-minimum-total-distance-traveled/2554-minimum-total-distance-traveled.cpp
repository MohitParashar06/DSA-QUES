class Solution {
public:

    long long solve(int ind, vector<int>& rb, vector<int>& f, vector<vector<long long>> &dp,int prv){
        if(ind >= rb.size()) return 0;
        if(prv >= f.size()) return 1e16;
        if(dp[ind][prv] != -1) return dp[ind][prv];
        long long mini = abs(rb[ind]-f[prv]) + solve(ind+1,rb,f,dp,prv+1);
        mini = min(mini, solve(ind,rb,f,dp,prv+1));
        return dp[ind][prv] =  mini;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> temp;
        for(auto it : factory){
            for(int i = 0; i < it[1]; i++)
                temp.push_back(it[0]);
        }
        vector<vector<long long>> dp(robot.size(), vector<long long>(temp.size()+1, -1));
        long long ans =solve(0,robot,temp,dp,0);
        return ans;
    }
};