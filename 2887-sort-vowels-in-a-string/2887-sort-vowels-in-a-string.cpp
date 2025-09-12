class Solution {
public:

    bool vowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return 1;
        return 0;
    }

    string sortVowels(string s) {
        priority_queue<char,vector<char>,greater<char>> pq;
        for(auto it : s){
            if(vowel(it)){
                pq.push(it);
            }
        }
        string res = "";
        for(auto it : s){
            if(vowel(it)){
                res += pq.top();
                pq.pop();
                continue;
            }
            res += it;
        }
        return res;
    }
};