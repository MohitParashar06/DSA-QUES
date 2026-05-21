class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> st, st2;
        for (int i : arr1) {
            string s = to_string(i);
            string t = "";
            for (int j = 0; j < s.size(); j++) {
                t += s[j];
                st.insert(t);
            }
        }
        for (int i : arr2) {
            string s = to_string(i);
            string t = "";
            for (int j = 0; j < s.size(); j++) {
                t += s[j];
                st2.insert(t);
            }
        }
        int ans = 0;
        for(auto it : st){
            if(st2.find(it) != st2.end())
                ans = max(ans,(int)it.size());
        }
        return ans;
    }
};