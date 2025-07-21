class Solution {
public:
    string makeFancyString(string s) {
        int cnt = 1;
        string ans = "";
        int n = s.size();
        if(n <=2) return s;
        ans += s[0];
        ans += s[1];
        int j = 0, k = 1;
        for(int i = 2; i < n; i++){
            if(s[i]==ans[k]&&s[i]==ans[j]) continue;
            ans += s[i];
            j++;k++;
        }
        return ans;
    }
};