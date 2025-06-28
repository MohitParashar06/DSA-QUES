class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> pr,ar;
        for(int i = 0; i < nums.size(); i++){
            pr.push_back({nums[i], i});
        }
        sort(pr.begin(), pr.end());
        vector<int> ans;
        for(int i = nums.size()-1; i >= nums.size()-k && i>=0; i--){
            ar.push_back(pr[i]);
        }
        if(ar.size() > 1){
            sort(ar.begin(), ar.end(), [](pair<int,int>&a, pair<int,int>&b){
                return a.second < b.second;
            });}
        for(auto it : ar){
            ans.push_back(it.first);
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};