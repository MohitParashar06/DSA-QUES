class Solution {
public:
int min(int a, int b){
    if(a <= b) return a;
    return b;
}
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        
        vector<int> pre(startPos+k+1,0);
        unordered_map<int,int> fr;
        for(auto it : fruits){
            fr[it[0]] = it[1];
        }
        if(fr.find(0) != fr.end()){
            pre[0]=fr[0];
        }
        for(int i = 1; i < pre.size(); i++){
            if(fr.find(i) != fr.end()){
                pre[i] = pre[i-1]+fr[i];
            }else{
                pre[i]=pre[i-1];
            }
        }
        // for(auto it : pre){
        //     cout << it << " ";
        // }cout << endl;
        int x = ceil(k/2.0)-1;
        // cout << x << endl;
        int ans = 0;
        if(x < 0){
            if(fr.find(startPos) != fr.end()){
                return fr[startPos];
            }
            return 0;
        }
        for(int i = 0; i <= x; i++){
            int st = startPos-i;
            int en = st + (k-i);
            st = max(st,0);
            en = min(en,pre.size()-1);
            if(st == en){
                ans = max(ans,pre[st]);continue;
            }
            if(st != 0)
                ans = max(ans,pre[en]-pre[st-1]);
            else
                ans = max(ans,pre[en]);
            // cout << st << " " << en << " " << ans << endl;
        }
        for(int i = 0; i <= x; i++){
            int en = startPos+i;
            int st = en - (k-i);
            st = max(st,0);
            en = min(en,pre.size()-1);
            if(st == en){
                ans = max(ans,pre[st]);continue;
            }
            if(st != 0)
                ans = max(ans,pre[en]-pre[st-1]);
            else
                ans = max(ans,pre[en]);
            // cout << st << " " << en << " " << ans << endl;
        }
        return ans;
    }
};