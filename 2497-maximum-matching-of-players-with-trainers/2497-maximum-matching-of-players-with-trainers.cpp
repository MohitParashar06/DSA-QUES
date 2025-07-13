class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(), p.end());
        sort(t.begin(),t.end());
        int cnt = 0;
        int i = 0;
        for(int j = 0; j < t.size(); j++){
            if(i == p.size()) break;
            if(p[i] > t[j]) continue;
            cnt++;i++;
        }
        return cnt;
    }
};