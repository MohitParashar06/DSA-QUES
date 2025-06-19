class Solution {
public:

    int findPar(int node, vector<int>& parent){
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node],parent);
    }

    void unionRank(int u, int v, vector<int>& rank, vector<int>& parent){
        int ulp_u = findPar(u,parent);
        int ulp_v = findPar(v,parent);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> rank(n+1,0),parent(n+1,0);
        for(int i = 0; i <= n; i++)
            parent[i]=i;
        vector<int> ans;
        for(auto &ed : edges){
            int u = ed[0];
            int v = ed[1];
            if(findPar(u,parent) == findPar(v,parent))
                ans = ed;
            unionRank(u,v,rank,parent);
        }
        return ans;
    }
};