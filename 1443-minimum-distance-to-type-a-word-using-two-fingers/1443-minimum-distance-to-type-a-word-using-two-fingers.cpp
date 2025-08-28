class Solution {
public:
    int solve(string& s, unordered_map<int, pair<int, int>>& pos, int f1,
              int f2, int ind,  vector<vector<vector<int>>> &dp) {
        if (ind >= s.size())
            return 0;
        if(dp[ind][f1+1][f2+1] != -1) return dp[ind][f1+1][f2+1];
        int fing1=0, fing2=0;
        if (f1 == -1) {
            fing1 = solve(s, pos, s[ind] - 'A', f2, ind + 1,dp);
        } else {
            int val = abs(pos[f1].first - pos[s[ind]-'A'].first) +
                      abs(pos[f1].second - pos[s[ind]-'A'].second);
                    //   cout << ch << " " << s[ind] << " " << val << endl;
            fing1 = solve(s, pos, s[ind] - 'A', f2, ind + 1,dp) + val; 
        }
        if (f2 == -1) {
            fing2 = solve(s, pos, f1, s[ind] - 'A', ind + 1,dp);
        } else {
            int val = abs(pos[f2].first - pos[s[ind]-'A'].first) +
                      abs(pos[f2].second - pos[s[ind]-'A'].second);
            fing2 = (int)solve(s, pos, f1, s[ind] - 'A', ind + 1,dp) + val;
        }
        return dp[ind][f1+1][f2+1] = min(fing1, fing2);
    }

    int minimumDistance(string word) {
        vector<vector<char>> wds;
        wds.push_back({'A', 'B', 'C', 'D', 'E', 'F'});
        wds.push_back({'G', 'H', 'I', 'J', 'K', 'L'});
        wds.push_back({'M', 'N', 'O', 'P', 'Q', 'R'});
        wds.push_back({'S', 'T', 'U', 'V', 'W', 'X'});
        wds.push_back({'Y', 'Z', ' ', ' ', ' ', ' '});
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < wds.size(); i++) {
            for (int j = 0; j < wds[0].size(); j++) {
                pos[wds[i][j]-'A'] = {i, j};
            }
        }
        vector<vector<vector<int>>> dp(word.size(), vector<vector<int>>(27, vector<int>(27,-1)));
        int ans = solve(word, pos, -1, -1, 0,dp);
        return ans;
    }
};