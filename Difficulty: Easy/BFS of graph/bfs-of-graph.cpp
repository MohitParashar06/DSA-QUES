class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        queue<int> q;
        q.push(0);
        unordered_map<int,bool> vis;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node]=1;
            ans.push_back(node);
            for(int it : adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};