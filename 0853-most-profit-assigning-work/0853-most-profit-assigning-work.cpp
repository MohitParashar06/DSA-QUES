class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> pr;
        int n = profit.size();
        for (int i = 0; i < n; i++) {
            pr.push_back({difficulty[i], profit[i]});
        }
        sort(pr.begin(), pr.end());
        unordered_map<int, int> maxi;
        int lmax = 0;
        for (int i = 0; i < n; i++) {
            lmax = max(lmax, pr[i].second);
            maxi[pr[i].first] = lmax;
        }
        int ans = 0;
        for (int i = 0; i < worker.size(); i++) {
            // cout << i << " ";
            auto it = upper_bound(pr.begin(), pr.end(), worker[i],
                                  [](int value, const pair<int, int>& p) {
                                      return value <
                                             p.first; 
                                  });
                    if(it == pr.end()){
                        ans += maxi[pr[n-1].first];
                    }
                    else{
                        int ind = it - pr.begin();
                        if(ind == 0) continue;
                        ans += maxi[pr[ind-1].first];
                    }
        }
        return ans;
    }
};