class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m1;

   for(int i : nums){
        m1[i]++;
   }
   priority_queue<pair<int,int>> pq;
    for(auto x : m1){
        pq.push({x.second,x.first});
    }
    vector<int> res;
    while(!pq.empty() && k--){
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
    }
};