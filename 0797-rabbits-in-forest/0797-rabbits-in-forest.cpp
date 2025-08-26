class Solution {
public:
    int numRabbits(vector<int>& answers) {
       unordered_map<int,int> cnt;
       for(int it : answers)
            cnt[it]++;
        int ans =0 ;
        for(auto it : cnt){
            if(it.first == 0) ans += it.second;
            else{
                ans += it.first+1;
                it.second -= (it.first+1);
                while(it.second > 0){
                    ans += it.first+1;
                    it.second -= (it.first+1);
                }
            }
        }
        return ans;
    }
};