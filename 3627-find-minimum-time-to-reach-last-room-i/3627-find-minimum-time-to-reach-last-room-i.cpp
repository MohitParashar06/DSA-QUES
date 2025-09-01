class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};  

        int ans = 1e9;
        vector<vector<int>> vis(mt.size(), vector<int>(mt[0].size(),INT_MAX));
        while(!pq.empty()){
            auto top = pq.top();pq.pop();
            int t = top.first;
            int x = top.second.first;
            int y = top.second.second;
            if(t >= vis[x][y]) continue;
            if(x == mt.size()-1 && y == mt[0].size()-1){
                return t;
            }
            vis[x][y]=t;
            for(int k = 0; k < 4; k++){
                int nr = dr[k] + x;
                int nc = dc[k] + y;
                if(nr>=0&&nr<mt.size()&&nc>=0&&nc<mt[0].size()&&vis[nr][nc]==INT_MAX){
                    pq.push({max(t,mt[nr][nc])+1,{nr,nc}});
                }
            }
        }
        return -1;
    }
};