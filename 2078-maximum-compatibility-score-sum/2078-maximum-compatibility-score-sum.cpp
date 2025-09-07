class Solution {
public:

    int f(vector<vector<int>>& st, vector<vector<int>>& mt, int ind, int mask,vector<vector<int>> &dp){
        if(ind >= st.size()) return 0;
        int ans = 0;
        if(dp[ind][mask] != -1) return dp[ind][mask];
        for(int i = 0; i < mt.size(); i++){
            int nmask = mask;
            if(nmask & (1 << i)){
                int cnt = 0;
                for(int j = 0; j < mt[i].size(); j++){
                    if(st[ind][j] == mt[i][j]) cnt++;
                }
                ans = max(ans,f(st,mt,ind+1,nmask ^ (1 << i),dp)+cnt);
            }
        }
        return dp[ind][mask] = ans;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = mentors.size();
        int mask = (1 << m)-1;
        vector<vector<int>> dp(m, vector<int>(mask+1, -1));
        return f(students,mentors,0,mask,dp);
    }
};