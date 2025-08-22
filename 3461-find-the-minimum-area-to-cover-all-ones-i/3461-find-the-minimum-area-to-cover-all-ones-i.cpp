class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int l1 = 1e9, m1 = 1e9, l2 = -1e9, m2 = -1e9;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    l1 = min(l1,i);
                    l2 = max(l2,i);
                    m1 = min(m1,j);
                    m2 = max(m2,j);
                }
            }
        }
        return (l2-l1+1)*(m2-m1+1);
    }
};