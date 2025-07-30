class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxlen = 0, len = 0, bit = 0;
        for(int i = 0; i < nums.size(); i++){
            if(bit < nums[i]){
                bit = nums[i];
                len = 1;
                maxlen = 1;
            }
            if(i > 0 && nums[i] == nums[i-1] && bit == nums[i]){
                len++;
            }else if(i > 0 && nums[i] != nums[i-1]){
                len = 1;
            }
            maxlen = max(maxlen,len);
        }
        return maxlen;
    }
};