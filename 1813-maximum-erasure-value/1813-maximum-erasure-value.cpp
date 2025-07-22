class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,bool> vis;
        int n = nums.size();
        int sum = 0, j = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(vis.find(nums[i]) == vis.end()){
                vis[nums[i]]=1;
                sum += nums[i];
                maxi = max(maxi,sum);
            }
            else{
                while(vis[nums[i]] && j < i){
                    sum -= nums[j];
                    vis[nums[j]]=0;
                    j++;
                }
                sum += nums[i];
                vis[nums[i]]=1;
                maxi = max(maxi,sum);
            }
        }
        return maxi;
    }
};