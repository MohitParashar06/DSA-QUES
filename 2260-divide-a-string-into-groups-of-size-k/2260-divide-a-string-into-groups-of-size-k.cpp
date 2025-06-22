class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for(int i = 0; i < s.size(); i += k){
            int j = i;
            string str = "";
            while(j < i+k && j < s.size()){
                str+= s[j++];
            }
            cout << str << endl;
            ans.push_back(str);
        }
        if(ans.back().size() == k)
            return ans;
        else
            ans.pop_back();
        int x = s.size()%k;
        string st = "";
        for(int i = s.size()-x; i < s.size(); i++){
            st += s[i];
        }
        while(st.size() < k)
            st += fill;
        ans.push_back(st);
        return ans;
    }
};