class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        
        sort(ages.begin(), ages.end());
        unordered_map<int,int> tt;
        tt[ages[0]]++;
        int cnt = 0;
        int j = 0;
        for(int i = 1; i < ages.size(); i++){
            tt[ages[i]]++;
            // if(ages[i] >= 100 && ages[j] >= 100){
            //     cnt += (i-j);
            //     continue;
            // }
            while(ages[j] <= (ages[i]/2 + 7) && j < i){
                j++;
            }
            cnt += (i-j);
        }

        for(auto it : tt){
            int n = it.second;
            int x = it.first;
            if(x > x/2+7)
                cnt += (n*(n-1))/2;
        }

        return cnt;

    }
};