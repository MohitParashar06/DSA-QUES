class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        int sum = 0, count = 0, flag = mini;
        for(int i = 0; i < nums.size(); i++){
            int num = target - nums[i];
            int j = i+1, k = nums.size() - 1;
            while(j < k){
                sum = nums[i] + nums[j] + nums[k];
                if(sum == target){
                    return target;
                }
                else if(nums[j] + nums[k] < num){
                    j++;
                }
                else{
                    k--;
                }
                mini = min(mini,abs(sum - target));
                if(flag != mini){
                    count = sum;
                    flag = mini;
                }
            }
        }
            return count;
    }
};