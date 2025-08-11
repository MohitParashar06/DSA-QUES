class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        bitset<31> bs(n);
        vector<long long> power;
        for(int i = 30; i >= 0; i--){
            if(bs[i] == 1){
                power.push_back(pow(2,i));
            }
        }
        int mod = 1e9+7;
        reverse(power.begin(), power.end());
        vector<int> ans;
        for(auto q : queries){
            long long pr = power[q[0]];
            for(int i = q[0]+1; i <= q[1]; i++){
                pr = (pr%mod*power[i])%mod;
            }
            ans.push_back(pr);
        }
        return ans;
    }
};