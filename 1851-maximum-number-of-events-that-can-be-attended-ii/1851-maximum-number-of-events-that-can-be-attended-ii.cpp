class Solution {
public:
int f(int ind, vector<vector<int>>& pr, vector<vector<int>>& dp, int k){
        if(ind >= pr.size())
            return 0;
        if(k == 0)
            return 0;
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        int exc = f(ind+1,pr,dp,k);
         auto it = upper_bound(pr.begin(), pr.end(), pr[ind][1],
    [](int value, const vector<int>& row) {
        return value < row[0];
    });
        if(it == pr.end()){
        //   cout << pr[ind][2] << endl;
          return dp[ind][k] = max(exc,pr[ind][2]);  
        } 
        int id = it - pr.begin();
        // cout << ind << " " << id << endl;
        int inc = f(id,pr,dp,k-1) + pr[ind][2];
        return dp[ind][k] = max(inc,exc);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(),vector<int>(k+1,-1));
        int ans = f(0,events,dp,k);
        return ans;
    }
};