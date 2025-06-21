class Solution {
  public:
    
    void f(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid){
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
            return;
        if(vis[i][j] || grid[i][j] == 'W') return;
        vis[i][j]=1;
        int drow[] = {-1,-1,-1,0,0,1,1,1};
        int dcol[] = {-1,0,1,-1,1,-1,0,1};
        for(int k = 0; k < 8; k++){
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            if(nrow < grid.size() && ncol < grid[0].size()
            && nrow >= 0 && ncol >= 0 && grid[nrow][ncol] == 'L'){
                f(nrow,ncol,vis,grid);
            }
        }
        return;
    }
  
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 'L'){
                    // cout << i << " " << j << endl;
                    ans++;
                    f(i,j,vis,grid);
                }
            }
        }
        return ans;
    }
};