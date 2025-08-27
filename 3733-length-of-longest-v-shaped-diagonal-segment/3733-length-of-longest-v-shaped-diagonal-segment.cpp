class Solution {
public:

    int f(int i, int j, int dr, int cnt,vector<vector<int>>& grid, vector<vector<int>>& vis, vector<vector<vector<vector<int>>>> &dp){
        if(vis[i][j] == 1) return 0;
        if(cnt > 2) return 0;
        if(dp[i][j][dr-1][cnt-1] != -1) return dp[i][j][dr-1][cnt-1];
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        int ans = 1;
        // cout << i << " " << j << " " << dr << " " << cnt<<endl;
        if(grid[i][j] == 2){
            if(dr == 1){
                if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 0){
                    ans = max(ans,f(i-1,j-1,dr,cnt,grid,vis,dp)+1);
                }
                if(i-1 >= 0 && j+1 < m && grid[i-1][j+1] == 0){
                    ans = max(ans,f(i-1,j+1,2,cnt+1,grid,vis,dp)+1);
                }
            }
            if(dr == 2){
                if(i-1 >= 0 && j+1 < m && grid[i-1][j+1] == 0){
                    ans = max(ans,f(i-1,j+1,dr,cnt,grid,vis,dp)+1);
                }
                if(i+1 < n && j+1 < m && grid[i+1][j+1] == 0){
                    ans = max(ans,f(i+1,j+1, 4,cnt+1,grid,vis,dp)+1);
                }
            }
            if(dr == 4){
                if(i+1 < n && j+1 < m && grid[i+1][j+1] == 0){
                    ans = max(ans,f(i+1,j+1,dr,cnt,grid,vis,dp)+1);
                }
                if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 0){
                    ans = max(ans,f(i+1,j-1,3,cnt+1,grid,vis,dp)+1);
                }
            }
            if(dr == 3){
                if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 0){
                    ans = max(ans,f(i+1,j-1,dr,cnt,grid,vis,dp)+1);
                }
                if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 0){
                    ans = max(ans, f(i-1,j-1,1,cnt+1,grid,vis,dp)+1);
                }
            }
        }else{
            if(dr == 1){
                if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 2){
                    ans = max(ans,f(i-1,j-1,dr,cnt,grid,vis,dp)+1);
                }
                if(i-1 >= 0 && j+1 < m && grid[i-1][j+1] == 2){
                    ans = max(ans,f(i-1,j+1,2,cnt+1,grid,vis,dp)+1);
                }
            }
            if(dr == 2){
                if(i-1 >= 0 && j+1 < m && grid[i-1][j+1] == 2){
                    ans = max(ans,f(i-1,j+1,dr,cnt,grid,vis,dp)+1);
                }
                if(i+1 < n && j+1 < m && grid[i+1][j+1] == 2){
                    ans = max(ans,f(i+1,j+1, 4,cnt+1,grid,vis,dp)+1);
                }
            }
            if(dr == 4){
                if(i+1 < n && j+1 < m && grid[i+1][j+1] == 2){
                    ans = max(ans,f(i+1,j+1,dr,cnt,grid,vis,dp)+1);
                }
                if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 2){
                    ans = max(ans,f(i+1,j-1,3,cnt+1,grid,vis,dp)+1);
                }
            }
            if(dr == 3){
                if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 2){
                    ans = max(ans,f(i+1,j-1,dr,cnt,grid,vis,dp)+1);
                }
                if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 2){
                    ans = max(ans, f(i-1,j-1,1,cnt+1,grid,vis,dp)+1);
                }
            }
        }
        vis[i][j]=0;
        return dp[i][j][dr-1][cnt-1] = ans;
    }

    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis,
    vector<vector<vector<vector<int>>>> &dp){
        int ans = 1;
        int n = grid.size();
        int m = grid[0].size();
        // cout << i << " " << j << endl;
        if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == 2)
            ans = max(ans,f(i-1,j-1,1,1,grid,vis,dp)+1);
        if(i-1 >= 0 && j+1 < m && grid[i-1][j+1] == 2)
            ans = max(ans,f(i-1,j+1,2,1,grid,vis,dp)+1);
        if(i+1 < n && j-1 >= 0 && grid[i+1][j-1] == 2)
            ans = max(ans,f(i+1,j-1,3,1,grid,vis,dp)+1);
        if(i+1 < n && j+1 < m && grid[i+1][j+1] == 2)
            ans = max(ans,f(i+1,j+1,4,1,grid,vis,dp)+1);
            // cout << i << " " << j << " " << ans << endl;
        return ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(2,-1))));
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(grid[i][j] == 1){
                    ans = max(ans,solve(i,j,grid,vis,dp));
                    // cout << i << " " << j << " " << ans << endl;
                }
            }
        }
        return ans;
    }
};