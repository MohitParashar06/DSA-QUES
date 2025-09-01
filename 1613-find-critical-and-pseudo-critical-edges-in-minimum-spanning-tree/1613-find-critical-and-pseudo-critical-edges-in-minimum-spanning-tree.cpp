class Solution {
public:

    vector<int> par;

    void disjoint(int n){
        par.resize(n+1);
        for(int i = 0; i <= n; i++){
            par[i]=i;
        }
    }

    int findpar(int u){
        if(par[u] == u) return u;
        return par[u] = findpar(par[u]);
    }

    void merge(int u, int v){
        int ua = findpar(u);
        int ub = findpar(v);
        par[ua] = ub;
    }

    int findwt(int& n, vector<vector<int>>& eg, int inc, int e){
        disjoint(n+1);
        int wt = 0;
        if(e != -1){
            wt += eg[e][2];
            merge(eg[e][0], eg[e][1]);
        }

        for(int i = 0; i < eg.size(); i++){
            if(i == inc) continue;
            if(findpar(eg[i][0]) == findpar(eg[i][1])) continue;
            merge(eg[i][0], eg[i][1]);
            wt += eg[i][2];
        }

        for(int i = 0; i < n; i++)
            if(findpar(i) != findpar(0)) return INT_MAX;
        return wt;
    }

    static bool cmp(vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> ct,ps;
        for(int i = 0; i < edges.size(); i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(),cmp);
        int mstwt = findwt(n,edges,-1,-1);

        for(int i = 0; i < edges.size(); i++){
            if(mstwt < findwt(n,edges,i,-1)){
                ct.push_back(edges[i][3]);
            }
            else if(mstwt == findwt(n,edges,-1,i)){
                ps.push_back(edges[i][3]);
            }
        }
        return {ct,ps};
    }
};