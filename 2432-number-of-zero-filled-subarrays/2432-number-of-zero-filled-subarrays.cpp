class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        unordered_map<long long,long long> zc;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                count++;
            }else{
                zc[count]++;
                count = 0;
            }
            if(i == nums.size()-1){
                zc[count]++;
            }
        }
        long long ans = 0;
        for(auto it : zc){
            long long num = it.first;
            // cout << num << " " << it.second << endl;;
            ans += (long long)it.second * (long long)(num*(num+1)/2);
        }
        return ans;
    }
};