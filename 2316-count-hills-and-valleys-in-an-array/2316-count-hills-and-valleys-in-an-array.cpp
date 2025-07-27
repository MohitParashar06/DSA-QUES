class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> uni;
        uni.push_back(nums[0]);
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(uni.back() == nums[i]) continue;
            uni.push_back(nums[i]);
        }
        int cnt = 0;
        for(int i = 1; i < uni.size()-1; i++){
            if(uni[i] > uni[i-1] && uni[i] > uni[i+1] 
            || uni[i] < uni[i-1] && uni[i] < uni[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};