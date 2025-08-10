class Solution {
public:
    bool check(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n = n >> 1;
        }
        return count == 1;
    }

    bool perm(int ind, string& s, string& num) {
        if (ind >= num.size()) {
            // cout << stoi(num) << endl;
            if(check(stoi(num))) return true;
            return false;
        }

        for(int i = ind; i < num.size(); i++){
            swap(num[i], num[ind]);
            if(num[0] != '0')
                if(perm(ind+1,s,num)) return true;
            swap(num[i], num[ind]);
        }
        return false;
    }

    bool reorderedPowerOf2(int n) {
        string s = "";
        string num = to_string(n);
        return perm(0,s,num);
    }
};