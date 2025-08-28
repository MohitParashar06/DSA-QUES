class Solution {
public:
    int rotatedDigits(int n) {
        unordered_map<char,char> ch;
        ch['0']='0';
        ch['1']='1';
        ch['8']='8';
        ch['2']='5';
        ch['5']='2';
        ch['6']='9';
        ch['9']='6';
        int ans = 0;
        for(int i = 1; i <= n; i++){
            string s = to_string(i);
            int fg = 0;
            for(auto &c : s){
                if(ch.find(c) != ch.end()){
                    c = ch[c];
                }else{
                    fg = 1;
                    break;
                }
            }
            if(fg == 1) continue;
            int num = stoi(s);
            if(num != i) ans++;
        }
        return ans;
    }
};