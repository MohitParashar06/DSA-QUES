class Solution {
public:

    bool isPalindrome(string &s, int i, int j){
        // int i = 0, j = s.length()-1;
        while(i < j){
            if(s[i] != s[j])
                return 0;
            i++;j--;
        }
        return 1;
    }
    bool  solve(string &s, int ind, int k, vector<vector<int>> &dp){
        if(ind >= s.length()){
            
            return k == 0;
        }
        if(k == 0){
            return isPalindrome(s,ind,s.size()-1);
        }
        if(dp[ind][k] != -1){
            return dp[ind][k];
        }
        bool ans = false;
        for(int i = ind; i < s.length()-1; i++){
            if(isPalindrome(s,ind,i)){
                ans = ans || solve(s,i+1,k-1,dp);
            }
        }
        return dp[ind][k] = ans;
    }

    bool checkPartitioning(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(3,-1));
        bool ans = solve(s,0,2,dp);
        return ans;
    }
};