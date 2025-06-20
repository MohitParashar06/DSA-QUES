class Solution {
  public:
    
    bool f(int node, unordered_map<int,vector<int>> &adj,
            unordered_map<int,int>& par, unordered_map<int,bool> &vis){
                vis[node]=true;
                for(auto it : adj[node]){
                    if(vis[it] == true && par[node] == it) continue;
                    if(vis[it] == true && par[node] != it) return true;
                    if(!vis[it]){
                        par[it]=node;
                        if(f(it,adj,par,vis)) return true;
                    }
                }
                return false;
            }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> par;
        unordered_map<int,bool> vis;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 0; i < V; i++){
            if(vis[i]) continue;
            par[i]=-1;
            bool ans = f(i,adj,par,vis);
            if(ans) return true;
        }
        return false;
    }
};