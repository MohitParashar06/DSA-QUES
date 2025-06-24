class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        set<int> st;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                if(abs(i-j) <= k && (nums[i] == key || nums[j] == key)){
                    if(nums[j] != key)
                        st.insert(j);
                    else
                        st.insert(i);
                }
            }
        }
        for(auto &it : st){
            ans.push_back(it);
        }
        return ans;
    }
};