class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        vector<int> result;
        unordered_map<int,int> m1,m2;
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i] == nums2[i]){
                m1[nums1[i]]++;m2[nums2[i]]++;
                ans++;
                result.push_back(ans);
            }else{
                if(m1[nums2[i]] > 0 && m2[nums1[i]] > 0){
                    ans+=2;
                }else if(m1[nums2[i]] > 0 || m2[nums1[i]] > 0){
                    ans++;
                }
                result.push_back(ans);
                m1[nums1[i]]++;m2[nums2[i]]++;
            }
        }
        return result;
    }
};