class Solution {
public:
    int f(string target, vector<vector<int>>& stickers, unordered_map<string, int>& dp) {
        if (target.empty()) return 0;
        if (dp.count(target)) return dp[target];

        vector<int> tar(26, 0);
        for (char c : target) tar[c - 'a']++;

        int ans = INT_MAX;
        for (auto& st : stickers) {
            if (st[target[0] - 'a'] == 0) continue;

            string nt;
            for (int i = 0; i < 26; i++) {
                int remain = tar[i] - st[i];
                for (int j = 0; j < max(0, remain); j++)
                    nt.push_back('a' + i);
            }

            int temp = f(nt, stickers, dp);
            if (temp != -1) ans = min(ans, 1 + temp);
        }

        return dp[target] = (ans == INT_MAX ? -1 : ans);
    }

    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>> stickerFreq(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
            for (char c : stickers[i])
                stickerFreq[i][c - 'a']++;
        unordered_map<string, int> dp;
        return f(target, stickerFreq, dp);
    }
};
