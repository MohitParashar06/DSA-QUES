class Solution {
public:
int mod = 1e9+7;
//     int f(int n, int alpha){
//         if(n <= 0){
//             return 0;
//         }
//         int res = 0;
//         if(alpha == 97){
//             res = (res%mod + f(n-1,101)+1)%mod;
//         }
//         else if(alpha == 101){
//             res = (res%mod + f(n-1,97)+1)%mod;
//             res = (res%mod + f(n-1,105)+1)%mod;
//         }
//         else if(alpha == 105){
//             res = (res%mod + f(n-1,97)+1)%mod;
//             res = (res%mod + f(n-1,101)+1)%mod;
//             res = (res%mod + f(n-1,111)+1)%mod;
//             res = (res%mod + f(n-1,117)+1)%mod;
//         }
//         else if(alpha == 111){
//             res = (res%mod + f(n-1,105)+1)%mod;
//             res = (res%mod + f(n-1,117)+1)%mod;
//         }
//         else{
//             res = (res%mod + f(n-1,97)+1)%mod;
//         }
//         return res%mod;
//     }

    int f(int n, int dig, vector<vector<int>>& dp){
        if(n == 0) return 1;
        if(dp[n][dig] != -1) return dp[n][dig];
        int ans = 0;
        for(int i =0; i < 5; i++){
            if(dig == 0 && i == 1){
                ans = (ans%mod + f(n-1,i,dp)%mod)%mod;
            }
            if(dig == 1 && (i == 0 || i == 2)){
                ans = (ans%mod + f(n-1,i,dp)%mod)%mod;
            }
            if(dig == 2 && i != 2){
                ans = (ans%mod + f(n-1,i,dp)%mod)%mod;
            }
            if(dig == 3 && (i == 2 || i == 4)){
                ans = (ans%mod + f(n-1,i,dp)%mod)%mod;
            }
            if(dig == 4 && i == 0){
                ans = (ans%mod + f(n-1,i,dp)%mod)%mod;
            }
        }
        return dp[n][dig] = ans%mod;
    }

    int countVowelPermutation(int n) {
        if(n == 1){
            return 5;
        }
        vector<vector<int>> dp(n+1, vector<int>(5,-1));
        int ans = 0;
        for(int i = 0; i < 5; i++){
            ans = (ans%mod + f(n-1,i,dp)%mod)%mod;
        }
        return ans;
        // int a = f(n-1,97);cout << a << endl;
        // int e = f(n-1,101);cout << e << endl;
        // int i = f(n-1,105);cout << i << endl;
        // int o = f(n-1,111);cout << o << endl;
        // int u = f(n-1,117);cout << u << endl;
        // return (((a%mod + e%mod)%mod + (i%mod + o%mod)%mod)%mod + u%mod)%mod;
    }
};