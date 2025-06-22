class Solution {
public:
    static bool customSort(const vector<int> &a, const vector<int> &b) {
        if (a[0] != b[0])
            return a[0] < b[0];
        return a[2] > b[2];
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<int> maxFrom(n);
        maxFrom[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; --i) {
            maxFrom[i] = max(events[i][2], maxFrom[i + 1]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            auto it = upper_bound(events.begin(), events.end(), events[i][1],
                [](int value, const vector<int>& p) {
                    return value < p[0];
                });

            int id = it - events.begin();
            if (id == n) {
                ans = max(ans, events[i][2]);
            } else {
                ans = max(ans, events[i][2] + maxFrom[id]);
            }
        }
        return ans;
    }
};
