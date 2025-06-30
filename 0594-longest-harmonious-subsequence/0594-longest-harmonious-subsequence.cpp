class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int cnt = 0;
        for(int j = 1; j < nums.size(); j++){
            while(nums[j] - nums[i] > 1)
                i++;
            if(nums[j] - nums[i] == 1){
                cnt = max(cnt, j-i+1);
            }
        }
        return cnt;
    }
};