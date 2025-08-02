class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        unordered_map<int, int> cnt1, cnt2, total;
        int n = b1.size();

        for (int i = 0; i < n; i++) {
            cnt1[b1[i]]++;
            cnt2[b2[i]]++;
            total[b1[i]]++;
            total[b2[i]]++;
        }

        for (auto& [val, freq] : total) {
            if (freq % 2 != 0) return -1;
        }

        
        vector<int> e1, e2;

        for (auto it : total) {
            int s = total[it.first] / 2;
            int diff1 = cnt1[it.first] - s;
            int diff2 = cnt2[it.first] - s;

           
            for (int i = 0; i < max(0, diff1); i++) e1.push_back(it.first);
            for (int i = 0; i < max(0, diff2); i++) e2.push_back(it.first);
        }

       
        if (e1.size() != e2.size()) return -1;

        sort(e1.begin(), e1.end());              
        sort(e2.rbegin(), e2.rend());             

        int gm = min(*min_element(b1.begin(), b1.end()), *min_element(b2.begin(), b2.end()));
        long long ans = 0;

        for (int i = 0; i < e1.size(); i++) {
            int a = e1[i], b = e2[i];
            ans += min((long long)min(a, b), 2LL * gm);
        }

        return ans;
    }
};
