class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set<pair<int,pair<int,int>>> st;
        for(int i = 0; i < nums.size(); i++){
            st.insert({nums[i][0], {i,0}});
        }
        if(nums.size()==1){
            return {nums[0][0],nums[0][0]};
        }
        int ans = 1e9;
        vector<int> res;
        while(st.size() >= 2){
            auto t = *st.begin();
            auto l = *st.rbegin();
            if(l.first-t.first < ans){
                ans = l.first-t.first;
                res = {t.first,l.first};
            }else if(l.first-t.first == ans && res[0] > t.first){
                res = {t.first,l.first};
            }
            st.erase(t);
            if(t.second.second+1 < nums[t.second.first].size()){
                st.insert({nums[t.second.first][t.second.second+1], 
                        {t.second.first,t.second.second+1}});
            }else{
                break;
            }
        }
        return res;
    }
};