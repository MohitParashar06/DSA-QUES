class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
    unordered_map<int,int> hash;
    for(int i : arr){
        hash[i]++;
    }
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++){
        hash[arr[i]]--;
        if(hash[target - arr[i]] > 0){
            ans.push_back(i);
        }
        hash[arr[i]]++;
    }
    return ans;
    }  
};