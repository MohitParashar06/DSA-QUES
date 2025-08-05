class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        unordered_map<int,bool> vis;
        int cnt = 0;
        for(int i = 0; i < fruits.size(); i++){
            for(int j = 0; j < fruits.size(); j++){
                if(vis[j]) continue;
                if(baskets[j] >= fruits[i]){
                    vis[j]=1;
                    cnt++;
                    break;
                }
            }
        }
        return fruits.size()-cnt;
    }
};