class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 1, j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]-nums[j] > k){
                cnt++;
                j = i;
            }
        }
        return cnt;
    }
};