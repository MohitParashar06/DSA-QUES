class Solution {
public:

    int count(string& s){
        int i = 0, j =s.size()-1;
        int cnt = 0;
        while(i <= j){
            if(s[i] != s[j]) cnt++;
            i++;j--;
        }
        return cnt;
    }

    int f(string& s, int ind, int k, vector<vector<int>>& dp){
        if(ind >= s.size()){
            if(k == 0) return 0;
            return 1e9;
        }
        if(k < 0) return 1e9;
        if(dp[ind][k] != -1) return dp[ind][k];
        string st = "";
        int ans = 1e9;
        for(int i = ind; i < s.size(); i++){
            st += s[i];
            int cnt = count(st);
            // cout << ind  << " " << i << " " << st << " " << cnt << endl;
            ans = min(ans, f(s,i+1,k-1,dp)+cnt);
        }
        return dp[ind][k] = ans;
    }

    int palindromePartition(string s, int k) {
        vector<vector<int>> dp(s.size(), vector<int>(k+1,-1));
        return f(s,0,k,dp);
    }
};