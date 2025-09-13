class Solution {
public:
 bool vowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return 1;
        return 0;
    }
    int maxFreqSum(string s) {
        vector<int> freq(26,0);
        for(int i = 0; i < s.size(); i++){
            freq[s[i]-'a']++;
        }
        int v = 0,c = 0;
        for(int i = 0; i < 26; i++){
            if(vowel(i+'a')) v = max(v,freq[i]);
            else c = max(c,freq[i]);
        }
        return v+c;
    }
};