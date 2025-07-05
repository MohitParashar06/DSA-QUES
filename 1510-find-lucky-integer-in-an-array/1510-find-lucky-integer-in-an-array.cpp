class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> cnt;
        int ans = -1;
        for(int i : arr)
            cnt[i]++;
        for(auto it : cnt){
            if(it.first == it.second)
                ans = max(ans,it.first);
        }
        return ans;
    }
};