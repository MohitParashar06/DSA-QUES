class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int gs) {
        unordered_map<int,int> count;
        for(int i : hand){
            count[i]++;
        }
        sort(hand.begin(),hand.end());
        int ans = 0;
        int varCount = 0;
        for(int i = 0; i < hand.size(); i++){
            if(count[hand[i]] <= 0) continue;
            int cnt = 1;
            int x = hand[i];
            count[x]--;
            while(count[x+1] > 0 && cnt < gs){
                // cout << x << " ";
                cnt++;
                count[x+1]--;
                x++;
            }
            // cout << x << " ";
            // cout << endl;
            if(cnt == gs) ans++;
            else return false;
        }
        return true;
    }
};