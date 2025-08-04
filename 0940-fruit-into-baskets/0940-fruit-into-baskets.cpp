class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int t1 = -1, t2 = -1;
        int ans = 0;
        int j = 0;
        unordered_map<int,int> cnt;
        for(int i = 0; i < fruits.size(); i++){
            if(t1 == -1 && t2 == -1){
                t1 = fruits[i];
                cnt[fruits[i]]++;
                ans = max(ans,i-j+1);
            }else if(t2 == -1 && fruits[i] != t1){
                t2 = fruits[i];
                cnt[fruits[i]]++;
                ans = max(ans,i-j+1);
            }else if(fruits[i] == t2 || fruits[i] == t1){
                cnt[fruits[i]]++;
                ans = max(ans,i-j+1);
            }else{
                while(cnt[t1] > 0 && cnt[t2] > 0){
                    cnt[fruits[j]]--;
                    j++;
                }
                if(cnt[t1] == 0){
                    t1 = fruits[i];
                    cnt[t1]++;
                }else{
                    t2 = fruits[i];
                    cnt[t2]++;
                }
                ans = max(ans,i-j+1);
            }
        }
        return ans;
    }
};