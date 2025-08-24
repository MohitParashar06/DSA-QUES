class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int nzero = 1;
        int count = 0, maxCount = 0;int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0 && nzero <= 0){
                while(nums[j] != 0){
                    count--;
                    j++;
                }
                // count--;
                j++;
            }else if(nums[i] == 0 && nzero == 1){
                count++;
                nzero--;
            }else{
                count++;
            }
            maxCount = max(maxCount,count);
        }
        return maxCount-1;
    }
};