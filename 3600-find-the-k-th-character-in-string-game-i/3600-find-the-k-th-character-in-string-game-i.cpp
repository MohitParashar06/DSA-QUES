class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.size() < k){
            string temp = s;
            for(auto& it : temp){
                if(it == 'z'){
                    it = 'a';continue;
                }
                it = it+1;
            }
                s = s + temp;
            // cout << s << endl;
        }
        return s[k-1];
    }
};