class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt;
        for (auto s : words) {
            cnt[s]++;
        }
        int val = words.size() * words[0].size();
        int win = words[0].size();
        if(s.size() < val) return {};
        vector<int> ans;
        unordered_map<string, int> temp;
        int i = 0;
        for (i = 0; i < val; i += win) {
            string str = s.substr(i, win);
            // cout << str << " " << i << endl;
            temp[str]++;
        }
        if (temp == cnt) {
            ans.push_back(i - val);
        }
        int j = 1;
        i++;
        while (i <= s.size()) {
            temp.clear();
            for (int k = j; k < i; k += win) {
                string str = s.substr(k, win);
                // cout << str << " " << j << endl;
                if(cnt.find(str) == cnt.end()) break;
                temp[str]++;
            }
            if (temp == cnt) {
                ans.push_back(i - val);
            }
            j++;
            i++;
        }
        return ans;
    }
};