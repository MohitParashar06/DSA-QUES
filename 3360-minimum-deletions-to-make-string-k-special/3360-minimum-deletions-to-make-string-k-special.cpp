class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> cnt(26,0);
        for(auto it : word){
            cnt[it-'a']++;
        }
        // sort(cnt.begin(), cnt.end());
        int ans = INT_MAX;
        for(int i = 0; i < cnt.size(); i++){
            int count = 0;
            for(int j = 0 ; j < cnt.size(); j++){
                if(cnt[j] < cnt[i]) count += cnt[j];
                if(cnt[j] > cnt[i]+k) count += (cnt[j]-cnt[i]-k);
            }
            ans = min(ans,count);
        }
        return ans;
    }
};