class Solution {
public:
    string largestGoodInteger(string num) {
       unordered_map<int,int> cnt;
       int i = 0;
       char c = num[0];
       string s = "";
       s += c;
       s += num[1];
       s += num[2];
       cnt[num[0]]++;
       cnt[num[1]]++;
       cnt[num[2]]++;
       string ans = "";
       if(cnt.size() == 1 && s > ans){
            ans = s;
        }
       for(int j = 3; j <= num.size()-1; j++){
        cnt[num[i]]--;
        if(cnt[num[i]] == 0){
            cnt.erase(num[i]);
        }
        cnt[num[j]]++;
        i++;
        s.erase(s.begin());
        s += num[j];
        if(cnt.size() == 1 && s > ans){
            ans = s;
        }
       }
       return ans;
    }
};