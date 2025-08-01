class Solution {
public:

    void solve(int n, vector<vector<int> >& ans, int count){
        if(count >= n){
            return;
        }
        vector<int> output;
        output.push_back(1);
        int i = count - 1;
        int j = 0;
        while(j+1 < ans[i].size()){
            output.push_back(ans[i][j] + ans[i][j+1]);
            j++;
        }

        output.push_back(1);
        ans.push_back(output);
        solve(n,ans,count+1);
    }

    vector<vector<int>> generate(int n) {

        if(n == 1){
            return {{1}};
        }
        if(n == 2){
            return {{1},{1,1}};
        }

        vector<vector<int>> ans;

        vector<int> ot;
        ot.push_back(1);

        ans.push_back(ot);
        ot.push_back(1);
        ans.push_back(ot);

        solve(n,ans, 2);

        return ans;
    }
};