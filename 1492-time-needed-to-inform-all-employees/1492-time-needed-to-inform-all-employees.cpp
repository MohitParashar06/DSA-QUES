class Solution {
public:
    int f(vector<int>& manager, int node, vector<int>& it){
        if(manager[node] == -1)
            return it[node];
        return it[node]+f(manager,manager[node],it);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int cnt = 0;
        for(int i = 0; i < informTime.size(); i++){
            if(informTime[i] == 0){
                cnt = max(cnt,f(manager,i, informTime));
            }
        }
        return cnt;
    }
};