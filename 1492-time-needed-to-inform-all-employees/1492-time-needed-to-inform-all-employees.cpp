class Solution {
public:
    int f(vector<int>& manager, int node, vector<int>& it, vector<int>& dp){
        if(manager[node] == -1)
            return it[node];
        if(dp[node] != -1)
            return dp[node];
        return dp[node] = it[node]+f(manager,manager[node],it,dp);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int cnt = 0;
        vector<int> dp(n+1,-1);
        for(int i = 0; i < informTime.size(); i++){
            if(informTime[i] == 0){
                cnt = max(cnt,f(manager,i, informTime,dp));
            }
        }
        return cnt;
    }
};