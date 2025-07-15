class Solution {
public:
    bool isValid(string s) {
        bool fg = true;
        if(s.size() < 3) return 0;
        int dig=0,vow=0,con = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='@' || s[i]=='#' || s[i] =='$') return 0; 
            if(s[i] == 'a' || s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')vow++;
            else if(s[i] == 'A' || s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')vow++;
            else if(!(s[i]>='0'&&s[i] <= '9'))
                con++;
        }
        // cout << vow << " " << co/n<<endl;
        if(vow > 0 && con > 0) return 1;
        return 0;
    }
};