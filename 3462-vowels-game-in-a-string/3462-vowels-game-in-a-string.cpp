class Solution {
public:

    bool vowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return 1;
        return 0;
    }

    bool f(string s, int ind, int turn){
        // cout << s << "   " << ind << "   " << turn << endl;
        if(ind >= s.size()){
            return turn;
        }
        if(turn == 0){
            for(int i = 1; i+ind < s.size(); i+=2){
                bool ans = f(s,ind+i,1);
                if(ans) return ans;
            }
            return false;
        }else{

            for(int i = 0; i+ind < s.size(); i += 2){
                bool ans = f(s,ind+i,0);
                // if(ans == false) return false;
            }
            return true;
        }
    }

    bool doesAliceWin(string s) {
       string res = "";
       for(auto it : s){
        if(vowel(it))
            res += it;
       } 
       if(res.size() == 0) return 0;
       return true;
       return f(res,0,0);
    }
};