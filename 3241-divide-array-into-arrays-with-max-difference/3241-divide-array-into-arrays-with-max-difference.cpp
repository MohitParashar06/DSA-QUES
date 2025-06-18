class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i+=3){
            vector<int> temp;
            if(nums[i+2]-nums[i] <= k && nums[i+1]-nums[i] <= k && nums[i+2]-nums[i+1] <= k){
                ans.push_back({nums[i],nums[i+1],nums[i+2]});
            }else{
                return {};
            }
        }
        return ans;
    }
};