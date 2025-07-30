class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<pair<int, int>> pr;
        int n = profits.size();
        for (int i = 0; i < n; i++) {
            pr.push_back({capital[i], profits[i]});
        }
        sort(pr.begin(), pr.end());
        unordered_map<int, bool> vis;

        priority_queue<pair<int,int>> pq;
        int prv = 0;

        while (k > 0) {
            auto it = upper_bound(pr.begin(), pr.end(), w,
                                 [](int value, const pair<int, int>& p) {
                                     return value < p.first;
                                 });
            int ind;
            if (it == pr.end()) {
                ind = n - 1;
            } else {
                ind = it - pr.begin() - 1;
            }
            while(prv <= ind){
                pq.push({pr[prv].second, prv});
                prv++;
            }
            if(pq.empty()) break;
            w += pq.top().first;
            pq.pop();
            k--;
        }
        return w;
    }
};