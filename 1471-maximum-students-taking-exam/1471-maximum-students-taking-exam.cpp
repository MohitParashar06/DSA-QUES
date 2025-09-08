class Solution {
public:
    int f(int ind, int mask, vector<vector<char>>& seats, vector<vector<int>>& dp) {
        if (ind >= seats.size()) return 0;
        int ans = 0;
        int n = seats[ind].size();
        if(dp[ind][mask] != -1) return dp[ind][mask];
        // Option 1: Skip this row
        ans = max(ans, f(ind + 1, mask, seats,dp));

        // Try placing students in this row using mask rules
        for (int curMask = 0; curMask < (1 << n); curMask++) {
            bool valid = true;
            int count = 0;
            for (int i = 0; i < n; i++) {
                if ((curMask >> i) & 1) {
                    // Check seat availability
                    if (seats[ind][i] == '#') { valid = false; break; }

                    // Check same row adjacency (i > 0 to avoid negative index)
                    if (i > 0 && ((curMask >> (i - 1)) & 1)) { valid = false; break; }

                    // Check diagonal adjacency with previous row
                    if ((i > 0 && (mask & (1 << (i - 1)))) || 
                        (i + 1 < n && (mask & (1 << (i + 1))))) {
                        valid = false;
                        break;
                    }

                    count++;
                }
            }
            if (valid) {
                ans = max(ans, count + f(ind + 1, curMask, seats,dp));
            }
        }
        return dp[ind][mask] = ans;
    }

    int maxStudents(vector<vector<char>>& seats) {
        vector<vector<int>> dp(seats.size(), vector<int>(1000,-1));
        return f(0, 0, seats,dp);
    }
};
