class Solution {
public:
    int maximum69Number (int num) {
       string s = to_string(num);
       int ans = num;
       for(int i = 0; i < s.length(); i++){
        if(s[i] == '9'){
            s[i] = '6';
            int num = stoi(s);
            ans = max(num,ans);
            s[i] = '9';
        }
        else{
             s[i] = '9';
            int num = stoi(s);
            ans = max(num,ans);
            s[i] = '6';
        }
       }
       return ans; 
    }
};