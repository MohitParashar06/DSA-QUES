// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>dis(V,1e9);
        dis[src]=0;
        queue<pair<int,int>> q;
        q.push({src,0});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int node = front.first;
            int dist = front.second;
            for(auto it : adj[node]){
                if(it.second + dist < dis[it.first]){
                    dis[it.first] = it.second+dist;
                    q.push({it.first,dis[it.first]});
                }
            }
        }
        return dis;
    }
};