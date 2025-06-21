class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(V,0);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
    
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i : adj[node]){
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        
        if(ans.size() == V) return ans;
        return {};
    }
};