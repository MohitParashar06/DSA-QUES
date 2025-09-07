class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1){
            return {0};
        }
        vector<int> ans;
        int k = n/2;
        for(int i = -k; i <= k; i++){
            if(i != 0)
                ans.push_back(i);
        }
        if(n&1){
            ans.push_back(0);
        }
        return ans;
    }
};