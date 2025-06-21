class Solution {
public:

    int f(int ind, vector<vector<int>>& pr, vector<int>& dp){
        if(ind >= pr.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int exc = f(ind+1,pr,dp);
         auto it = lower_bound(pr.begin(), pr.end(), pr[ind][1],
        [](const vector<int>& p, int value) {
            return p[0] < value;
        });
        if(it == pr.end()){
        //   cout << pr[ind][2] << endl;
          return dp[ind] = max(exc,pr[ind][2]);  
        } 
        int id = it - pr.begin();
        // cout << ind << " " << id << endl;
        int inc = f(id,pr,dp) + pr[ind][2];
        return dp[ind] = max(inc,exc);
    }

    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& prf) {
        vector<vector<int>> pr;
        for(int i = 0; i < st.size(); i++){
            pr.push_back({st[i], et[i], prf[i]});
        }
        sort(pr.begin(), pr.end());
        vector<int> dp(st.size(),-1);
        int ans = f(0,pr,dp);
        return ans;
    }
};