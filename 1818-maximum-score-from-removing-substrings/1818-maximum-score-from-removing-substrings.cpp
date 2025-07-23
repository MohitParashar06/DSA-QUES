class Solution {
public:

    int f(string s, int maxi, int mini, string p, string t){
        stack<char> st;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
            }else if(s[i] == p[1] && st.top() == p[0]){
                ans += maxi;
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        string temp ="";
        while(!st.empty()){
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        for(int i = 0; i < temp.size(); i++){
            if(st.empty()){
                st.push(temp[i]);
            }else if(temp[i] == t[1] && st.top() == t[0]){
                ans += mini;
                st.pop();
            }else if(temp[i] == p[1] && st.top() == p[0]){
                ans += maxi;
                st.pop();
            }else{
                st.push(temp[i]);
            }
        }
        return ans;
    }

    int maximumGain(string s, int x, int y) {
        int ans;
        if(x > y){
            ans = f(s,x,y,"ab","ba");
        }else{
            ans = f(s,y,x,"ba","ab");
        }
        return ans;
    }
};