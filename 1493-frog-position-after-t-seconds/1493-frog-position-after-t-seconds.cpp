class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
       unordered_map<int,vector<int>> adj;
       for(auto it : edges){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       queue<pair<int,pair<int,double>>> q;
       q.push({1,{0,1.0}});
       unordered_map<int,bool> vis;
       while(!q.empty()){
        auto front = q.front();
        q.pop();
        int node = front.first;
        vis[node]=1;
        int time = front.second.first;
        if(time > t){
            if(!q.empty()) continue;
            return 0;
        }
        double val = front.second.second;
        if(node == target && time == t) return val;
        int v = 0;
        int fg = 0;
        for(auto it : adj[node]){
            if(!vis[it]){
                v++;
                fg=1;
            }
        }
        for(auto it : adj[node]){
            if(!vis[it])
            q.push({it, {time+1,val*(1.0/v)}});
        }
        if(!fg){
            q.push({node,{time+1,val}});
        }
       }
       return 0;
    }
};