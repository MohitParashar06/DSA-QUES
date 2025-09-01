class Solution {
public:
    vector<int> par;
    void disjointset(int n) {
        par.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }
    int findpar(int u) {
        if (par[u] == u)
            return u;
        return par[u] = findpar(par[u]);
    }

    void merge(int u, int v) {
        int ua = findpar(u);
        int ub = findpar(v);
        par[ua] = ub;
    }

    static bool cmp(vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    }

    int findwt(vector<vector<int>>& edges, int n, int inc, int e){
        disjointset(n+1);
        int wt = 0;
        if(e != -1){
            wt += edges[e][2];
            merge(edges[e][0], edges[e][1]);
        }

        for(int i = 0; i < edges.size(); i++){
            if(i == inc) continue;
            if(findpar(edges[i][0]) == findpar(edges[i][1])) continue;
            merge(edges[i][0],edges[i][1]);
            wt += edges[i][2];
        }
        for(int i = 0 ;i < n; i++){
            if(findpar(i) != findpar(0)) return INT_MAX;
        }
        return wt;
    }

    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        disjointset(n+1);
        for(int i = 0; i < edges.size(); i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), cmp);

        int mstwt = findwt(edges,n,-1,-1);

        vector<int> ct,ps;
        for(int i = 0; i < edges.size(); i++){
            if(mstwt < findwt(edges,n,i,-1)){
                ct.push_back(edges[i][3]);
            }else if(mstwt == findwt(edges,n,-1,i)){
                ps.push_back(edges[i][3]);
            }
        }
        return {ct,ps};
    }
};