class Solution {
public:
    unordered_map<int, bool> dp;

    bool solve(int bitmask, int dt, int& mi) {
        if (dt <= 0) return false;
        if (dp.count(bitmask)) return dp[bitmask];

        for (int i = 0; i < mi; i++) {
            if (bitmask & (1 << i)) {
                if (!solve(bitmask ^ (1 << i), dt - (i + 1), mi))
                    return dp[bitmask] = true;
            }
        }
        return dp[bitmask] = false;
    }

    bool canIWin(int mi, int dt) {
        if (dt == 0) return true;
        int sum = (mi * (mi + 1)) / 2;
        if (dt > sum) return false;

        int bitmask = (1 << mi) - 1;
        return solve(bitmask, dt, mi);
    }
};
