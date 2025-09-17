class Solution {
public:
    int canBeTypedWords(string text, string bl) {
        set<char> st(bl.begin(), bl.end());
        int i = 0;
        int cnt = 0;
        while(i < text.size()){
            if(text[i] == ' '){
                i++;continue;
            }
            if(st.count(text[i])){
                cnt++;
                while(i < text.size() && text[i] != ' ') i++;
            }
            i++;
        }
        i=0;
        int ct=0;
        while(i < text.size()){
            if(text[i] == ' ') ct++;
            i++;
        }
    return ct+1-cnt;
    }
};