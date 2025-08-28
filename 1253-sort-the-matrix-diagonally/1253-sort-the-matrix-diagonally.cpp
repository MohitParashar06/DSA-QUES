class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& grid) {
        vector<vector<int>> res= grid;
        for(int i = 0; i < grid.size(); i++){
            vector<int> temp;
            int l = i, k = 0;
            while(l < grid.size() && k < grid[0].size()){
                temp.push_back(grid[l][k]);
                l++;k++;
            }
            sort(temp.begin(), temp.end());
            l=i;k=0;int j=0;
            while(l < grid.size() && k < grid[0].size()){
                res[l][k] = temp[j++];
                l++;k++;
            }
        }
        for(int i = 1; i < grid[0].size(); i++){
            vector<int> temp;
            int l = 0, k = i;
            while(l < grid.size() && k < grid[0].size()){
                temp.push_back(grid[l][k]);
                l++;k++;
            }
            sort(temp.begin(), temp.end());
            l=0;k=i;int j=0;
            while(l < grid.size() && k < grid[0].size()){
                res[l][k] = temp[j++];
                l++;k++;
            }
        }
        
        return res;
    }
};