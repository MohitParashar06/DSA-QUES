class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
         int min_j = 0, max_j = 0;
    for (int i = indexDifference, j = 0; i < nums.size(); ++i, ++j) {
        min_j = nums[min_j] < nums[j] ? min_j : j;
        max_j = nums[max_j] > nums[j] ? max_j : j;
        if (abs(nums[i] - nums[min_j]) >= valueDifference)
            return {min_j, i};
        if (abs(nums[i] - nums[max_j]) >= valueDifference)
            return {max_j, i};
    }
    return {-1, -1};
    }
};