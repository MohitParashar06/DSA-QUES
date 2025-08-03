class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector<pair<int,int>>pr;
        for(int i = 0; i < n; i++){
            pr.push_back({eff[i],speed[i]});
        }
        sort(pr.rbegin(), pr.rend());
        int mod = 1e9+7;
        priority_queue<int, vector<int>, greater<int> > pq;
        long long sum = 0;
        long long mini = 1e9;
        long long ans = 0;
        for(auto it : pr){
            pq.push(it.second);
            sum += it.second;
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans,sum*it.first);
        }
        return ans%mod;
    }
};